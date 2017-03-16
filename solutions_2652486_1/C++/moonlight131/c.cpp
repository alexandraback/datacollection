#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;


#define PB push_back
#define MP make_pair

const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
const double pi=2.0*asin(1.0),eps=1e-8;

int main()
{
	freopen("C-small-2-attempt8.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,bin[20],i,j,n,m,r,num,ca=1,sum=0,ri=0,Max[20];
	long long a[20];
	long long x,it;
	scanf("%d",&t);
	while(t--)
	{
		srand(unsigned(time(0)));
		scanf("%d%d%d%d",&r,&n,&m,&num);
		printf("Case #%d:\n",ca++);
		g:while(r--)
		{
			if(r%100==0)cerr<<r<<" "<<ri<<endl;
			memset(Max,0,sizeof(Max));
			for(i=0;i<num;i++)
			{
				scanf("%lld",&a[i]);

				for(j=m;j>=2;j--)
				{
					x=0;
					while(a[i]%j==0)
					{
						a[i]/=j;
						x++;
					}
					if(Max[j]<x)Max[j]=x;
				}
			}
			sum=0;
			for(i=2;i<=m;i++)
			{
				sum+=Max[i];
			}
			x=0;
			for(i=2;i<=m;i++)
			{
				for(j=0;j<Max[i]&&x<n;j++)
				{
					printf("%d",i);
					x++;
				}
			}
			if(x<n)ri++;
			while(x<n)
			{
				x++;
				printf("%d",2);
			}
			printf("\n");
		}
	}
}
