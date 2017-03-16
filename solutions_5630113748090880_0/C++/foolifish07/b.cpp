#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

using namespace std;
const int maxn = 1300;
const int inf = 1e9+7;

int n;
int cnt[3000];

int main(){

    int t; scanf("%d", &t);
    for(int it=1;it<=t;it++){
        scanf("%d", &n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n+n-1;i++){
            for(int j=1;j<=n;j++){
                int v; scanf("%d", &v);
                cnt[v]++;
            }
        }

        vector<int> tmp; tmp.clear();
        for(int i=1;i<=2500;i++)
            if ( cnt[i]&1 ){
                tmp.push_back( i );
            }
        sort( tmp.begin(), tmp.end() );
        printf("Case #%d:", it);
        for(int i=0;i<tmp.size();i++)
            printf(" %d", tmp[i]);
        printf("\n");
    }

    return 0;
}

