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

char g[30]={"yhesocvxduiglbkrztnwjpfmaq"};
char str[1000];
int T;

int main()
{
    //freopen("D:\\A-small-attempt1.in","r",stdin);
    //freopen("D:\\A-small-attempt1.out","w",stdout);

    int cas = 1;
    scanf("%d",&T);
    char ch = getchar();

    while(T--)
    {
        clr(str,0);
        gets(str);
        int len = strlen(str);
        printf("Case #%d: ",cas++);
        for(int i=0; i<len; i++)
        {
            if(isalpha(str[i]))
                putchar(g[str[i]-'a']);
            else
                putchar(' ');
        }
        puts("");
    }

	return 0;
}
