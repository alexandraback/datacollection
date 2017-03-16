#include<ctype.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include<complex>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

#include<algorithm>
#include<string>

#define inf             2000000000
#define infLL           1000000000LL*1000000000
#define PI              3.141592653589793238462643383279502884

#define Lp0(i,n)        for(i=0;i<n;i++)
#define rLp0(i,n)       for(i=n-1;i>=0;i--)
#define Lp1(i,n)        for(i=1;i<=n;i++)
#define rLp1(i,n)       for(i=n;i>0;i--)
#define Wh(a)           while(a)

#define Pr              printf
#define Pr1(a)          printf("%d ",a)
#define Pr2(a,b)        printf("%d %d ",a,b)
#define Pr3(a,b,c)      printf("%d %d %d ",a,b,c)
#define Pr4(a,b,c,d)    printf("%d %d %d %d ",a,b,c,d)
#define Prh(a)          printf("%hd ",a)
#define Prll(a)         printf("%lld ",a)
#define Prll2(a,b)      printf("%lld %lld ",a,b)
#define PrI64(a)        printf("%I64d ",a)
#define PrI642(a,b)     printf("%I64d %I64d ",a,b)
#define Prf(a)          printf("%f ",a)
#define Prlf(a)         printf("%lf ",a)
#define Prg(a)          printf("%g ",a)
#define Prc(a)          printf("%c ",a)
#define Prs(a)          printf("%s ",a)
#define EL              printf("\n")
#define Sc              scanf
#define Sc1(a)          scanf("%d",&a)
#define Sc2(a,b)        scanf("%d %d",&a,&b)
#define Sc3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define Sc4(a,b,c,d)    scanf("%d %d %d %d",&a,&b,&c,&d)
#define Sch(a)          scanf("%hd",&a)
#define Scll(a)         scanf("%lld",&a)
#define Scll2(a,b)      scanf("%lld %lld ",&a,&b)
#define ScI64(a)        scanf("%I64d",&a)
#define ScI642(a,b)     scanf("%I64d %I64d ",&a,&b)
#define Scf(a)          scanf("%f",&a)
#define Sclf(a)         scanf("%lf",&a)
#define Scc(a)          scanf("%c",&a)
#define Scs(a)          scanf("%s",&a)
#define Scsl(a)         gets(a)

#define I               int
#define LLI             long long int
#define SI              short int
#define F               float
#define D               double
#define C               char
#define S               string
#define Mapii           map<int,int>
#define Mapsi           map<string,int>
#define Seti            set<int>
#define mSeti           multiset<int>
#define Heap            priority_queue<pii>
#define Vcti            vector<int>
#define Pii             pair<int,int>
#define Psi             pair<string,int>
#define Cmp             complex<double,double>
#define It              iterator
#define Be              begin()
#define En              end()
#define Si              size()
#define To              top()
#define Fr              front()
#define Fi              first
#define Se              second
#define Mkp             make_pair
#define Im              imag()
#define Re              real()

using namespace std;
int fl[1000],hv[1000],co[2000],nab,nco,v;
main()
{
    int cnt,nq,q,i,j,k,l;
    Sc1(nq);
    Lp1(q,nq)
    {
        Sc3(nab,nco,v);
        Lp1(i,v)
        {
            fl[i]=0;
            hv[i]=0;
        }
        fl[0]=1;
        Lp0(j,nco)
        {
            Sc1(co[j]);
            hv[co[j]]=1;
        }
        Lp0(j,nco)
            Lp0(k,nab)
                rLp0(i,v+1)
                {
                    if(i>=co[j]&&fl[i-co[j]]==1)
                        fl[i]=1;
                }
        cnt=0;
//        Lp1(i,v)
//            Pr("%d: %d\n",i,fl[i]);
        Lp1(i,v)
        {
            if(fl[i]==0)
            {
                cnt++;
                Lp1(j,v)
                    if(hv[j]==0)
                        break;
//                printf("add %d\n",j);
                hv[j]=1;
                Lp0(l,nab)
                    rLp0(k,v+1)
                    {
                        if(k>=j&&fl[k-j]==1)
                            fl[k]=1;
                    }
            }
        }
        Pr("Case #%d: %d\n",q,cnt);
    }
    return 0;
}
