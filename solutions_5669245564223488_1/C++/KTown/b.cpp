#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

char buff[102];

vector<vector<char> > trains;
void printTrains(){
    for(int i=0;i<trains.size();i++){
        for(int j=0;j<trains[i].size();j++)
            cerr << trains[i][j];
        cerr << " ";
    }
    cerr << endl;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0;t++<T;){
        trains.clear();
        int Tr;
        scanf("%d", &Tr);
        trains.resize(Tr);
        //cerr << Tr << endl;
        for(int i=0;i<Tr;i++){
            scanf("%s", buff);
            //cerr << buff << endl;
            //cerr << strlen(buff) << endl;
            for(int j=0;j<strlen(buff);j++){
                trains[i].push_back(buff[j]);
            }
        }
        for(int i=0;i<Tr;i++){
            int j=0;
            while(j<trains[i].size()-1){
                if(trains[i][j] == trains[i][j+1])
                    trains[i].erase(trains[i].begin()+j);
                else
                    j++;
            }
        }        
        //printTrains();
        int next=0;
        map<char, int> many;
        for(int i=0;i<Tr;i++){
            for(int j=0;j<trains[i].size();j++){
                if(j==0||j==(trains[i].size()-1)){
                    if(many[trains[i][j]] == 2)
                        next=1;
                    many[trains[i][j]] = 1;
                }else{
                    if(many[trains[i][j]] != 0)
                        next=1;
                    many[trains[i][j]] = 2;
                }
            }
        }
        if(next){
            printf("Case #%d: 0\n", t);
            continue;
        }
        map<char, int> startsWith;
        map<char, int> endsWith;
        many.clear();
        for(int i=0;i<Tr;i++){
            many[trains[i][0]]=1;
            if(trains[i].size() == 1)
                continue;
            trains[i].erase(trains[i].begin()+1, trains[i].end()-1);
            many[trains[i][1]]=1;
            if(startsWith[trains[i][0]])
                next=1;
            startsWith[trains[i][0]] = 1;
            if(endsWith[trains[i][1]])
                next=1;
            endsWith[trains[i][1]] = 1;
        }
        if(next){
            printf("Case #%d: 0\n", t);
            continue;
        }
        
        map<char, char> links;
        for(int i=0;i<Tr;i++){
            if(trains[i].size()==2)
                links[trains[i][0]] = trains[i][1];
        }
        for(auto it = links.begin(); it != links.end(); it++){
            char l = it->first;
            int i=0;
            while(links.count(l)){
                if(i > 100){
                    next=1;
                    break;
                }
                l = links[l];
                i++;
            }
        }

        if(next){
            printf("Case #%d: 0\n", t);
            continue;
        }
        int pairs=0;
        map<char,int> singles;
        int letterCount=many.size();
        for(int i=0;i<Tr;i++){
            if(trains[i].size()==1){
                singles[trains[i][0]]++;
                //cerr << "here" << endl;
            }
            if(trains[i].size()==2)
                pairs++;
        }
        long long ret = 1;
        long long mod = 1000000007;
        int tmp = letterCount-pairs;
        //cerr << "tmp: " << tmp << endl;
        
        for(int i=1; i<=tmp;i++){
            ret = (ret*i)%mod;
        }
        for(auto it = singles.begin(); it!=singles.end();it++){
            int tmp = it->second;
            //cerr << "tmp: " << tmp << endl;
            for(int i=1;i<=tmp;i++)
                ret=(ret*i)%mod;
        }
        printf("Case #%d: %lld\n", t, ret);
    }
}
