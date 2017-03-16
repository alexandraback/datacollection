#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); puts("");}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}

#define pb push_back
#define mp make_pair
#define all(x)  (x).begin(),(x).end()
#define tr(c, it)   for(auto it=c.begin(); it!=c.end(); it++)
#define clr(a, b)   memset(a, b, sizeof(a))

int T;
int n;

string a[22], b[22];

set<string> fi, se;
set<string> comb;

bool check(int j)
{
    if(fi.find(a[j]) == fi.end())
        return false;
    if(se.find(b[j]) == se.end())
        return false;

    string s = a[j];
    s += ' ';
    s += b[j];
    if(comb.find(s) != comb.end())
        return false;
    return true;
}


int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);

    freopen("C-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cas = 1;
    cin >>T;

    while(T--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a[i] >> b[i];
        }

        int lim = (1 << n);
        int ans = 0;
        for(int i=0; i<lim; i++)
        {
            fi.clear();
            se.clear();
            comb.clear();

            for(int j=0; j<n; j++)
            {
                if(  ((1 << j ) & i) > 0)
                {
                    fi.insert(a[j]);
                    se.insert(b[j]);
                    string s = a[j];
                    s += ' ';
                    s += b[j];
                    comb.insert(s);
                }
            }

            bool ok = true;
            for(int j=0; j<n; j++)
            {
                if(  ((1 << j ) & i) == 0)
                {
                    bool can_fake = check(j);
                    if(can_fake == false)
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok == false)
                continue;
            ans = max(ans, n - __builtin_popcount(i));
        }

        printf("Case #%d: %d\n", cas++, ans);

    }

    return 0;
}
