//#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define ll __int64
#define inf 1000000007
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
int abs(int x) {return x<0?-x:x;}
const int N=1000005;
const int M=600005;
int num[N];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.out","w",stdout);
    int i,j,k=1;
    int n,m,tt,t;
    scanf("%d",&tt);
    while(tt--)
    {
		printf("Case #%d: ",k++);
		scanf("%d%d",&m,&n);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		if(m==1) {printf("%d\n",n);continue;}
		sort(num,num+n);
		int ans=n,sum=0;
		for(i=0;i<n;i++)
		{
			if(m>num[i]) m+=num[i];
			else
			{
				while(m<=num[i]) m+=m-1,sum++;
				m+=num[i];
			}
			ans=min(ans,sum+n-i-1);
		}
		printf("%d\n",ans);
    }
    return 0;
}