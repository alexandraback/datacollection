#include<stdio.h>
#include<queue>
#include<memory.h>
#include<vector>
#include<set>
using namespace std;
int small[1001];
int large[1001];
bool was1[1001];
bool was2[1001];
int main()
{
	freopen("D:\\gcj\\B-large.in","r",stdin);
	freopen("D:\\gcj\\B-large.out","w",stdout);
	int tests;
	scanf("%d",&tests);
	for(int test=0;test<tests;test++)
	{
		int N;
		scanf("%d",&N);
		int A,B;
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&A,&B);
			small[i]=A;
			large[i]=B;
		}
		memset(was1,0,sizeof(was1));
		memset(was2,0,sizeof(was2));
		int curstars=0;
	    bool found=false;
		int steps=0;
		int uses=0;
		for(int i=0;i<2*N+5;i++)
		{
			found=false;
			//use all 2-lvl
			for(int j=0;j<N;j++)
			{
				if(!was2[j] && large[j]<=curstars)
				{
					was2[j]=true;
					curstars+=2;
					if(was1[j])curstars--;
					found=true;
					++steps;
					++uses;
					if(uses==N)break;
				}
				
			}
			if(uses==N)break;
			if(!found)
			{
				int touse=-1;
				int curmax=-1;
				for(int j=0;j<N;j++)
				{
					if(!was2[j] && !was1[j] && small[j]<=curstars)
					{
						if(large[j]>curmax)
						{
							curmax=large[j];
							touse=j;
						}
					}
				}
				if(touse!=-1)
				{
					was1[touse]=true;
					++curstars;
					++steps;
				}
			}
		}
		bool checked=true;
		for(int i=0;i<N;i++)
		{
			if(!was2[i])checked=false;
		}
		if(!checked)
		{
			printf("Case #%d: Too Bad\n",test+1);
		}
		else
		{
			printf("Case #%d: %d\n",test+1,steps);
		}
	}
}