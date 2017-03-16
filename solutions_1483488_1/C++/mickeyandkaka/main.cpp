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
bool hash [10000010];


int T;
int a,b;

char str[10];

int tran(int num)
{
    int len = 0;
    while(num>0)
    {
        str[++len] = num%10+'0';
        num/=10;
    }

    for(int i=1; i<=len/2; i++)
        swap(str[i],str[len+1-i]);
    return len;
}

void fun(int len)
{
    char ch = str[1];
    for(int i=1; i<=len-1; i++)
        str[i] = str[i+1];
    str[len] = ch;
}


int decode(int len)
{
    int sum = 0;
    for(int i=1; i<=len; i++)
        sum = sum*10+str[i]-'0';
    return sum;
}

int main()
{
    //freopen("D:\\C-large.in","r",stdin);
    //freopen("D:\\C-large.out","w",stdout);

    int cas = 1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&a,&b);
        int ans = 0;
        clr(hash,false);

        for(int i=a; i<=b; i++)
        {
            if(hash[i]) continue;
            hash[i] = true;
            clr(str,0);
            int len = tran(i);
            int c = 1;
            int time = 1;

            while(1)
            {
                fun(len);
                time++;

                if(time > len)  break;

                int n = decode(len);
                if(hash[n]) continue;
                hash[n] = true;

                int cnt = 0,t=n;
                while(t>0)
                {
                    cnt++;
                    t/=10;
                }

                if(n > b || n < a || cnt!=len)   continue;
                c++;
            }
            ans += c*(c-1)/2;
        }
        printf("Case #%d: %d\n",cas++,ans);

    }
    return 0;
}
