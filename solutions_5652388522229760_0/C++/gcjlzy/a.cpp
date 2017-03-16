#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+1;
int a[10];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        int n,i,s=0;
        scanf("%d",&n);
        memset(a,0,sizeof a);
        for(i=1;i<1e3;i++)
        {
            int x=i*n;
            while(x){if(!a[x%10]){a[x%10]=1;s++;}x/=10;}
            if(s==10)break;
        }
        printf("Case #%d: ",k);
        if(s==10)printf("%d\n",i*n);
        else printf("INSOMNIA\n");
    }
    return 0;
}
