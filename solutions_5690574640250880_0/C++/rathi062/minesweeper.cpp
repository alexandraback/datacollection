#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 52
#define MOD 1000002013

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getcx();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
 n=n*sign;
 }*/


using namespace std;

char check[MX][MX];
void print(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<check[i][j];
        cout<<endl;
    }
}
int main()
{
    int t=0,r,c,m;
    
    inp(t);
    for(int test = 1;test <= t;test++)
    {
        
        inp(r);
        inp(c);
        inp(m);
        m=r*c-m;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                check[i][j]='*';
        if(m==0)
        {
            printf("Case #%d:\n",test);
            print(r,c);
            continue;
        }
        if(r==1 || c==1)
        {
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c&m>0;j++)
                {
                    check[i][j]='.';
                    m--;
                }
                if(!m)
                    break;
            }
            check[0][0]='c';
            printf("Case #%d:\n",test);
            print(r,c);
            continue;
        }
        if(r!=1&&c!=1)
        {
            if(m==2 || m==3 || m==5 || m==7)
            {
                printf("Case #%d:\nImpossible\n",test);
                continue;
            }
            if(m==1)
            {
                check[0][0]='c';
                printf("Case #%d:\n",test);
                print(r,c);
                continue;
            }
            else
            {
                if(m&1)
                {
                    if(r==2 || c==2)
                    {
                        printf("Case #%d:\nImpossible\n",test);
                        continue;
                    }
                    
                    for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                            check[i][j]='.';
                    m-=9;
                    check[1][1]='c';
                    for(int i=3;i<c & m>0;i++)
                    {
                        check[0][i]='.';
                        check[1][i]='.';
                        m-=2;
                    }
                    for(int i=3;i<r & m>0;i++)
                    {
                        check[i][0]='.';
                        check[i][1]='.';
                        m-=2;
                    }
                    for(int i=3;i<c &m>0;i++)
                    {
                        check[2][i]='.';
                        m--;
                    }
                    for(int i=3;i<r;i++)
                    {
                        for(int j=2;j<c & m>0;j++)
                        {
                            check[i][j]='.';
                            m--;
                        }
                        if(!m)
                            break;
                    }
                    printf("Case #%d:\n",test);
                    print(r,c);
                }
                else
                {
                    for(int i=0;i<2;i++)
                        for(int j=0;j<2;j++)
                            check[i][j]='.';
                    m-=4;
                    check[0][0]='c';
                    for(int i=2;i<c & m>0;i++)
                    {
                        check[0][i]='.';
                        check[1][i]='.';
                        m-=2;
                    }
                    for(int i=2;i<r & m>0;i++)
                    {
                        check[i][0]='.';
                        check[i][1]='.';
                        m-=2;
                    }
                    for(int i=2;i<c;i++)
                    {
                        for(int j=2;j<r&m>0;j++)
                        {
                            m--;
                            check[j][i]='.';
                        }
                        if(!m)
                            break;
                    }
                    
                    printf("Case #%d:\n",test);
                    print(r,c);
                    
                }
            }
        }
        
    }
    return 0;
}
