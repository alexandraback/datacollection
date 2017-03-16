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

char a[20], b[20];
int st[20], ed[20];
int l;

bool judge(int val, char*s)
{
    int dig[20];
    for(int i=0; i<l; i++)
    {
        dig[i] = val % 10;
        val /= 10;
    }
    reverse(dig, dig+l);
    for(int i=0; i<l; i++)
    {
        if( s[i] != '?' && dig[i] + '0' != s[i] )
            return false;

    }
    return true;
}
void  pp(int v)
{
    int dig[20];
    for(int i=0; i<l; i++)
    {
        dig[i] = v % 10;
        v /= 10;
    }
    reverse(dig, dig+l);
    for(int i=0; i<l; i++)
        printf("%d",dig[i]);

}

const int INF = 0x3f3f3f3f;

int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);

    freopen("B-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cas = 1;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%s%s", a, b);
        l = strlen(a);
        ed[1] = 9;
        for(int i=2; i<=5; i++)
            ed[i] = ed[i-1] * 10 + 9;

        int delta = INF;
        int va = INF, vb = INF;
        for(int ia=0; ia<=ed[l]; ia++)
        {
            for(int ib=0; ib<=ed[l]; ib++)
            {
                if(judge(ia, a) && judge(ib, b))
                {
                    int t = abs(ia-ib);
                    if(t < delta || (t == delta && ia < va) || (t == delta && ia == va && ib < vb))
                    {
                        delta = t;
                        va = ia;
                        vb = ib;
                    }

                }

            }
        }

        printf("Case #%d: ", cas++);
        pp(va);
        printf(" ");
        pp(vb);
        puts("");

    }

    return 0;
}
