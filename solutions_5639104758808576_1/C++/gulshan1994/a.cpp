#include <vector>
#include <string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<string>
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //freopen("practice.in","r",stdin);
	//freopen("A-large-practice.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("output.out","w",stdout);
	long long t,m;
	scanf("%lld",&t);
	for(m=1;m<=t;m++)
    {
        long long n,standing,i,j,ans=0;
        char arr[10002];
        scanf("%lld %s",&n,arr);
        standing=(long long)(arr[0]-'0');
        for(i=1;i<=n;i++)
        {
            if(standing>=i)
            {
                standing+=(long long)(arr[i]-'0');
            }
            else
            {
                ans+=i-standing;
                standing=i;
                standing+=(long long)(arr[i]-'0');
            }
        }
        printf("Case #%lld: ",m);
        printf("%lld\n",ans);
    }
    return 0;
}
