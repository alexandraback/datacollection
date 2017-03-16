#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
#include <stack>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <queue>
using namespace std;

typedef long long int ll;
vector<string> car;
bool used[102] = {};
bool pre[26] = {};
int ncar;
int ans;

void dfs(int state, string all){
    if(state == ncar){
        //cout << "all:  ";
        //cout << all << endl;

        bool isused[28] = {};
        while(!all.empty()){
            //cout << all << endl;
            if(isused[all[0] - 'a'] == false ){
                isused[all[0] - 'a'] = true;
                char c = all[0];
                while(!all.empty()){
                    if(all[0] == c){
                        all.erase(all.begin());
                    }else break;
                }
            }else break;
        }
        if(all.empty()){
            ans++;
        }
        return;
    }
    for(int i=0; i<ncar; i++){
        if(!used[i]){
            used[i] = true;
            bool ignore = false;
            bool back_pre[28] = {};
            for(int k=0; k<28; k++){
                back_pre[k] = pre[k];
            }
            for(unsigned k=0; k<car[i].size(); k++){
                if(pre[car[i][k] - 'a'] == true && car[i][k] != all[all.length()-1]){
                    ignore = true;
                    break;
                }else {
                    char c = car[i][k];
                    pre[c - 'a'] = true;
                    while(car[i][k] == c && k < car[i].size()){
                        k++;
                    }
                    k--;
                }
            }
            if(ignore == false){
                dfs(state + 1, all + car[i]);
            }
            for(int k=0; k<28; k++){
                pre[k] = back_pre[k];
            }

            used[i] = false;
        }
    }
    return;
}

int main (int argc, char * const argv[]){
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        freopen("B11.in", "r", stdin);
        freopen("B1.out", "w", stdout);
    #endif // LOCAL


    int ntest;
    while(cin>>ntest){
        for(int tt=0; tt<ntest; tt++){

            cin >> ncar;
            car.clear();
            for(int i=0; i<ncar; i++){
                string tmp;
                cin >> tmp;
                car.push_back(tmp);
            }
            ans = 0;
            memset(pre, 0, sizeof(pre));
            memset(used, 0, sizeof(used));
            dfs(0, "");

            printf("Case #%d: %d\n", tt+1, ans);

        }

    }





    return 0;
}
