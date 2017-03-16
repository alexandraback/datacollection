#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V;
vector<int> K;

int A;

int result(int N)
{
	if(A == 1)
		return N;
	int best = N;
	int a = A, k, added = 0;
	for(int i=0; i<V.size(); i++)
	{
		for(k = 0; a <= V[i] && added+k <= N; k++)
			a += (a-1);
		//printf("--->%d\n", k);
		added += k;
		a += V[i];
		if(added > N)
			return best;
		best = (best < added+V.size()-i-1)?(best):(added+V.size()-i-1);
	}
	return best;
}

int main()
{
	int T, N, a;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		scanf("%d %d", &A, &N);
		for(int i=0; i<N; i++) {
			scanf("%d", &a);
			V.push_back(a);
		}
		sort(V.begin(), V.end());
		printf("Case #%d: %d\n", t, result(N));
		V.clear();
	}
	return 0;
}
