#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define mod 1000000007
#define pinf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a);
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define ps(a) printf("%s",a);
#define nline printf("\n")
#define pc(a) printf("%c",a)
#define ll long long
#define MAX(a,b,c) ((a>b)?(a>c?a:c):(b>c?b:c))
#define MIN(a,b,c) ((a<b)?(a<c?a:c):(b<c?b:c))
long long precomp[40]={0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,
400080004,
404090404LL,
10000200001LL,
10221412201LL,
12102420121LL,
12345654321LL,
40000800004LL,
1000002000001LL,
1002003002001LL,
1004006004001LL,
1020304030201LL,
1022325232201LL,
1024348434201LL,
1210024200121LL,
1212225222121LL,
1214428244121LL,
1232346432321LL,
1234567654321LL,
4000008000004LL,
4004009004004LL
};
int main()
{
int t,p;
long long i,j,x,y,pos1,pos2;
FILE * fp,*fw;
fp=fopen("C-large-1.in","r");
fw=fopen("outputlargecodec.txt","w");
fscanf(fp,"%d",&t);
for(p=1;p<=t;p++)
    {
    fscanf(fp,"%lld %lld",&x,&y);
    for(i=1;i<=39;i++)
        {
        if(precomp[i]>=x)
            {
                pos1=i;
                break;
            }
        }

     for(i=1;i<=39;i++)
        {
        if(precomp[i]>y)
            {
                pos2=i;
                break;
            }
        }
       if(i==40)
            pos2=40;
         fprintf(fw,"Case #%d: %d\n",p,pos2-pos1);

    }

return 0;
}
