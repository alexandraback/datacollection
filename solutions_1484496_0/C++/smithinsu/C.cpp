#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
void precompute(void)
{
}
//int n,test=0,t,MAXLim=20*101000,i,j,k,bits[2][20*101000],pos[2][20*101000],num[1024],a,b,flag;
int t,flag,n,test,i,i2,j,num[1024],val;
vector < int > bitstr(20*101000);
int main()
{
	precompute();
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			flag=0;
			test++;
			printf("Case #%d: \n",test);
			
//			bitstr.clear();
			for(i=0;i<20*100100;i++)
				bitstr[i]=0;
	//		fprintf(stderr,"Case #%d: started\n",test);
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d",&num[i]);
			}
			for(i=1;i<(1<<n);i++)
			{
				val=0;
				for(j=0;j<n;j++)
				{
					if((i>>j)%2!=0)
					{
						val+=num[j];
					}
				}
			//	printf("%d %d\n",i,val);
				if(bitstr[val]==0)
					bitstr[val]=i;
				else
				{
					i2=bitstr[val];
			//		printf("%d %d %d\n",i,i2,val);
					for(j=0;j<n;j++)
					{
						if((i>>j)%2==1&&(i2>>j)%2!=1)
							printf("%d ",num[j]);
					}
					printf("\n");
					for(j=0;j<n;j++)
					{
						if((i2>>j)%2==1&&(i>>j)%2!=1)
							printf("%d ",num[j]);
					}
					printf("\n");


					flag=1;
					break;
				}
			}

/*			pos[0][0]=1;
			bits[0][0]=1;
			for(i=0;i<n;i++)
			{
				a=i%2;
				b=1-a;
				for(j=0;j<=MAXLim;j++)
				{
					pos[b][j]=0;	
				}
				for(j=0;j<=MAXLim;j++)
				{
					if(pos[a][j]==1)
					{
						if(pos[b][j]==0)
						{
							pos[b][j]++;
							bits[b][j]=bits[a][j];
						}
						else
						{
							flag=1;
							for(k=0;k<n;k++)
							{
								if(bits[b][j]&(1<<k)!=0)
								{
									printf("%d ",num[k]);
								}
							}
							printf("\n");
							for(k=0;k<n;k++)
							{
								if(bits[a][j]&(1<<k)!=0)
								{
									printf("%d ",num[k]);
								}
							}
							printf("\n");

							break;
						}
						if(pos[b][j+num[i]]==0)
						{
							pos[b][j+num[i]]++;
							bits[b][j+num[i]]=bits[a][j]|(1<<i);
						}
						else
						{
							flag=1;
							for(k=0;k<n;k++)
							{
								if(bits[b][j+num[i]]&(1<<k)!=0)
								{
									printf("%d ",num[k]);
								}
							}
							printf("\n");
							for(k=0;k<n;k++)
							{
								if(bits[a][j]&(1<<k)!=0)
								{
									printf("%d ",num[k]);
								}
							}
							printf("\n");
							break;
						}
					}
				}
				if(flag==1)
					break;
			}*/
			if(flag==0)
				printf("Impossible\n");
		}
	}
	return 0;
}
