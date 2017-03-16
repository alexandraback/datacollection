#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int,int> PII;

int a[2010];
int b[2010];

int solve()
{
	int N;
	scanf("%d",&N);
	int i;
	priority_queue<PII,vector<PII>,greater<PII> > B;
	priority_queue<PII,vector<PII>,greater<PII> > A;
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		A.push(make_pair(a[i],i));
		B.push(make_pair(b[i],i));
	}
	int s=0,c=0;
	while(!B.empty())
	{
		PII p=B.top();
		if(p.first<=s)
		{
			B.pop();
			s++;
			if(a[p.second]!=-1)s++;
			b[p.second]=-1;
			c++;
		}
		else
		{
			while(1)
			{
				if(A.empty())return -1;
				p=A.top();A.pop();
				if(b[p.second]==-1)continue;
				if(p.first>s)return -1;
				s++;c++;a[p.second]=-1;
				break;
			}
			
		}
	}
	return c;
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int T,C=0;
	scanf("%d",&T);
	while(++C<=T)
	{
		printf("Case #%d: ",C);
		
		int g=solve();
		if(g==-1)puts("Too Bad");
		else printf("%d\n",g);
	}
	return 0;
}
