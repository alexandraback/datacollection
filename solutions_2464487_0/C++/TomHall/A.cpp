#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
#define N 1000010
#define lp(i,n) for(i=0;i<n;i++)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

unsigned long long n,i,j,k,r,tt,t,time,sum,tmp,ans,m;
double mm;
int a[N];
char s[N];
bool flag;

FILE *in,*out;

int main()
{
    in=freopen("A-small-attempt0.in","r",stdin);
    out=freopen("A-small-attempt0.out","w",stdout);
    cin>>tt;
    for (time=1;time<=tt;time++)
    {
        cin>>r>>t;
        mm=(sqrt((2*r-1)*(2*r-1)+8*t)+1-2*r)/4;
        ans=floor(mm);

        cout<<"Case #"<<time<<": "<<ans<<endl;
    }
    return 0;
}

