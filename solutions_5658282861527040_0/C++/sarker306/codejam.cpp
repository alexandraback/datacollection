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

char str[101][101];
int N;
vector<char> run[101];
vector<int> runLen[101];

int main(){
    int test, ks;
    int A, B, K;
    
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    while ( scanf("%d", &test) == 1 ){
        for ( ks = 1 ; ks <= test ; ks++ ){
            scanf("%d%d%d", &A, &B, &K);
            
            int cnt = 0;
            for ( int i = 0 ; i < A ; i++ )
                for ( int j = 0 ; j < B ; j++ ){
                    if ( (i & j) < K ) cnt++;
                }
                    

            printf("Case #%d: %d\n", ks, cnt);
        }
    }
    
    return 0;
}
