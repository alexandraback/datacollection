#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
#define PB			push_back
#define ALL(v)			(v).begin() , (v).end()
#define SZ(v)			( (int) v.size() )
#define Set(v,x)		memset(  v , x , sizeof(v))
#define two(n)			( 1 << (n) )
#define contain(S,i)		( (S) & two(i) ) 
#define SQR(v)			( (v) * (v) )
#define ABS(x)			( ( (x) >= 0 ) ? (x) : -(x) )
#define foreach(v,it)		for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
const int MAX = 10010;
int R, E, N;
int dp[MAX][20], v[MAX];

int go(int i, int e) {
    if (i == N)
        return 0;
    int &r = dp[i][e];
    if (r != -1)
        return r;
    r = 0;
    for (int j = 0; j <= e; j++) 
        r = max(r , j * v[i] + go(i+1, min(E, e-j+R)));
    return r;
}
void solve() {
    int i;
    cin >> E >> R >> N;
    for (i = 0 ; i < N ; i++)
        cin >> v[i];
    Set(dp, -1);
    printf("%d\n", go(0, E));
}

int main() {
    int C , nc;

    scanf("%d\n", &C);
    for ( nc = 1 ; nc <= C ; nc++) {
        cout << "Case #" << nc << ": ";
        solve();
    }	
    return 0;
}
