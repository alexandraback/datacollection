#include <cstdio>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

llu brute(int A, int B, int K){
    llu cnt = 0;
    for ( int i = 0 ; i < A ; i++ )
        for ( int j = 0 ; j < B ; j++ ){
            if ( (i & j) < K ) cnt++;
        }

    return cnt;
}

char a[34], b[34];
void convert(char *a, int A){
    for ( int i = 0 ; i < 32 ; i++ ){
        if ( A & (1<<(31-i)) ) a[i] = '1';
        else a[i] = '0';
    }
    
    a[32] = 0;
    //cout << a << endl;
}

llu dp[34][2][2][2];
char vis[34][2][2][2];
int KK;
llu rec(int pos, int lsA, int lsB, int lsK){
    llu res = 0;
    
    if ( pos == 32 ) return 1;
    if ( vis[pos][lsA][lsB][lsK]  ) return dp[pos][lsA][lsB][lsK];
    vis[pos][lsA][lsB][lsK] = 1;
    
    for ( int i = 0 ; i < 2 ; i++ ){
        int nlsa = lsA;
        if ( lsA == 0 && i + '0' < a[pos] ) nlsa = 1;
        if ( lsA == 0 && i + '0' > a[pos] ) continue;
        
        for ( int j = 0 ; j < 2 ; j++ ){
            int nlsb = lsB;
            if ( lsB == 0 && j + '0' < b[pos] ) nlsb = 1;
            if ( lsB == 0 && j + '0' > b[pos] ) continue;
            
            int nlsk = lsK;
            if ( lsK == 0 && ( (i & j) > ((KK & (1<<(31 - pos)))>>(31-pos)) )) continue;
            if ( lsK == 0 && ( (i & j) < ((KK & (1<<(31 - pos)))>>(31-pos)) )) nlsk = 1;
            res += rec(pos + 1, nlsa, nlsb, nlsk);
        }
    }
    
    return dp[pos][lsA][lsB][lsK] = res;
}

llu doIt(int A, int B, int K){
    A--, B--, K--;
    convert(a, A);
    convert(b, B);
    
    KK = K;
    memset(vis, 0, sizeof(vis));
    return rec(0, 0, 0, 0);
}

int main(){
    int test, ks;
    int A, B, K;
    
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    while ( scanf("%d", &test) == 1 ){
        for ( ks = 1 ; ks <= test ; ks++ ){
            scanf("%d%d%d", &A, &B, &K);

            llu cnt = doIt(A, B, K);
            printf("Case #%d: %lld\n", ks, cnt);
            /*cnt = brute(A, B, K);
            printf("Case #%d: %lld\n", ks, cnt);*/
        }
    }
    
    return 0;
}
