#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  

int max(int a, int b)
{ 
	if (a>b) return a;
	else return b;
}

int min(int a, int b)
{
	if (a<b) return a;
	else return b;
}


int main() { 
	
	int T,i; 
	scanf("%d",&T);
	int N,X,Y;
	
	int demanded[100000];
	demanded[0]=1;
	//while (demanded[pos]<1000000)
	for (i=1;i<=1000000;i++)
	{
	//	pos++;
		demanded[i]=demanded[i-1]+2*i+2*i+1;
	}
	
	long long fact[3501];
	fact[0]=1;
	for (i=1;i<=3500;i++)
		fact[i]=fact[i-1]*i;
	//for (i=0;i<=100;i++) printf("%lld ", fact[i]);
	
	double result;
	
	for (i=1; i<=T; i++)
	{
		scanf("%d",&N);
		scanf("%d",&X);
		scanf("%d",&Y);
        if (X<0) X=-X;
        if ((X==0)&&(Y==0))
			result=1.0;
		else
		{
			if (N<=demanded[((X+Y)/2)-1])		
				result=0.0;		//de ftanoun na kalufthoun ta endiamesa
			else 
			{
				long long total=0; long long good=0;
				int left=N-demanded[((X+Y)/2)-1];
				if (Y+1>left) result=0.0;	 //de ftanoun 
				else if (left>(X+Y)+Y) result=1.0; //ftanoun sigoura
				else 
				{
					int start=max(left-(X+Y), 0);
					int end=min(left, X+Y);
					
					
					
					while (start<=end)
					{
						total=total+fact[left]/(fact[start]*fact[left-start]);
						if (start>=Y+1) good=good+fact[left]/(fact[start]*fact[left-start]);
						start++;
					}
					result=(double)good/(double)total;
				}
				
			}
		}
		printf("Case #%d: %f\n",i,result);
	}
	return 0;
}