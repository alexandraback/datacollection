#include<stdio.h>

int check(int v,int c,int a[],int d,int e[])
{
	int j;
	if(v==0)
		return 1;
	for(j=0;j<d;j++)
	{
		if(e[j]!=0)
		{
			e[j]--;
			if(check(v-a[j],c,a,d,e))
			{
				e[j]++;
				return 1;
			}
			e[j]++;
		}
	}
	return 0;
}

int main()
{
	FILE *fp1,*fp2;
	int i,t,d,c,v,j,ans;
	int e[100],a[100];
	
	fp1=freopen("C-small-attempt0.in","r",stdin);
	fp2=freopen("ab.txt","w+",stdout);
	
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&c,&d,&v);
		ans=0;
		for(j=0;j<d;j++)
		{
			scanf("%d",a+j);
			e[j]=c;
		}
		
		//printf("%d",check(4,c,a,d,e));
		for(j=1;j<=v;j++)
			if(check(j,c,a,d,e)!=1)
			{
				ans++;
				//printf("%d",j);
				a[d++]=j;
				e[d-1]=c;
			}
			
			
		printf("Case #%d: %d\n",i+1,ans);
	}
	fclose(fp1);
	fclose(fp2);
}
