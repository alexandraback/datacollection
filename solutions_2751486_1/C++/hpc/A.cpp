#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXL 1000005
using namespace std;
int L,N;
long long int cnt;
char c[MAXL];
bool check(char c)
{
    if(c=='i'||c=='e'||c=='o'||c=='u'||c=='a') return false;
    return true;
}
int process()
{
    L=strlen(c);
    cnt=0;
    int b=-1,tmp=0,p,q,flag=0;
    for(int i=0;i<L;++i)
    {
        if(check(c[i]))
        {
            tmp++;
            if(tmp==N)
            {
                p=L-1-i+1;
                q=i-N+1-b;
                cnt+=(long long int)(p)*(long long int)(q);
                //cout<<p<<" "<<q<<"\n";
            }
            else if(tmp>N)
            {
                p=L-1-i+1;
                cnt+=(long long int)(p);
            }
            if(tmp>=N) flag=i-N+1;
        }
        else
        {
            tmp=0;
            if(cnt>0) b=flag;
        }
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,Case;
    scanf("%d",&T);
    Case=T;
    while(T--)
    {
        scanf("%s%d",c,&N);
        process();
        printf("Case #%d: %lld\n",Case-T,cnt);
    }
    return 0;
}
