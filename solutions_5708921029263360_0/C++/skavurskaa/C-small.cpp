#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> Day;
typedef pair<int,int> Par;

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int J,P,S,K;
		scanf("%d %d %d %d", &J, &P, &S, &K);

		srand(time(NULL));
		pair<int,set<Day>> best(0,set<Day>());
		for (int r = 0; r < 10000; r++)
		{
			map<Par,int> C1,C2,C3;
			set<Day> st;
			for (int i = 1; i <= J; i++)
				for (int j = 1; j <= P; j++)
					for (int k = 1; k <= S; k++)
						if (rand()%100>10 && C1[Par(i,j)] < K && C2[Par(i,k)] < K && C3[Par(j,k)] < K)
						{
							st.insert(Day(i,j,k));
							C1[Par(i,j)]++;
							C2[Par(i,k)]++;
							C3[Par(j,k)]++;
						}
			for (int i = 1; i <= J; i++)
				for (int j = 1; j <= P; j++)
					for (int k = 1; k <= S; k++)
						if (st.find(Day(i,j,k)) == st.end() && C1[Par(i,j)] < K && C2[Par(i,k)] < K && C3[Par(j,k)] < K)
						{
							st.insert(Day(i,j,k));
							C1[Par(i,j)]++;
							C2[Par(i,k)]++;
							C3[Par(j,k)]++;
						}
			best = max(best, make_pair((int)st.size(),st));
		}
		printf("Case #%d: %d\n", t, best.first);
		for (auto d : best.second)
		{
			tie(J,P,S) = d;
			printf("%d %d %d\n", J, P, S);
		}
	}
}
