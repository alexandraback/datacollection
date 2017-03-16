#include <iostream>
using namespace std;

int DP[105][105];
int t[105];
int N, S, p;

int max_sup(int tot) {
	if (tot < 2)
		return -1; /* can't be surprising */
	return (tot+4)/3;
}

int max_non_sup(int tot) {
	if (tot == 0)
		return 0;
	return (tot+2)/3;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
			cin >> N >> S >> p;
			for (int i = 1; i <= N; i++)
				cin >> t[i];
				
			/* DP[i][s] is maximum number of dudes among {1,...,i} with scores at least p s.t. there are exactly 's' suprising results.
			 * If no such set up exists (for example, 1 guy with score 1 CANNOT have a surprising result), DP[i][s] is -1
			 * The condition "There will be at least S total points between 2 and 28, inclusive." ensures there will be a 
			 * solution in the end, though.
			 */
			
			for (int s = 0; s <= S; s++)
				DP[1][s] = -1; /* assume impossible */
				
			if (max_non_sup(t[1]) >= p) /* any value of t[i] can be from a non-surprising result */
				DP[1][0] = 1;
			else
				DP[1][0] = 0;
				
			if (t[1] < 2)
				DP[1][1] = -1; /* impossible because he must have non-surprising score */
			else if (max_sup(t[1]) >= p)
				DP[1][1] = 1;
			else
				DP[1][1] = 0;

			for (int i = 2; i <= N; i++)
			{
				for (int s = 0; s <= S; s++)
					DP[i][s] = DP[i-1][s]; /* lower bound, if this is a non-suprising result thats smaller than p */
				
				/* what if t[i] is a non-surprising result? can we beat the bound by one? */
				if (max_non_sup(t[i]) >= p)
					for (int s = 0; s <= S; s++)
						if (DP[i-1][s] != -1)
							DP[i][s]++;
				
				/* now what if t[i] is a actually a surprising result? can we beat the above result? */
				if (t[i] < 2)
					continue; /* can't be surprising */
					
				for (int s = 0; s <= S; s++)
					DP[i][s] = max(DP[i][s], DP[i-1][s-1]); /* either got from above or prev iteration */
				
				if (max_sup(t[i]) >= p)
					for (int s = 1; s <= S; s++)
						if (DP[i-1][s-1] != -1 && DP[i][s] == DP[i-1][s-1])
							DP[i][s]++;
			}
			
			int res = DP[N][S];
			cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
