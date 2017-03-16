#include <stdio.h>
#include <string.h>
int tcase;
int main()
{
	int loop,l,i,j,ans,temp;
	long long int n,n2;
	bool flag;
	char str[20];
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&tcase);
	for(loop=1;loop<=tcase;loop++)
	{
		ans=0;

		scanf("%lld",&n);
		if(n%10==0)
		{
			ans++;
			n--;
		}

		n2=n;

		l=0;
		while(n2>0)
		{
			n2/=10;
			l++;
		}

		if(l>=1)
			ans+=1;
		if(l>=2)
			ans+=9;
		for(i=3;i<=l;i++)
		{
			temp=1;
			if(i%2==0)
				temp*=10;
			for(j=1;j<=(i-1)/2;j++)
			{
				temp*=10;
				temp+=9;
			}
			ans+=temp;
		}

		for(i=l;i>=1;i--)
		{
			str[i]=n%10;
			n/=10;
		}

		temp=0;
		flag=false;
		for(i=l/2;i>=1;i--)
		{
			temp*=10;
			temp+=str[i];
			if((i==1 && str[i]!=1) || (i!=1 && str[i]!=0))
				flag=true;
		}
		if(flag==false)
			ans--;
		ans+=temp;

		temp=0;
		for(i=l/2+1;i<=l;i++)
		{
			temp*=10;
			temp+=str[i];
		}
		ans+=temp;

		printf("Case #%d: %d\n",loop,ans);
	}
	return 0;
}