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
const int N = 2222;
int f[N];

bool check(int u, int v)
{
    if(f[u] == v)
        return true;
    return false;
}

int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);

    freopen("C-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt1.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cas = 1;
    scanf("%d", &T);

    while(T--)
    {
        printf("Case #%d: ", cas++);

        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&f[i]);
            f[i]--;
        }

        int ans = 2;
        for(int st=1; st<(1<<n); st++)
        {
            int tmp = __builtin_popcount(st);
            if(tmp <= ans) continue;

            int t[N];
            int tc = 0;
            for(int i=0; i<n; i++)
            {
                if( (1 << i) & st ){
                    t[tc++] = i;
                }
            }

            sort(t, t+tc);
            do{
                int v[N];
                int cc = 0;
                for(int it=0; it<tc; it++)
                {
                    v[++cc] = t[it];
                }
                v[++cc] = t[0];
                v[++cc] = t[1];

                bool ok = true;
                for(int i=2; i<=cc-1; i++)
                {
                    if(check(v[i], v[i-1]) || check(v[i], v[i+1]))
                        continue;
                    else
                    {
                        ok = false;
                        break;
                    }
                }


                if(ok)
                {
                    ans = tmp;
                    break;
                }

            }while(next_permutation(t, t+tc));

        }
        printf("%d\n", ans);

    }

    return 0;
}
