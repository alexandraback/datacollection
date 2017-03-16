#include "stdio.h"
#include "algorithm"
#include "vector"

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,n,m,k;
		scanf("%d",&r);
		scanf("%d",&n);
		scanf("%d",&m);
		scanf("%d",&k);
		printf("Case #1:\n");
		while(r--)
		{
			int count2=0,count3=0,count4=0,count5=0,count9=0,count25=0,count27=0,count125=0;
			int count8=0,count16=0,count32=0,count64=0;
			int num[7];
			int out[3];
			for (int i = 0; i < k; ++i)
			{
				scanf("%d",&(num[i]));
				if(num[i]%2==0) count2++;
				if(num[i]%3==0) count3++;
				if(num[i]%4==0) count4++;
				if(num[i]%5==0) count5++;
				if(num[i]%25==0) count25++;
				if(num[i]%9==0) count9++;
				if(num[i]%27==0) count27++;
				if(num[i]%125==0) count125++;
				if(num[i]%8==0) count8++;
				if(num[i]%16==0) count16++;
				if(num[i]%32==0) count32++;
				if(num[i]%64==0) count64++;
			}
			int numcount=0;
			if(count5>0)
			{
				out[numcount]=5;
				numcount++;
				if(count25>0){
				out[numcount]=5;
				numcount++;}
				if(count125>0){
				out[numcount]=5;
				numcount++;}
			}
			if(count3>0)
			{
				out[numcount]=3;
				numcount++;
				if(count9>0){
				out[numcount]=3;
				numcount++;}
				if(count27>0){
				out[numcount]=3;
				numcount++;}
			}
			//if(count4>0)
			
				if(count64>0)
				{
					out[numcount]=4;
					numcount++;
					out[numcount]=4;
					numcount++;
					out[numcount]=4;
					numcount++;
				}
				else if(count32>0)
				{
					out[numcount]=2;
					numcount++;
					out[numcount]=4;
					numcount++;
					out[numcount]=4;
					numcount++;
				}
				else
				{
					if(count16>0)
					{
						if(numcount==0)
						{
							out[numcount]=4;
						numcount++;
						out[numcount]=2;
						numcount++;
						out[numcount]=2;
						numcount++;
						}
						else
						{
							out[numcount]=4;
						numcount++;
						out[numcount]=4;
						numcount++;
						}
					}
					else if(count8>0)
					{
						if(numcount==0)
						{
							out[numcount]=2;
						numcount++;
						out[numcount]=2;
						numcount++;
						out[numcount]=2;
						numcount++;
						}
						else
						{
							out[numcount]=2;
						numcount++;
						out[numcount]=4;
						numcount++;
						}
					}
					else if(count4>0)
					{
						if(numcount==1)
						{
						out[numcount]=2;
						numcount++;
						out[numcount]=2;
						numcount++;
						}
						else
						{
						out[numcount]=4;
						numcount++;						
						}
					}
					else if(count2>0)
					{
						out[numcount]=2;
						numcount++;	
					}
				}
			while(numcount<3)
			{
				out[numcount]=2;
				numcount++;	
			}
			printf("%d%d%d\n",out[0],out[1],out[2] );
		}
	}
	return 0;
}