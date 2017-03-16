#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
 
#define FOR(i,f,t) for(int i = f;i<t;i++)
#define For(i, t) for(int i = 0;i<t;i++)
#define ITER(it, a) for(typeof (a.begin()) it = a.begin();it != a.end();it++)
#define range(cont) cont.begin(), cont.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back
#define inf 100000

using namespace std;
using namespace std::tr1;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int cas;
ll two_pow[45];

int main() {

    two_pow[0] = 1;
    FOR(i,1, 45){
        two_pow[i] = two_pow[i-1]<<1;
    }

    scanf("%d", &cas);
    For(cc, cas){
        printf("Case #%d: ",cc+1);
        ll a, b;
        char ch;
        cin >> a >> ch>> b;

        ll g = __gcd(a,b);
        a /= g;
        b /= g;

        bool ok = 0;
        For(i, 45)
        if(b== two_pow[i]){
            ok = 1;
            break;
        }
        if((a > b) || !ok){printf("impossible\n");continue;}
        ok = 0;
        For(i, 45)
        if(b <= (two_pow[i] * a)){
            ok = 1;
            printf("%d\n", i);
            break;
        }
        if(!ok)puts("impossible");

    }

    return 0;
}