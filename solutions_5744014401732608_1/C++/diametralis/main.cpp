#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>

#include <cstring>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <cassert>
#include <cmath>
#include <iomanip>

#define eps e-8

using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define ll long long int
//#define INF 1000000000


void solve() {
    ll T;
    cin>>T;
    forn(t, T) {
        cout<<"Case #"<<t+1<<": ";
        ll b, m;
        cin>>b>>m;
        ll mx = 1;
        forn(i, b-2) {
            mx*=2;
        }
        if(m>mx) {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        vector<vector<ll>> v(b);
        forn(i, b) {
            forn(j, b) {
                v[i].push_back(0);
            }
        }
        v[0][b-1]=1;
        m--;
        
        ll x = 1;
        ll cur = b-2;
        while(m!=0) {
            if(m & x) {
                v[0][cur] = 1;
                m-=x;
            }
            x = x<<1;
            cur--;
        }
        for(ll x = b-2; x>0; --x) {
            for(ll y = x+1; y<b; ++y) {
                v[x][y]=1;
            }
        }
        forn(i, b) {
            forn(j, b) {
                cout<<v[i][j];
            }
            cout<<endl;
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
#ifdef diametralis
    freopen("/Users/oxo/Documents/codeforces/IO/input.txt", "rt", stdin);
    freopen("/Users/oxo/Documents/codeforces/IO/output.txt", "wt", stdout);
#endif
    solve();
#ifdef diametralis
    cerr << "Time == " << clock() << endl;
#endif
}