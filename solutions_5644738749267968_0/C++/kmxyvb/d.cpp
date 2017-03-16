#include<cstdio>
#include<algorithm>

int TestCase,Case;

int n,_[1100],i,j,Ans1,Ans2;

double a[1100],b[1100];

int main()
{
//	freopen("d.in","rb",stdin);
//	freopen("d.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",a+i);
		for(i=0;i<n;i++)
			scanf("%lf",b+i);
		std::sort(a,a+n);
		std::sort(b,b+n);
		memset(_,0,sizeof _);
		Ans1=Ans2=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(!_[j]&&b[j]>a[i])
					break;
			if(j==n)
				for(j=0;j<n;j++)
					if(!_[j])
						break;
			_[j]=1;
			if(a[i]>b[j])
				Ans1++;
		}
		for(i=j=0;i<n;i++)
		if(a[i]>b[j])
		{
			Ans2++;
			j++;
		}
		printf("Case #%d: %d %d\n",Case,Ans2,Ans1);
	}
	return 0;
}
