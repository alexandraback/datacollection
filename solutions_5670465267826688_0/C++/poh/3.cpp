#include<stdio.h>
int t[8][8]={0,1,2,3, 4, 5, 6, 7,       
               1,4,3,6, 5, 0, 7, 2, 						
               2,7,4,1, 6, 3, 0, 5, 						
               3,2,5,4, 7, 6, 1, 0, 						
               4,5,6,7, 0, 1, 2, 3, 						
               5,0,7,2, 1, 4, 3, 6, 						
               6,3,0,5, 2, 7, 4, 1, 						
               7,6,1,0, 3, 2, 5, 4 	
			  },c[8];
int main()
{
	FILE *fp=freopen("input.txt","r",stdin);
	FILE *fp2=freopen("output.txt","w",stdout);
	int i,j,k,n,x,y,z=0,b=0,mul;
	char a[10005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %s",&x,&y,a);
		
			mul=y;
		c[1]=0;c[2]=0;
		for(j=0,k=0,z=0;k<mul*x;j++,k++)
		{
			if(j==x)
				j=0;
			if(a[j]=='i')
				b=1;
			else if(a[j]=='j')
				b=2;
			else if(a[j]=='k')
				b=3;
			z=t[z][b];
			if(z==1)
				c[1]=1;
			else if(z==3&&c[1]==1)
				c[2]=1;
			//printf("%d ",z);
		}
		if(x<=2||z==1||(z==4&&y%2==0))
			printf("Case #%d: NO\n",i+1);
		else if(((z!=1&&z!=4&&y%4==2)||(z==4&&y%2==1))&&c[1]==1&&c[2]==1)
			printf("Case #%d: YES\n",i+1);
		else
			printf("Case #%d: NO\n",i+1);
	}
	scanf(" ");
}

