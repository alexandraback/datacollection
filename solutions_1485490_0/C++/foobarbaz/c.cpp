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

vector<ll> cnta, cntb;
VI a, b;

int N, M;

ll ans;

int bpt[4];

//search for a[k], starting at idx in b
void go(int k, int idx) {
    if (k == N) {
        ll ret = 0;
        FOR (i, 1, N + 1)   {
            ll cur = 0;
            FOR (j, bpt[i-1] + 1, bpt[i] + 1) if(b[j] == a[i-1]) {
                cur += cntb[j];
            }
            ret += min(cur, cnta[i-1]);
        }
        
        if (ans < ret)  {
            // FOR (i, 0, N + 1)   cout << bpt[i] << ",";
            // cout << "\t" << ret << endl;
            ans = ret;
        }
        return;
    }
    FOR (i, idx, M) if (b[i] == a[k])   {
        bpt[k+1] = i;
        go(k + 1, i + 1);
    }
}

int main(void)	{
	int T;
	cin >> T;
	FOR (nc, 1, T+1)	{
        int origN;
        cin >> origN >> M;

        ll origcnta[128], origcntb[128];
        int origa[128], origb[128];
        
        FOR (i, 0, origN)   {
            cin >> origcnta[i] >> origa[i];
        }
        
        FOR (i, 0, M)   {
            cin >> origcntb[i] >> origb[i];
        }
        
        ans = 0;
        FOR (msk, 1, (1<<origN))  {
            vector<ll> tmpa;
            VI ta;
            FOR (i, 0, origN) if ((msk&(1<<i)) != 0)   {
                tmpa.PB(origcnta[i]);
                ta.PB(origa[i]);
            }

            cnta.clear();
            a.clear();
            cntb.clear();
            b.clear();
            
            int i = 0;
            while (i < tmpa.SZ)    {
                int save = i;
                ll cnt = 0;
                while (i < tmpa.SZ && ta[i] == ta[save]) {
                    cnt += tmpa[i];
                    i++;
                }
                cnta.PB(cnt);
                a.PB(ta[save]);
                cntb.PB(0);
                b.PB(ta[save]);
            }

            N = cnta.SZ;
        
            FOR (i, 0, M)   {
                cntb.PB(origcntb[i]);
                b.PB(origb[i]);
            }
        
            FOR (i, 0, N)   {
                cntb.PB(0);
                b.PB(a[i]);
            }
        
            M = cntb.SZ;

            bpt[0] = -1;
        
            // cout << "msk = " << msk << endl;
            // FOR (i, 0, N)   cout << cnta[i] << "\t";
            // cout << endl;
            // FOR (i, 0, N)   cout << a[i] << "\t";
            // cout << endl;
            // FOR (i, 0, M)   cout << cntb[i] << "\t";
            // cout << endl;        
            // FOR (i, 0, M)   cout << b[i] << "\t";
            // cout << endl;
            
            go(0, 0);
        }
		cout << "Case #" << nc << ": " << ans << endl;
	}
	
	
}
