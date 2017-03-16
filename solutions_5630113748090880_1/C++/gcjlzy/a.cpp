#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int N=2500+1;
int a[N];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        int n,i;
        cin>>n;memset(a,0,sizeof a);
        for(i=0;i<n*(2*n-1);i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        printf("Case #%d:",k);
        for(i=1;i<N;i++)
            if(a[i]&1)printf(" %d",i);
        printf("\n");
    }

    return 0;
}
