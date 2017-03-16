#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int N;
string str[20][2];
int main(){
    freopen("C.in","r",stdin);
    freopen("Cdata.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        scanf("%d",&N);
        for(int i=0;i<N;i++) {
            cin>>str[i][0]>>str[i][1];
        }
        int ans = 0;
        for(int n=0;n<(1<<N);n++){
            map<string,int>mp,mp1;
            for(int i=0;i<N;i++) {
                if(n&(1<<i)) {
                    mp[str[i][0]] = 1;
                    mp1[str[i][1]] = 1;
                }
            }
            bool jud = true;
            int s=0;
            for(int i=0;i<N;i++) {
                if(n&(1<<i)) continue;
                s++;
                if(mp[str[i][0]] == 0 || mp1[str[i][1]] == 0){
                    jud = false;
                    break;
                }
            }
            if(jud) {
                ans = max(ans,s);
            }
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
