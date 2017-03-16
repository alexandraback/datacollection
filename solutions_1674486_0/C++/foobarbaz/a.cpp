#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)	for(int i=(a); i<(b); ++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define MP make_pair
#define PB push_back
#define SZ size()
#define iss istringstream 

#define SORT(x) sort(x.begin(), x.end())
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end()) 
#define dbg(x) cerr << #x << " -> '" << (x) << "'\t"
#define dbge(x) cerr << #x << " -> '" << (x) << "'\n"

typedef long long ll, int64;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;

ll MODS[] = {100000007, 100000931};
int64 INF = 1000*1000*1001;

//bool ed[1024][1024];
VVI npaths;
int n;

void print(VVI& mat) {
    int n = mat.SZ;
    FOR (i, 0, n)   {
        FOR (j, 0, n)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

VVI multiply(VVI& a, VVI& b, ll mod)    {
    int n = a.SZ;
    VVI c(n, VI(n, 0));
    FOR (i, 0, n)   FOR (j, 0, n)   {
        FOR (k, 0, n)   {
            c[i][j] += (a[i][k] * b[k][j]) % mod;
        }
        c[i][j] %= mod;
    }
    return c;
}
 
// VVI expon(VVI& mat, int k)   {
//     if (k == 1)   {
//         cout << "k = " << k << endl;
//         print(mat);
//         return mat;
//     }
//     VVI foo = expon(mat, k / 2);
//     VVI bar = multiply(foo, foo);
//     if (k % 2 == 1) {
//         foo = multiply(bar, mat);
//         cout << "k = " << k << endl;
//         print(foo);
//         return foo;
//     }
//     else    {
//         return bar;
//     }
// }


int main(void)	{
	int T;
    int n;
	cin >> T;
	FOR (nc, 1, T+1)	{
        cin >> n;
        // memset(ed, 0, sizeof ed);
        npaths = VVI(n, VI(n, 0));
        FOR (i, 0, n)   {
            int deg;
            cin >> deg;
            FOR (j, 0, deg) {
                int v;
                cin >> v;
                //ed[v-1][i] = true;
                npaths[v-1][i] = 1;
            }
        }
        
        // VVI ret = expon(npaths, n);
    
        bool ans = false;
        
        FOR (idx, 0, 2) {
            VVI curmat(n, VI(n, 0));
            VVI totmat(n, VI(n, 0));
            FOR (i, 0, n)   curmat[i][i] = 1;
            FOR (t, 0, n)   {
                curmat = multiply(curmat, npaths, MODS[idx]);
                FOR (i, 0, n)   FOR (j, 0, n)   totmat[i][j] = (totmat[i][j] + curmat[i][j]) % MODS[idx];
            }
        
            // FOR (i, 0, n)   {
            //     FOR (j, 0, n)
            //         cout << totmat[i][j] << "\t";
            //     cout << endl;
            // }
        
            FOR (i, 0, n)   FOR (j, 0, n)   if (j != i && totmat[i][j] > 1) {
                ans = true;
                break;
            }
        }
        
		cout << "Case #" << nc << ": " << (ans ? "Yes" : "No") << endl;
	}
	
	
}
