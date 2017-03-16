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

LL b, m;

int g[55][55];
LL cnt[55];

int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);

    //freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt3.in", "r", stdin);
   //freopen("B-large.in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cas = 1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d: ", cas++);

        cin >> b >> m;
        if(b == 2)
        {
            if(m == 1)
            {
                printf("POSSIBLE\n");
                printf("01\n00\n");
            }
            else
            {
                printf("IMPOSSIBLE\n");
            }
            continue;
        }

        clr(g, 0);
        for(int i=2; i<=b-1; i++)
        {
            cnt[i] = 1ll << (i - 2);
            for(int j=2; j<i; j++)
            {
                g[i][j] = 1;
            }
            g[i][b] = 1;
        }

        if((m & (m -1)) == 0)
        {
            m --;
            g[1][b] = 1;
        }

        LL val = 0;
        for(int j=2; j<=b-1; j++)
        {
            int idx = j - 2;
            if( m & (1ll << idx) )
            {
                val += 1ll << idx;
                g[1][j] = 1;
            }
        }


        if(val != m)
        {
            //if(val + 1 == m)
            //{
                //g[1][b] = 1;

                //printf("POSSIBLE\n");
                //for(int i=1; i<=b; i++)
                //{
                    //for(int j=1; j<=b; j++)
                    //{
                        //printf("%d", g[i][j]);
                    //}
                    //puts("");
                //}


            //}
            //else
            {
                printf("IMPOSSIBLE\n");
            }
        }
        else
        {
            printf("POSSIBLE\n");
            for(int i=1; i<=b; i++)
            {
                for(int j=1; j<=b; j++)
                {
                    printf("%d", g[i][j]);
                }
                puts("");
            }

        }

    }
    return 0;
}
