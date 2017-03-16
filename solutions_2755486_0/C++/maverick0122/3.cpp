#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

const int N=5010;
const int add=2000;
/*
typedef struct 
{
	int d, n, w, e, s, delta_d, delta_p, delta_s;
}tribe;*/

typedef struct
{
	int d,st,en,h;
}attack;

//tribe tb[20];
int w[N],rec[110][3];
attack att[110];
int n;

int cmp(const void *a, const void *b)
{
	return ((attack*)a)->d - ((attack*)b)->d;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		scanf("%d",&n);
		int i,j,ai=0;
		for(i=0;i<n;i++)
		{
			int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
			//scanf("%d%d%d%d%d%d%d%d",&tb[i].d,&tb[i].n,&tb[i].w,&tb[i],e,&tb[i].s,&tb[i].delta_d,&tb[i].delta_p,&tb[i].delta_s);
			scanf("%d%d%d%d%d%d%d%d",&di,&ni,&wi,&ei,&si,&delta_di,&delta_pi,&delta_si);
			for(j=0;j<ni;j++)
			{
				att[ai].d = di + j*delta_di;
				att[ai].st = wi + j*delta_pi;
				att[ai].en = ei + j*delta_pi;
				att[ai].h = si + j*delta_si;
				ai++;
			}
		}
		qsort(att,ai,sizeof(attack),cmp);
		memset(w,0,sizeof(w));
		int ans=0;
		int pred=att[0].d;
		int reccnt = 0;
		for(i=0;i<ai;)
		{
			if(att[i].d==pred)
			{
				for(j=att[i].st;j<att[i].en;j++)
				{
					if(w[add+j]<att[i].h)
					{
						ans++;
						rec[reccnt][0]=att[i].st;
						rec[reccnt][1]=att[i].en;
						rec[reccnt][2]=att[i].h;
						reccnt++;
						break;
					}
				}
				i++;
			}
			else
			{
				for(j=0;j<reccnt;j++)
				{
					for(int k=rec[j][0];k<rec[j][1];k++)
					{
						if(w[add+k]<rec[j][2])
						{
							w[add+k] = rec[j][2];
						}
					}
				}
				pred = att[i].d;
				reccnt = 0;
			}
		}
		
		printf("Case #%d: %d\n",cnt,ans);
	} 
} 
