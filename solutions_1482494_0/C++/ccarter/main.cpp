#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int star[1010];
struct level{
	int a;
	int b;
	bool inline friend operator < (level x,level y)
	{
		if (x.b<y.b) return 1;
		else return 0;
	}
} need[1010];

int main()
{
    int tt;
    scanf("%d",&tt);
    for (int ttt=1;ttt<=tt;ttt++)
    {
    	int n;
    	memset(need,0,sizeof(need));
    	memset(star,0,sizeof(star));
    	scanf("%d",&n);
    	for (int i=0;i<n;i++)
    	{
			scanf("%d %d",&(need[i].a),&(need[i].b));
    	}
    	int badflag =0 ;
    	sort(need,need+n);
		int cnt = 0;
		int complete = 0;
		int myst=0;
		while (complete < n)
		{
			badflag = 1;
			for (int i=n-1;i>=0;i--)
			{
				if (star[i]!=2 && need[i].b<=myst)
				{
					cnt++;
					complete++;
					myst+=2-star[i];
					star[i]=2;

					badflag = 0;
					//printf("%d %d====\n",need[i].a,need[i].b);
					break;
				}
			}
			if (badflag)
			{
				for (int i=n-1;i>=0;i--)
				{
					if (star[i]<1 && need[i].a<=myst)
					{
						cnt++;
						star[i]=1;
						myst++;
						badflag =0 ;
						//printf("%d %d===!\n",need[i].a,need[i].b);
						break;
					}
				}
			}
			if (badflag)
			{
				printf("Case #%d: Too Bad\n",ttt);
				break;
			}
		}
		if (!badflag)
		{
			printf("Case #%d: %d\n",ttt,cnt);
		}

    }
    return 0;
}
