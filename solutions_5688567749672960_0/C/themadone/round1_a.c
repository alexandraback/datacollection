#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long long ull_t;

ull_t flip(ull_t in)
	{
	ull_t out;
	char temp[20];
	char temp2[20];
	int len;
	int i;
	
	sprintf(temp,"%lld",in);
	len=strlen(temp);
	for(i=0;i<len;i++)
		{
		temp2[len-i-1]=temp[i];
		}
	temp2[len]='\0';
	sscanf(temp2,"%lld\n",&out);
	return(out);
	}

int main(int argc,char *argv[])
	{
	int tests;
	int casenum;
	ull_t target;
	ull_t count;
	ull_t curr,flipped;
	ull_t i; 

	fscanf(stdin,"%d\n",&tests);
	for(casenum=1;casenum<=tests;casenum++)
		{
		fscanf(stdin,"%lld\n",&target);
		if(target<=19)
			{
			count=target;
			}
		else
			{
			count=11;
			curr=11;
//			fprintf(stderr,"-1-%lld %lld\n",curr,count);
			while(curr<target)
				{
				if(target-curr<10)
					{
					count += target-curr;
//					fprintf(stderr,"-2-%lld %lld\n",target,count);
					break;
					}
				for(i=9-(curr % 10);i>0;i--)
					{
					flipped=flip(curr+i);
					if((flipped<=target)&&((curr+i)!=flipped)&&(flipped>(curr+1)))
						{
//						fprintf(stderr,"-3-%lld %lld\n",curr+i,count+i);
						count += i+1;
						curr=flipped;
//						fprintf(stderr,"-3-%lld %lld %lld\n",curr,count,flipped);
						break;
						}
					}
				if(i==0)
					{
					count += 10-(curr % 10);
					curr += 10-(curr % 10);
//					fprintf(stderr,"-4-%lld %lld\n",curr,count);
					}
				}
			}
		
		printf("Case #%d: %lld\n",casenum,count);
		}
	}
