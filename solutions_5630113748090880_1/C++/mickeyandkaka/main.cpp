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

int cnt[5000];


int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);

    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cas = 1;
    scanf("%d", &T);

    while(T--)
    {
        printf("Case #%d: ", cas++);

        clr(cnt, 0);
        scanf("%d", &n);
        for(int i=1; i<=2*n-1; i++)
            for(int j=1; j<=n; j++)
            {
                int a;
                scanf("%d",&a);
                cnt[a]++;
            }

        int left = n;
        for(int i=1; i<=2500; i++)
        {
            if(cnt[i] % 2 == 1)
            {
                printf("%d", i);
                if(left == 1) printf("\n");
                else printf(" ");
                left --;

            }

        }




    }

    return 0;
}
