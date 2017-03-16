#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#define MAXN 128
#define INF 1<<30
///
using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int c=1; c<=cases; c++)
    {
        long long r,t;
        scanf("%lld %lld",&r,&t);
        long long tmp1=(long long)sqrt(1.0*t/2);
        long long tmp2=(long long)(1.0*t/(2*r-1)+1);
        //printf("%lld\n",tmp1);
        printf("Case #%d: ",c);
        long long ll,rr;
        ll=0;
        rr=min(tmp1,tmp2);
        while(rr-ll>=1)
        {
            long long mid=(ll+rr+1)/2;
            long long cur=2*mid*mid+(2*r-1)*mid;
            if(cur<=t) ll=mid;
            else rr=mid-1;
        }
        printf("%lld\n",ll);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
