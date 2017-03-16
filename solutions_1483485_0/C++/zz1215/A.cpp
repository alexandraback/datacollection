#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<cstring>
#include<iomanip>
using namespace std;

#ifdef _WIN32
#define i64 __int64
#define out64 "%I64d\n"
#define in64 "%I64d"
#else
#define i64 long long
#define out64 "%lld\n"
#define in64 "%lld"
#endif

#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)
#define FF(i,a)         for( int i = 0 ; i < (a) ; i ++)
#define FFD(i,a)        for( int i = (a)-1 ; i >= 0 ; i --)
#define S64(a)          scanf(in64,&a)
#define SS(a)           scanf("%d",&a)
#define LL(a)           ((a)<<1)
#define RR(a)           (((a)<<1)+1)
#define SZ(a)           ((int)a.size())
#define PP(n,m,a)       puts("---");FF(i,n){FF(j,m)cout << a[i][j] << ' ';puts("");}
#define pb              push_back
#define CL(Q)           while(!Q.empty())Q.pop()
#define MM(name,what)   memset(name,what,sizeof(name))
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)

const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-10;
const double pi = acos(-1.0);

int ex[]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

int T;
string s;
string ans;
char ss[1111];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    write;
    cin>>T;
    cin.getline(ss,111);
    for(int tt=1;tt<=T;tt++)
    {
        cin.getline(ss,1000);
        s = ss;
        ans.clear();
        char temp;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                ans += ' ';
            }
            else
            {
                temp = ex[s[i]-'a'] + 'a';
                ans += temp;
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
