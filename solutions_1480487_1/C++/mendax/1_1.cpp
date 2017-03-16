#include<stdio.h>
int main()
{
	int cases;
	int i,n,sum,j,k;
	int a[1024];
	scanf("%d",&cases);
	for(int cnt=1;cnt<=cases;cnt++){
		printf("Case #%d:",cnt);
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(i=0;i<n;i++)
		{
			  double h=100.0,l=0.0,m,score;
			while(h-l>=0.00001)
			{
				m=(h+l)/2;
				score=a[i]+sum*m/100;
				  double total=1-m/100;
  double diff;
				for(j=0;j<n;j++)
					if(j!=i)
{
						diff=(score-a[j])/sum;
						if(diff>0) 
							total-=diff;
						if(total<0) 
							break;
					}
				if(total<0) h=m;
				else l=m;
			}
			printf(" %lf",m);
		}
		printf("\n");
	}
	return 0;
}
