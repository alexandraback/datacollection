#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

#define clr(a,b)    (memset(a,b,sizeof(a)))
#define PB push_back
#define MP make_pair
#define SZ(v) (int)v.size()
#define ALL(c) c.begin(),c.end()
#define forn(i,s,t)   for(int i=s; i<=t; i++)
#define repv(i,v)   for(int i=0;i<(int)v.size();i++)
#define reps(i,s)   for(int i=0;i<(int)s.length();i++)
#define repi(it,c)  for(typeof(c.begin()) it=c.begin();it!=c.end();++it)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;


int T;
int n,s,p;

bool check1(int a)
{
    int s = a-p;
    if(s >= max(2*(p-1),0) )     return true;
    return false;
}

bool check2(int a)
{
    int s = a-p;
    if(s >= max(2*(p-2),0) )    return true;
    return false;
}

int main()
{
    //freopen("D:\\B-small-attempt0.in","r",stdin);
    //freopen("D:\\B-small-attempt0.out","w",stdout);

    int cas = 1;
    scanf("%d",&T);

    while(T--)
    {
        int ans1 = 0,ans2 = 0;
        scanf("%d%d%d",&n,&s,&p);
        for(int i=1; i<=n; i++)
        {
            int a;
            scanf("%d",&a);
            if(check1(a)) ans1++;
            else
            {
                if(check2(a))
                    ans2++;
            }
        }
        printf("Case #%d: %d\n",cas++,ans1+min(ans2,s));
    }

	return 0;
}
