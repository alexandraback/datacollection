#include<stdio.h>
#include<map>
#include<queue>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int n;
int a[1000],b[1000];
map<int,vector<int> > M;

int main(){
    int ca; scanf("%d",&ca);
    FOE(tt,1,ca){
        M.clear();
        scanf("%d",&n);
        FOR(i,0,n) scanf("%d",&a[i]);
        printf("Case #%d:\n",tt);
        bool ans=false;
        FOR(t,0,1<<n){
            vector<int> x;
            int s=0;
            FOR(i,0,n){
                if (t&(1<<i)) x.PB(a[i]), s += a[i];
            }
            if (M.count(s) == 0){
                M[s] = x;
            }else{
                vector<int> y = M[s];
                ans = true;
                bool fi=true;
                FOR(i,0,x.size()){
                    bool ok=true;
                    FOR(j,0,y.size()) if (x[i]==y[j]) ok=false;
                    if (ok) printf("%d ",x[i]);
                }
                puts("");
                FOR(i,0,y.size()){
                    bool ok=true;
                    FOR(j,0,x.size()) if (y[i]==x[j]) ok=false;
                    if (ok) printf("%d ",y[i]);
                }
                puts("");
                break;
            }
        }
        if (!ans) printf("Impossible\n");
    }
    return 0;
}
