
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

int main() {
    int Test, N, J, P, S, K, cnt;
    cin >> Test;
    for (int t = 1; t <= Test; ++t) {
        cout << "Case #" << t << ": ";
        cin >> J >> P >> S >> K;
        cout << J*P*min(S, K) << "\n";
        for (int j=0; j<J; j++) {
            for (int p=0; p<P; p++) {
                for (cnt = 0; cnt < min(K, S); cnt++) {
                    cout << j+1 << " " << p+1 << " " << cnt+1 << "\n";
                }
            }
        } 
    }
    return 0;
}