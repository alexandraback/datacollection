#include <cstdio>
int q,t,n,a[202],i,sum,j,l,r,mid;
double c[202],b[202],ans1,ans2,score;
int main ()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&t);
	for(q=1;q<=t;q++)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		ans1=0.0;
		for(i=0;i<n-1;i++)
		{
			l=0; r=1000000000;
			while(l<r)
			{
				mid=(r+l)/2+(r+l)%2;
				ans2=mid/10000000.0;
				score=a[i]+sum*ans2/100.0;
				for(j=i+1;j<n;j++)
				{
					if(a[j]>=score)b[j]=0;
					else b[j]=(score-a[j])/sum*100;
					ans2+=b[j];
				}
				if(ans1+ans2>100)r=mid-1;
				else l=mid;
			}
			b[i]=l/10000000.0;
			ans1+=b[i];
		}
		b[n-1]=100.0;
		for(i=0;i<n-1;i++)
			b[n-1]-=b[i];
		printf("Case #%d:",q);
		for(i=0;i<n;i++)
			printf(" %lf",b[i]);
		printf("\n");
	}
	
	return 0;
}

