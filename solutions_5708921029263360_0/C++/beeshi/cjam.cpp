#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define D(x...) fprintf(stderr,x) 
#else
#define D(x...) 
#endif 
int T, N, ans;
int main()
{
	freopen("infile.txt", "r", stdin);
	freopen("outfile.txt", "w", stdout);
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		vector<int> A[3];
		int U[20][20];
		int J, P, S, K;
		scanf("%d %d %d %d", &J, &P, &S, &K);
		for(int p=1; p<=P; p++)
		{
			for(int s=1; s<=S; s++)
			{
				U[p][s]=0;
			}
		}
		int s=1;
		for(int j=1; j<=J; j++)
		{
			int used[20];
			for(int s=1; s<=S; s++)
			{
				used[s]=0;
			}
			for(int p=1; p<=P; p++)
			{
				for(int k=0; k<min(K, S); k++)
				{
					while(true)
					{
						if(used[s]<K && U[p][s]<K)
						{
							used[s]++;
							A[0].push_back(j);
							A[1].push_back(p);
							A[2].push_back(s);
							U[p][s]++;
							s++;
							if(s>S)
							{
								s=1;
							}
							break;
						}
						s++;
						if(s>S)
						{
							s=1;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", t, A[0].size());
		if(A[0].size()!= J*P *min(S, K)) D("RIP %d\n", t);
		for(int a=0; a<A[0].size(); a++)
		{
			printf("%d %d %d\n",A[0][a], A[1][a], A[2][a]);
		}
	}
}