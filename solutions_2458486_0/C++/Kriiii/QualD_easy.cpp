#include <stdio.h>
#include <vector>
using namespace std;

vector<int> init,open[22];
int N,M,key[22],have[202]; bool can[1<<20];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test,Case=1;
	int i,j,k,s,x;
	scanf ("%d",&Test); while (Test--){
		printf ("Case #%d:",Case++);
		scanf ("%d %d",&M,&N); init.clear();
		while (M--){
			scanf ("%d",&x); init.push_back(x);
		}
		for (i=0;i<N;i++){
			scanf ("%d %d",key+i,&M); open[i].clear();
			while (M--){
				scanf ("%d",&x); open[i].push_back(x);
			}
		}

		for (s=(1<<N)-1;s>=0;s--){
			for (i=1;i<=200;i++) have[i] = 0;
			for (i=0;i<init.size();i++) have[init[i]]++;
			for (j=0;j<N;j++) if (s & (1 << j)){
				have[key[j]]--;
				for (i=0;i<open[j].size();i++) have[open[j][i]]++;
			}

			can[s] = 0;
			for (i=1;i<=200;i++) if (have[i] < 0) break;
			if (i <= 200) continue;
			if (s == (1<<N)-1){
				can[s] = 1;
				continue;
			}
			for (j=0;j<N;j++) if (have[key[j]] > 0 && (~s & (1 << j)) && can[s+(1<<j)]){
				can[s] = 1;
				break;
			}
		}

		x = 0;
		if (!can[0]) printf (" IMPOSSIBLE");
		else{
			for (i=1;i<=200;i++) have[i] = 0;
			for (i=0;i<init.size();i++) have[init[i]]++;
			for (k=0;k<N;k++){
				for (j=0;j<N;j++) if (have[key[j]] > 0 && (~x & (1 << j)) && can[x+(1<<j)]){
					break;
				}
				have[key[j]]--;
				for (i=0;i<open[j].size();i++) have[open[j][i]]++;
				x += 1 << j;
				printf (" %d",j+1);
			}
		}
		printf ("\n");
	}

	return 0;
}