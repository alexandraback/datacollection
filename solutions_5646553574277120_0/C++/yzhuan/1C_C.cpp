#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[]) {
    // freopen("1c_c.large.in", "r", stdin);
    // freopen("1c_c.large.out", "w", stdout);
    freopen("1c_c.small.in", "r", stdin);
    freopen("1c_c.small.out", "w", stdout);
    
    int T;
    int C,D,V;
    int coins[10];
    bool flag[1000];
    while(scanf("%d",&T)!=EOF) {
        for(int k=1; k<=T; k++) {
            scanf("%d%d%d",&C,&D,&V);
            for(int i=1; i<=D; i++) scanf("%d",&coins[i]);
            memset(flag,false,sizeof(flag));
            for(int i=1; i<=D; i++) flag[coins[i]] = true;
            for(int i=1; i<=D; i++) {
                for(int j=1; j<=D; j++) {
                    if(i!=j) flag[coins[i]+coins[j]] = true;
                }
            }
            int cnt = 0;
            while(true) {
                int tmp = true;
                for(int i=1; i<=V; i++) {
                    if(flag[i] == false) {
                        tmp = false;
                        flag[i] = true;
                        cnt ++;
                        for(int j=1; j<=D; j++) {
                            flag[i+coins[j]] = true;
                        }
                    }
                }
                if(tmp) break;
            }
            printf("Case #%d: %d\n",k,cnt);
        }
    }
    return 0;
}
