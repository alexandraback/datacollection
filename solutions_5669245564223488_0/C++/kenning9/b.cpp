#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, TC, eg[300], sg[300], fac[11];
string srt[101], s[101];
bool st[28], e[28];
int main(){
    cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        memset(eg, 0, sizeof(eg));
        memset(sg, 0, sizeof(sg));
        cin >> n;
        for(int i = 0; i < n; fac[i] = i++){
            cin >> srt[i];
            s[i] = "";
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < srt[i].size(); ++j){
                if(j > 0 && srt[i][j] == srt[i][j-1]) continue;
                s[i] += srt[i][j];
            }
            //cout << s[i] << endl;
        }
        int ans = 0;
        do{
            for(int j = 0; j < 26; ++j) st[j] = e[j] = 0;
            char prev = 0;
            for(int i = 0; i < n; ++i){
                for(int k = 0; k < s[fac[i]].size(); ++k){
                    int j = s[fac[i]][k] - 'a';
                    if(prev != 0 && s[fac[i]][k] != prev) e[prev -'a'] = true;
                    if(e[j]) goto gg;
                    if(!st[j]) st[j] = true;
                    prev = s[fac[i]][k];
                }
            }
            ++ ans;
            gg:
                continue;
        }
        while(next_permutation(fac, fac+n));
        printf("Case #%d: %d\n", tc, ans);
    }
}
                
        
        
