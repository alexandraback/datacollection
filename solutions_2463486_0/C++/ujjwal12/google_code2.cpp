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
#include<cmath>

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
int ispalindrome(int no)
{
int rev=0,cpy=no;
while(no!=0)
    {
        rev=rev*10+no%10;
        no=no/10;
    }
if(cpy==rev)
    return 1;
else
    return 0;
}
int a[1001]={0};
void generate()
{
int i,j;
for(i=1;i<=1000;i++)
    {
    if(!ispalindrome(i))
       {
        a[i]=a[i-1];
       }
    else
        {
        double x;
        int y;
        y=(int)sqrt((double)i);
        x=sqrt((double)i);
         if(x==y)
                    {
                    if(ispalindrome(y))
                        a[i]=a[i-1]+1;
                    else
                         a[i]=a[i-1];
                    }
                else
                    a[i]=a[i-1];
        }
    }
}
int main()
{
int i,j,t,p,x,y;
FILE * fp,*fw;
fp=fopen("C-small-attempt0.in","r");
fw=fopen("output2.txt","w");
fscanf(fp,"%d",&t);
generate();
for(p=1;p<=t;p++)
    {
    fscanf(fp,"%d %d",&x,&y);
    fprintf(fw,"Case #%d: %d\n",p,(a[y]-a[x-1]));
    }

return 0;
}
