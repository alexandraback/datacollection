#include<bits/stdc++.h>
using namespace std;


int sum;
bool v[20];
void add(long long c)
{
    while(c)
    {
        if(v[c%10]==0)v[c%10]=1,sum++;
        c/=10;
    }
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.txt","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        sum=0;memset(v,0,sizeof(v));
        long long n,s=0;scanf("%lld",&n);
        if(n==0)printf("Case #%d: INSOMNIA\n",ti++);
        else
        {
            do s+=n,add(s);
            while(sum<10);
            printf("Case #%d: %lld\n",ti++,s);
        }
    }
	return 0;
}
