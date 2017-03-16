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

struct jps {
    int j;
    int p;
    int s;
};

void solve() {
    ll T;
    cin>>T;
    forn(t, T) {
        cout<<"Case #"<<t+1<<": ";
        int j,p,s,k;
        cin>>j>>p>>s>>k;
        vector<jps> v;
        vector<bool> ok;
        forn(j1, j) {
            forn(p1, p) {
                forn(s1, s) {
                    v.push_back({j1, p1, s1});
                    ok.push_back(true);
                }
            }
        }
        
        forn(i, v.size()) {
            int r = 0;
            for(int l = 0; l<i; ++l) {
                if(!ok[l])
                    continue;
                if(v[l].j == v[i].j && v[l].p == v[i].p)
                    r++;
            }
            if(r>=k) {
                ok[i]=false;
                continue;
            }
            
            r = 0;
            for(int l = 0; l<i; ++l) {
                if(!ok[l])
                    continue;
                if(v[l].j == v[i].j && v[l].s== v[i].s)
                    r++;
            }
            if(r>=k) {
                ok[i]=false;
                continue;
            }
            
            r = 0;
            for(int l = 0; l<i; ++l) {
                if(!ok[l])
                    continue;
                if(v[l].s == v[i].s && v[l].p == v[i].p)
                    r++;
            }
            if(r>=k) {
                ok[i]=false;
                continue;
            }
        }
        int res = 0;
        forn(i, v.size()) {
            if(!ok[i])
                continue;
            res++;
        }
        cout<<res<<endl;
        forn(i, v.size()) {
            if(!ok[i])
                continue;
            cout<<v[i].j + 1<<" "<<v[i].p + 1<<" "<<v[i].s + 1<<endl;
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