#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

vector <int > v,ans;
int chk12[100],chk13[100],chk23[100],chk123[1000];
int x[11];
int a,b,c,d;
int res;

void play(int ii,int jj,int kk,int cnt)
{
	if(res < cnt)
	{
		res = cnt;
		ans = v;
	}
	int tmp12 = ii*10+jj,tmp13 = ii*10+kk,tmp23 = jj*10+kk,tmp123 = ii*100+jj*10+kk;
	if(chk12[tmp12] < d && chk13[tmp13] < d && chk23[tmp23] < d && chk123[tmp123] == 0)
	{
		chk12[tmp12]++,chk13[tmp13]++,chk23[tmp23]++,chk123[tmp123] = 1;
		v.push_back(tmp123);
		if(kk == c)
		{
			if(jj == b)
			{
				if(ii != a)
				{
					play(ii+1,1,1,cnt+1);
				}
				else
				{
					if(res < cnt+1)
					{
						res = cnt+1;
						ans = v;
					}
				}
			}
			else
			{
				play(ii,jj+1,1,cnt+1);
			}
		}
		else
			play(ii,jj,kk+1,cnt+1);
        v.pop_back();
		chk12[tmp12]--,chk13[tmp13]--,chk23[tmp23]--,chk123[tmp123] = 0;
	}
	if(kk == c)
	{
		if(jj == b)
		{
			if(ii != a)
			{
				play(ii+1,1,1,cnt);
			}
		}
		else
		{
			play(ii,jj+1,1,cnt);
		}
	}
	else
		play(ii,jj,kk+1,cnt);
}

void solution()
{
    int tmp;
	res = 0;
	memset(chk12,0,sizeof(chk12));
	memset(chk23,0,sizeof(chk23));
	memset(chk13,0,sizeof(chk13));
	memset(chk123,0,sizeof(chk123));
	ans.clear();
	v.clear();
	scanf("%d %d %d %d",&a,&b,&c,&d);
	play(1,1,1,0);
	printf("%d\n",res);
	while(!ans.empty())
    {
        tmp = ans.back();
        printf("%d %d %d\n",tmp/100,(tmp/10) % 10,tmp %10);
        ans.pop_back();
    }
}

int main()
{
	int i,j,t;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solution();
	}
	return 0;
}
