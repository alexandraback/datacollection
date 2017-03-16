#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int INF = 1e9,M=1e3+5;
string A[M],B[M];
bool mark[M];
int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            cin>>A[j]>>B[j];
        }
        int ans=0;
        for(int j=0;j<(1<<n);j++){
            memset(mark,0,sizeof(mark));
            int cnt=0;
            for(int k=0;k<n;k++){
                if((1<<k)&j){
                    mark[k]=1;
                }
            }

            for(int k=0;k<n;k++){
                if(mark[k]) continue;
                int ok1=0,ok2=0;
                for(int i=0;i<n;i++){
                    if(!mark[i]) continue;
                    if(A[k]==A[i]) ok1=1;
                    if(B[k]==B[i]) ok2=1;
                }
                if(ok1&&ok2) cnt++;
            }
            ans=max(ans,cnt);
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
