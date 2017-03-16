#include<stdio.h>
#include<math.h>

char a[200],b[200],d[200];
int c[200];

int main()
{
	FILE *fp1,*fp2;
	int i,t,l,k,s,j,p,m,count;
	float ans;
	
	fp1=freopen("B-small-attempt2.in","r",stdin);
	fp2=freopen("e.txt","w+",stdout);
	
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&k,&l,&s);
		ans=1;
		
		scanf("%s",a);
		scanf("%s",b);
		
		for(j=0;j<102;j++)
		{
			c[j]=0;
			d[j]=0;
		}
		
		for(j=0;j<k;j++)
			for(p=0;p<l;p++)
				if(a[j]==b[p])
					c[p]++;
					
		for(p=0;p<l;p++)
		{
		
			ans*=c[p];
		}
		p=0;
		count=0;
		
		for(j=0;j<s;j++)
		{
			d[j]=b[p++];
			if(p>=l)
				p=0;
		}
		d[j]='\0';
		//printf("%s",d);
		p=0;
		
		for(j=0;j<s;j++)
			if(d[j]==b[p])
			{
				p++;
				for(m=j+1;m<j+l && m<s;m++)
					if(d[m]!=b[p++])
					{
						p=0;
						break;
					}
					
				if(p && (m-j)==l)
					count++;
					
				p=0;
			}
			
		for(j=0;j<l;j++)
			if(c[j]==0)
				count=0;
		
			
		//printf("%d",count);	
		
		
		ans=count*ans;
			
		ans=ans/(pow(k,l));
		ans=count-ans;
			
		printf("Case #%d: %f\n",i+1,ans);
	}
	fclose(fp1);
	fclose(fp2);
}
