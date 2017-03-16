#include<cstdio>
using namespace std;
char ar[51][51];
int main()
{
	int ntc;
	int flag;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{  flag=0;
		printf("Case #%d:\n",tc);
		for(int i=1;i<51;i++)
		for(int j=1;j<51;j++)
		ar[i][j]='.';
		int r,c,m;
		scanf("%d",&r);scanf("%d",&c);scanf("%d",&m);
		if(r<c)
		{
			flag=1;
			int t=r;r=c;c=t;
		}
		ar[r][c]='c';
		if(c==1)
		{  
			
			    int i=1;
				while(m--)
				{
					ar[i][c]='*';
				}
			
		}
		
		else if(c==2)
		{ int temp=r*c - m;
			if(temp==2||(temp!=1&& temp%2==1))
			{printf("Impossible\n"); continue;}
		
		      for(int i=1;(i<=r) && m;i++)
		      for(int j=1;(j<=c)&&m;j++)
		      { 
		      	m--;ar[i][j]='*';
		      }
		
			
		}
		else
		{
			for(int i=1;(i<=r-2)&& m;i++)
			for(int j=1;(j<=c-2)&& m;j++)
			{   m--;
				ar[i][j]='*';
			}
			if(m >= 2*(r-3))
			{
			
			  for(int i=1;(i<=r-3)&&(m>1);i++)
			{
				ar[i][c-1]='*';ar[i][c]='*'; m=m-2;
				
			}  
			if(m >= 2*(c-3))
				{
				
			for(int i=1;(i<=c-3)&&(m>1);i++)
			{    
				ar[r-1][i]='*';ar[r][i]='*'; m=m-2;
				
			}   
			if(m==1||m==3||m==5||m==6) 
					{
						printf("Impossible\n"); continue;
					}
					if(m>=2) 
					{
						ar[r-2][c-1]='*';ar[r-2][c]='*';m=m-2;
					}
					if(m>=2) 
					{
						ar[r-1][c-2]='*';ar[r][c-2]='*';m=m-2;
					}
					if(m==3)
					{
						ar[r-1][c-1]='*';ar[r-1][c]='*';ar[r][c-1]='*';
					}
				}
				else 
				{  
					if(m%2==1) 
				{ m++;ar[r-2][c-2]='.';
				}
				for(int i=1;(i<=c-3)&&m;i++)
			{
				ar[r-1][i]='*';ar[r][i]='*'; m=m-2;
			}
				}
	 	   }
			else
			{
				
				if(m%2==1) 
				{ m++;ar[r-2][c-2]='.';
				}
				for(int i=1;(i<=r-3)&&m;i++)
			{
				ar[i][c-1]='*';ar[i][c]='*'; m=m-2;
			}
			}
		}
		if(flag==0)
		{
			for(int i=1;i<=r;i++)
			{
			
			for(int j=1;j<=c;j++)
			printf("%c",ar[i][j]);
			printf("\n");
		   }
		}
		else
		{
			for(int i=1;i<=c;i++)
			{
			
			for(int j=1;j<=r;j++)
			printf("%c",ar[j][i]);
			printf("\n");
		   }
		}		
	}
	
}
