#include<stdio.h>
#include<string.h>
long long int n,m,k,max,ans,c;
char s[100006],t[100006],a[100006],b[100006];

void rec(long long int x)
{
	long long int y,i,j,flg=0;
	if(x==k)
	{
		//printf("%s\n",a);
		ans++;
		y=0;
		for(i=0;i<=k-m;i++)
		{
			for(j=i;j<i+m;j++)
			{
				b[j-i]=a[j];
			}
			//printf("%s\n",b);
			flg=1;
			for(j=0;j<m;j++)
			{
				if(b[j]!=t[j])
				flg=0;
			}
			if(flg==1)
			{
				c++;
				y++;
			}
		}
		if(y>max)
		max=y;
		//printf("%lld %lld %lld\n",max,c,ans);
	}
		
	if(x<k)
	{
		for(i=0;i<n;i++)
		{
			a[x]=s[i];
			rec(x+1);
		}
	}
}

int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	
	long long int f,f1;
	double p,q,r;
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		max=0;c=0;ans=0;
		scanf("%lld %lld %lld",&n,&m,&k);
		scanf("%s %s",s,t);
		rec(0);
		//printf("%lld %lld %lld\n",max,c,ans);
		p=(double)(max);
		q=(double)(c);
		r=(double)(ans);
		q=q/r;
		printf("Case #%lld: %lf\n",f1,p-q);
	}
	return 0;
}
