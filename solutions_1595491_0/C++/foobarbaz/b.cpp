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

int64 INF = 1000*1000*1001;

bool valid (int x)  {
    return x >= 0 && x <= 10;
}

int main(void)	{
	int T, N, S, p, t[128];
	
	cin >> T;
	FOR (nc, 1, T+1)	{
        cin >> N >> S;
        cin >> p;
        FOR (i, 0, N)   {
            cin >> t[i];
        }
        
        int ans = 0;
        int avail = S;
        FOR (i, 0, N)   {
            int a = t[i] / 3;
            if (t[i] % 3 == 0)  {   //(a a a), (a-1 a a+1)
                if (a >= p)     ans++;
                else if (avail > 0 && valid(a - 1) && valid(a + 1) && a + 1 >= p) {
                    ans++;
                    avail--;
                }
            }
            else if (t[i] % 3 == 1) {   //(a a a+1), (a-1 a+1 a+1)
                if (a + 1 >= p) ans++;
            }
            else if (t[i] % 3 == 2) {   //(a a+1 a+1), (a a a+2)
                if (a + 1 >= p) ans++;
                else if (avail > 0 && valid(a + 2) && a + 2 >= p)   {
                    ans++;
                    avail--;
                }
            }
        }

        cout << "Case #" << nc << ": " << ans << endl;
	}
	
	
}
