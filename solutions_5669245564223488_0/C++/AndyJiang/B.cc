#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set> 
#include<cstdlib>
#include<cmath>
#include<string> 
#include<sstream>
#include<queue>
#include<stack>
#include<list>

using namespace std; 

bool valid(vector<string> & vs){
    int idx = 0; 
    vector<int> occur(26,-1); 
    string line ; 
    for(int i = 0; i < vs.size(); i++){
        line += vs[i]; 
        //cout << vs[i] << " " ; 
    }
    //cout << endl; 
    while(idx < line.size()){
        char c = line[idx]; 
        if(occur[c-'a'] != -1)
            return false;
        else 
            occur[c-'a'] = idx; 
        while(idx < line.size() && line[idx] == c)
            ++idx;
    }
    return true;
}

bool same(string s1, string s2){
    set<char> ss(s1.begin(),s1.end()); 
    set<char> sss(s2.begin(),s2.end()); 
    if(ss.size() == 1 && sss.size() == 1 && *ss.begin() == *sss.begin())
        return true; 
    return false;
}

long long work(vector<string> & v, int low ,int high){

    //cout << low << "-->" << high << endl;
    vector<string> vs ; 
    for(int i = low; i <= high; i ++){
        vs.push_back(v[i]); 
        //cout << v[i] << " " ; 
    }
    //cout << endl;
    sort(vs.begin(),vs.end()); 
    long long re = 1; 
    int idx = 0; 
    while(idx < vs.size()){
        int len = 1; 
        while(idx+1 < vs.size()){ 
            if(same(vs[idx],vs[idx+1])){
                ++len;
                ++idx;
            }else{
                break;
            }
        }
        ++idx;
        long long temp = 1; 
        for(int i = len; i >= 1; i--)
            temp *= i; 
        re *= temp;  
        re = re%1000000007;
    }
    //cout << re << endl;
    return re;
}

int main(){
    int T; 
    cin >> T; 
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": "; 
        int n; 
        cin >> n; 
        vector<string> vs; 
        string str; 
        for(int i = 0; i < n; i ++){
            cin >> str ; 
            vs.push_back(str); 
        }
        sort(vs.begin(),vs.end()); 
        if(valid(vs) == false){
            cout << 0 << endl; 
            continue;
        }
        long long re = 0;
        vector<long long> vll; 
        int low = -1; 
        int high = -1; 
        int idx = 0; 
        while(idx < n){
            //cout << "idx " << idx << endl; 
            if(low == -1){
                low = idx; 
                high = idx; 
            }
            if(high+1 < n){
                string s1 = vs[high]; 
                string s2 = vs[high+1];
                if(s1[s1.size()-1] == s2[0]){
                    ++idx; 
                    ++high;
                }else{
                    long long temp = work(vs,low,high); 
                    vll.push_back(temp);
                    low = high = -1;
                    ++idx;
                }
            }else{
                    long long temp = work(vs,low,high); 
                    vll.push_back(temp);
                    low = high = -1;
                    ++idx;
            }
        }
        re = 1; 
        for(int i = 0; i < vll.size(); i++){
            re = re * vll[i] % 1000000007;
            //cout << "vll " << i << " " << vll[i] << endl; 
        }
        int size = vll.size(); 
        while(size > 1){
            re = re * size % 1000000007; 
            size--;
        }

        cout << re % 1000000007 << endl;
    }
}
