#include<stdio.h>
int inp[1000];


int main()
{
	int test,i,n,s,p,i2,acc;
	int temp,mod;
	scanf("%d",&test);
	for(i=1;i<=test;i++)
	{
		acc=0;
		scanf("%d %d %d",&n,&s,&p);
		for(i2=0;i2<n;i2++)
		{
		    scanf("%d",&temp);
		    if(temp==0&&p>0)
		     continue;
		    if(temp/3>=p)
		     acc++;
		    else
		    {
		    	mod=temp%3;
		    	if(mod==1&&mod+temp/3>=p)
		    	    acc++;
		    	else if(mod==2)
		    	{
		    		if(temp/3+1>=p)
		    		   acc++;
		    		else if(temp/3+2>=p and s>0)
		    		{
		    		   s--;
		    		   acc++;
		    		}
		    	}
		    
		    	else if(mod==0)
		    	{
		    		if(temp/3+1>=p && s>0 )
		    		{
		    			s--;
		    			acc++;
		    		}		    		
		   		}
		    }
		}
		printf("Case #%d: %d\n",i,acc);
	}
	return 0;

}
