#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

int a,n,la,ca;
int m[1005];

void input()
{
	int i;
	scanf("%d %d",&a,&n);
	for(i=1;i<=n;i++)
		scanf("%d",&m[i]);
	sort(m+1,m+n+1);
}

void process()
{
	int i,k,la1,a1=a;
	la=n;
	la1=0;
	for(i=1;i<=n;i++)
	{
		if(a==1)
		{
			break;
		}
		if(a>m[i])
			a+=m[i];
		else
		{
			while(a<=m[i])
			{
				a=2*a-1;
				la1++;
			}
			a+=m[i];
		}
		if(la>la1+n-i)
			la=la1+n-i;
	}
}
void output()
{
	printf("Case #%d: %d\n",ca,la);
}

int main()
{
	int i,t;
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt", stdout);
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		input();
		process();
		output();
	}
	return 0;
}