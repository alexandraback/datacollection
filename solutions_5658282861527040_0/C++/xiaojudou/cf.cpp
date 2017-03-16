#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


int t;
int a,b,k;
int ans,tt;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--){
        scanf("%d%d%d",&a,&b,&k);
        ans=0;
        for(int i=0;i<a;++i)
        {
            for(int j=0;j<b;++j)
            {
                if((i&j)<k)ans++;
            }
        }
        printf("Case #%d: %d\n",++__,ans);
    }
    return 0;
}
