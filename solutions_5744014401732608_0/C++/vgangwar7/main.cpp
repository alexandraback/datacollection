#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <assert.h>
#include <deque>
#include <ctime>

#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define S(n)	    scanf("%d",&n)
#define P(n)	    printf("%d\n",n)
#define Sl(n)	    scanf("%lld",&n)
#define Pl(n)	    printf("%lld\n",n)
#define Sf(n)       scanf("%lf",&n)
#define Ss(n)       scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;
int n;
LL m;
LL A[100];
int adj[100][100];

int main()
{
    int T,tc(1);
    S(T);
    while(T--){
        S(n); Sl(m);
        memset(adj,0,sizeof adj);
        A[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            A[i] = 0;
            for(int j=i+1;j<n;j++){
                if(m>=A[i] + A[j]){
                    A[i] += A[j];
                    adj[i][j] = 1;
                }
            }
        }
        printf("Case #%d: ",tc++);
        if(A[0] == m){
            printf("POSSIBLE\n");
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    printf("%d",adj[i][j]);
                }
                printf("\n");
            }
        }else printf("IMPOSSIBLE\n");
    }
    return 0;
}