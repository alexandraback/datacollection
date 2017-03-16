#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

double Na[1005];
double Ke[1005];
int tt = 1;
void solve(void)
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++)
		scanf("%lf",&Na[i]);
	for(i=0;i<N;i++)
		scanf("%lf",&Ke[i]);
	sort(Na,Na+N);
	sort(Ke,Ke+N);
	int war = 0;
	int game = 0;
	int np = 0;
	int kp = 0;
	while(np<N&&kp<N)
	{
		if(Ke[kp]>Na[np])
		{
			kp++;
			np++;
			war++;
		}
		else
		{
			kp++;
		}
	}
	war = N-war;
	np = 0;
	int nmp = N-1;
	kp = N-1;
	while(np<=nmp&&kp>=0)
	{
		if(Na[nmp]>Ke[kp])
		{
			nmp--;
			kp--;
			game++;
		}
		else
		{
			np++;
			kp--;
		}
	}
	printf("Case #%d: %d %d\n",tt++,game,war);
}


int main(void)
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}


	return 0;
}
