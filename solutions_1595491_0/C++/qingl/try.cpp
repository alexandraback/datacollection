#include<cstdio>
#include<cstring>
const int N = 105;
int t[N];
bool u[N];
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out.out","w",stdout);
	int T,s,p,r,ca=1,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&s,&p);
		r=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",t+i);
			if(t[i]%3==0)
			{
				if(t[i]/3>=p)r++;
				else if(t[i]>0&&t[i]/3==p-1&&s){r++;s--;}
			}
			else if(t[i]%3==1)
			{

				if(t[i]/3+1>=p)r++;
			}
			else
			{
				if(t[i]/3+1>=p)r++;
				else if(t[i]/3+1==p-1&&s){r++;s--;}
			}
		}
		printf("Case #%d: %d\n",ca++,r);
	}
	return 0;
}
