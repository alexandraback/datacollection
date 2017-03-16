#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int T;
int E,R,N;
int v[10010];
long long P,tmp;
int z,z1;
long long queue[20000001][2];
long long queue1[20000001][2];
bool valid[20000001];
int ttt;

int main()
{
	freopen("B-large.in","r",stdin);
	//freopen("out_bl.txt","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d %d %d",&E,&R,&N);
		for(int j=1;j<=N;j++)
			scanf("%d",v+j);
		P=0;
		if(E<=R)
		{
			tmp=0;
			for(int j=1;j<=N;j++)
				tmp+=v[j];
			P=E*tmp;
		}
		else
		{
			z1=1;
			queue[1][0]=E;queue[1][1]=0;
			for(int j=1;j<=N;j++)
			{
				z=0;
				for(int now=1;now<=z1;now++)
				{
					for(int k=queue[now][0];k>=0;k-=R)
					{
						z++;
						queue1[z][0]=R+queue[now][0]-k;
						queue1[z][1]=queue[now][1]+k*v[j];
						if(queue1[z][0]>E)
						{
							queue1[z][1]+=(queue1[z][0]-E)*v[j];
							queue1[z][0]=E;
							break;
						}
					}		
				}
				memset(valid,0,sizeof(valid));
				for(int k=1;k<=z;k++)
				{
					if(valid[k]) continue;
					for(int l=k+1;l<=z;l++)
					{
						if(valid[l]) continue;
						if(queue1[k][0]>=queue1[l][0] && queue1[k][1]>=queue1[l][1]) valid[l]=1;
					}
				}
				z1=0;
				for(int k=1;k<=z;k++)
				{
					if(!valid[k])
					{
						z1++;
						queue[z1][0]=queue1[k][0];
						queue[z1][1]=queue1[k][1];
					}
				}
			}
			P=0;
			for(int j=1;j<=z1;j++)
			if(queue[j][1]>P) P=queue[j][1];
		}
		printf("Case #%d: %I64d\n",i,P);
	}
	return 0;
}
