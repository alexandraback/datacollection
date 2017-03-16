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
int ispalindrome(long long int no)
{
long long int rev=0,cpy=no;
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

FILE * fp,*fw;
void generate()
{
long long int i,j;
for(i=1;i<=10000000;i++)
    {
    if(ispalindrome(i))
        {
        long long y;
        y=i*i;

                    if(ispalindrome(y))
                        {
                        fprintf(fw,"%lld\n",y);
                        }
        }
    }
}

int main()
{
int i,j,t,p,x,y;

//fp=fopen("inputt.txt","r");
fw=fopen("precompnos.txt","w");
generate();
return 0;
}
