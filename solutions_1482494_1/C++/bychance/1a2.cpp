#include<iostream>
using namespace std;

#define MAXN 1001
#define INF 0x7fffffff

int T, N;
int a[MAXN], b[MAXN];
bool fa[MAXN], fb[MAXN];
int ans,stars;

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d\n", &T);
	for(int ca=1;ca<=T;++ca)
	{
		scanf("%d",&N);
		for(int i=0;i<N;++i)
		{
			scanf("%d%d",a+i,b+i);
		}

		memset(fa,false,sizeof(fa));
		memset(fb,false,sizeof(fb));

		ans=0;
		stars=0;

		while (true)
		{
			bool finish=true;
			for (int i=0;i<N;++i)
			{
				if(!fa[i]||!fb[i])
				{
					finish =false;
					break;
				}
			}
			if (finish)
			{
				break;
			}
			int besta=INF;
			int besta_second = -1;
			int bestb=INF;
			int bestall=INF;
			int besta_index,bestb_index,bestall_index;

			for(int i=0;i<N;++i)
			{
				if (!fa[i]&&besta>=a[i]&&besta_second<b[i]&&stars>=a[i])
				{
					besta=a[i];
					besta_second=b[i];
					besta_index =i;
				}
				if (!fb[i]&&bestb>b[i]&&stars>=b[i])
				{
					bestb=b[i];
					bestb_index =i;
				}
				if (!fa[i]&&!fb[i]&&bestall>b[i]&&stars>=b[i])
				{
					bestall=b[i];
					bestall_index =i;
				}
			}

			bool play=false;
			if (bestall!=INF)
			{
				fa[bestall_index]=fb[bestall_index]=true;
				stars+=2;
				ans++;
				play = true;
			}
			else if (bestb!=INF)
			{
				fb[bestb_index]=true;
				stars++;
				ans++;
				play = true;
			}
			else if (besta!=INF)
			{
				fa[besta_index]=true;
				stars++;
				ans++;
				play = true;
			}

			if (!play)
			{
				ans=-1;
				break;
			}
		}
		
		printf("Case #%d: ",ca);
		if (ans==-1)
		{
			puts("Too Bad");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}