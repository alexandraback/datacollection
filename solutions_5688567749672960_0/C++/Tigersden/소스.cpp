#include <stdio.h>
#include <queue>
using namespace std;
int tcase,check[1100000];
int main()
{
	int loop,n,i,p,p2,temp;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	queue<int> q;
	queue<int> q2;
	scanf("%d",&tcase);
	for(loop=1;loop<=tcase;loop++)
	{
		while(q.size()>0)
		{
			q.pop();
			q2.pop();
		}
		for(i=1;i<=1000000;i++)
			check[i]=0;
		scanf("%d",&n);
		q.push(1);
		q2.push(1);
		check[1]=1;
		while(q.size()>0)
		{
			p=q.front();
			p2=q2.front();
			q.pop();
			q2.pop();
			if(p==n)
			{
				break;
			}
			if(check[p+1]==0)
			{
				q.push(p+1);
				q2.push(p2+1);
				check[p+1]=1;
			}
			temp=0;
			while(p>0)
			{
				temp*=10;
				temp+=p%10;
				p/=10;
			}
			if(check[temp]==0)
			{
				q.push(temp);
				q2.push(p2+1);
				check[temp]=1;
			}
		}
		printf("Case #%d: %d\n",loop,p2);
	}
	return 0;
}