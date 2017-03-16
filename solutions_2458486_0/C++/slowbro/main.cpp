#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdexcept>
using namespace std;

struct Chest{
    int type;
    vector<int> keys;
};

void stash_key(map<int, int> &keys, int val){
    //increments the bucket of the type of key by 1
    auto iter = keys.find(val);
    if(iter==keys.end())
        keys[val] = 1;
    else
        keys[val]++;
}

int recur(set<int> &visited_list, map<int, int> &key_list, vector<Chest> &chestList, map<set<int>, int> *vf, int N){
    if(vf->find(visited_list) != vf->end())
        return (*vf)[visited_list];
    else if(visited_list.size() == (size_t) N){
        //Base case -- all states visited
        (*vf)[visited_list] = 1;
        return 1;
    }
    
    int max_vf = 0;
    
    set<int> temp_visited_list(visited_list);
    map<int, int> temp_key_list;
    for(int ii=0; ii<N; ii++){
        int cur_vf = 0;
        if(visited_list.find(ii)!=visited_list.end()){
            //we already opened this chest, skip
            continue;
        }
        if(key_list[chestList[ii].type] > 0){
            //key is available
            temp_key_list = key_list;
            temp_key_list[chestList[ii].type]--;
            for(auto it=chestList[ii].keys.begin(); it!=chestList[ii].keys.end(); it++)
                stash_key(temp_key_list, *it);
            temp_visited_list.emplace(ii);
            cur_vf = recur(temp_visited_list, temp_key_list, chestList, vf, N);
            temp_visited_list.erase(ii);
            
            if(cur_vf == 1){
                max_vf = 1;
                break;
            }
        }
    }
    (*vf)[visited_list] = max_vf;
    return max_vf;
}

string retrieve_path(map<set<int>, int> *vf, int N){
    int num_chests = 0;
    set<int> not_visited;
    for(int ii=0; ii < N; ii++){
        not_visited.emplace(ii);
    }
    set<int> visited;
    bool flag;
    int cur_chest;
    stringstream path;
    while(num_chests < N){
        flag = false;
        cur_chest=-1;
        for(auto it=not_visited.begin(); it!=not_visited.end(); it++){
            cur_chest = *it;
            visited.emplace(*it);
            if(vf->find(visited)!=vf->end() && (*vf)[visited]==1){
                flag = true;
            }
            visited.erase(*it);
            if(flag)
                break;
        }
        if(flag){
            num_chests++;
            visited.emplace(cur_chest);
            not_visited.erase(cur_chest);
            path << cur_chest+1 << " ";
        }
        else
            throw runtime_error("cannot retrieve path for some reason");
    }
    return path.str();
}

string solve(int K, int N, map<int, int> &startKeys, vector<Chest> &chestList){
    map<set<int>, int> vf;
    set<int> empty_visited_list;
    int max_vf = recur(empty_visited_list, startKeys, chestList, &vf, N);
    
    if(max_vf>0){
        return retrieve_path(&vf, N);
    }
    else
        return "IMPOSSIBLE";
}

int main(int argc, const char * argv[])
{
    fstream fh;
    if(argc > 1)
        fh.open(argv[1]);
    else{
        cout << "using test file" << endl;
        fh.open("/Users/syeung/c++/treasure/treasure/D-small-attempt0.in");
    }
    int T;
    string output;
    int K, N; //K is the number of keys you start with, N is number of chests to open
    map<int, int> startKeys;
    vector<Chest> chestList;
    Chest tmpChest;
    int Ti, Ki;
    
    fh >> T;
    for(int ii=0; ii<T; ii++){
        startKeys.clear();
        chestList.clear();
        
        fh >> K;
        fh >> N;
        for(int ki=0; ki<K; ki++){
            int tmp;
            fh >> tmp;
            //startKeys.push_back(tmp);
            stash_key(startKeys, tmp);
        }
        for(int ni=0; ni<N; ni++){
            fh >> Ti;
            tmpChest.type = Ti;
            fh >> Ki;
            tmpChest.keys.clear();
            for(int kii=0; kii<Ki; kii++){
                int tmp;
                fh >> tmp;
                tmpChest.keys.push_back(tmp);
            }
            chestList.push_back(tmpChest);
        }
        output = solve(K, N, startKeys, chestList);
        cout << "Case #" << ii+1 << ": " << output << endl;
    }
    return 0;
}

