#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int r, n, m, k;
int N;
ll a[100];
int ff[10];
int b[100];
string ans;
ll G;
map<ll, string> MP;
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    srand(239);
    scanf("%d", &k);
    printf("Case #1:\n");
    scanf("%d %d %d %d", &r, &n, &m, &k);


    for (int ti = 0; ti <= 100000; ti++) {
        string ss = "";
        for (int i = 0; i < n; i++) {
            a[i] = rand() % (m - 1) + 2;
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            ss += a[i] + '0';
        }
        ll G = 1;
        for (int i = 0; i < k; i++) {
            ll mp = 1;
            for (int j = 0; j < n; j++) {
                if (rand() & 1) {
                    mp *= a[j];    
                }
            }
            G = G * a[i];                
        }
//        cerr<<G<<" "<<ss<<endl;
        MP[G] = ss;
    }
    string ff = "";
    for (int i = 0; i < n; i++) {
        ff += "2";
    }
    for (int ti = 0; ti < r; ti++) {
        G = 1;
        for (int i = 0; i < k; i++) {
            scanf("%I64d", &a[i]);
            G = G * a[i] / __gcd(G, a[i]);            
        }
        if (MP.count(G) == 1) {
            printf("%s\n", MP[G].c_str());   
        } else {
            printf("%s\n", ff.c_str());
        }

    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 