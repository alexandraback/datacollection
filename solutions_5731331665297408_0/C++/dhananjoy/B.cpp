#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;

int t, n, m;
VPI e;
set<PI> s;
set<PI>::iterator it;
string ans, zip[64], maxzip;
VI v;
int next[64];

string cost()
{
    s.clear();
    for (int i = 0; i < sz(e); ++i) {
        s.insert(e[i]);
    }
    int curr = v[0];
    //cout << v[0];
    for (int i = 0; i < n; ++i)
		next[i] = -1;
    string ret = zip[v[0]];
    for (int i = 1; i < n; ++i)
    {
        while (s.find(mp(curr, v[i])) == s.end())
        {
            if (next[curr] == -1)
            {
                return maxzip;
            }
            else
            {
                int tmp = curr;
                curr = next[curr];
                next[tmp] = -1;
                //cout << " -> " << curr;
            }
        }
        it = s.find(mp(curr, v[i]));
        s.erase(it);
        it = s.find(mp(v[i], curr));
        s.erase(it);
        ret += zip[v[i]];
        next[v[i]] = curr;
        curr = v[i];
        //cout << " -> " << curr;
    }
    while(next[curr] != -1) {
        curr = next[curr];
        //cout << " -> " << curr;
    }
    //cout << '\n';
    for (int i = 0; i < n; ++i)
	    if (next[curr] != -1)
		    return maxzip;
	for (int i = 0; i < n; ++i)
	{
		//cout << v[i] << ' ';
	}
	//cout << " " << ret << '\n';
    return ret;
}

int main (int argc, char const *argv[])
{
    // ios::sync_with_stdio(false);


    cin >> t;
    for (int cs = 1; cs <= t; ++cs)
    {
        cin >> n >> m;
        maxzip = "";
        for (int i = 0; i < n; ++i) {
	        cin >> zip[i];
	        maxzip += "99999";
        }
        
        e.clear();
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            e.pb(mp(a - 1, b - 1));
            e.pb(mp(b - 1, a - 1));
        }
        ans = maxzip;
        v.clear();
        for (int i = 0; i < n; ++i)
            v.pb(i);
        // v.pb(4);
        // v.pb(1);
        // v.pb(0);
        // v.pb(3);
        // v.pb(2);
        // cost();
        do
        {
        	ans = min(ans, cost());
        }
        while (next_permutation(all(v)));
        cout << "Case #" << cs << ": " << ans << "\n";


    }

    return 0;
}
