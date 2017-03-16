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
	freopen("C-small-1-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,bin[20],i,j,n,m,r,num,ca=1,a[20],b[20];
	long long x,it;
	set<long long>s;
	for(i=0;i<20;i++)bin[i]=1<<i;
	scanf("%d",&t);
	while(t--)
	{
		srand(unsigned(time(0)));
		scanf("%d%d%d%d",&r,&n,&m,&num);
		printf("Case #%d:\n",ca++);
		g:while(r--)
		{
			for(i=0;i<num;i++)
			{
				scanf("%d",&a[i]);
			}
			it=10000000000;
			while(it--)
			{
				for(i=0;i<n;i++)
				{
					b[i]=rand()%(m-1)+2;
				}
				s.clear();
				for(i=0;i<bin[n];i++)
				{
					x=1;
					for(j=0;j<n;j++)
					{
						if(bin[j]&i)x*=b[j];
					}
					s.insert(x);
				}
				for(i=0;i<num;i++)
				{
					if(s.find(a[i])==s.end())break;
				}
				if(i==num||it==0)
				{
					for(i=0;i<n;i++)printf("%d",b[i]);
					printf("\n");
					goto g;
				}
			}
		}
	}
}
