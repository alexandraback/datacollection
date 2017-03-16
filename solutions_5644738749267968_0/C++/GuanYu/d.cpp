#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1002
using namespace std;

// weights
double w[2][MAXN];
bool used[MAXN];

// Main
int main(void)
{
	int tc,cs,N,i,Nm,NM,Km,KM,cnt,win[2];

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++) scanf("%lf",&w[0][i]);
		for(i=0;i<N;i++) scanf("%lf",&w[1][i]);
		sort(w[0],w[0]+N);
		sort(w[1],w[1]+N);

		// Greedy - D-War
		cnt=0;
		win[0]=0;
		Nm=Km=0,NM=KM=N-1;
		while(cnt<N)
		{
			if(w[0][Nm]<w[1][Km])
			{
				KM--;
				Nm++;
			}
			else
			{
				Nm++;
				Km++;
				win[0]++;
			}
			cnt++;
		}

		// Greedy - War
		cnt=0;
		win[1]=0;
		memset(used,false,N*sizeof(bool));
		while(cnt<N)
		{
			for(i=0;i<N;i++)
			{
				if(!used[i]&&w[1][i]>w[0][cnt])
					break;
			}
			if(i<N) used[i]=true;
			else
			{
				for(i=0;i<N;i++)
					if(!used[i]) break;
				used[i]=true;
				win[1]++;
			}
			cnt++;
		}

		// Output
		printf("Case #%d: %d %d\n",cs,win[0],win[1]);
	}
	return 0;
}