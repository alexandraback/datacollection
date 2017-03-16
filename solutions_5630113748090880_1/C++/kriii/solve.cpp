#include <stdio.h>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N,D[105][55],A[55],V[2][55],S[55],C[105];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		scanf ("%d",&N);
		for (int i=0;i<2*N-1;i++) for (int j=0;j<N;j++) scanf ("%d",&D[i][j]);
		for (int i=0;i<2*N-1;i++) C[i] = 0;
		int cen = -1;
		for (int i=0;i<N;i++){
			int mn = 0x7fffffff;
			for (int j=0;j<2*N-1;j++) if (!C[j] && mn > D[j][i]) mn = D[j][i];
			S[i] = 0;
			for (int j=0;j<2*N-1;j++) if (!C[j] && mn == D[j][i]) V[S[i]++][i] = j, C[j] = 1;
			if (S[i] == 1) cen = i;
		}

		for (int i=0;i<N;i++){
			if (S[i] == 2){
				multiset<int> s;
				s.insert(D[V[0][i]][cen]);
				s.insert(D[V[1][i]][cen]);
				s.erase(s.find(D[V[0][cen]][i]));
				A[i] = *s.begin();
			}
			else{
				A[i] = D[V[0][cen]][i];
			}
		}
		printf ("Case #%d:",Case);
		for (int j=0;j<N;j++) printf (" %d",A[j]); puts("");
	}

	return 0;
}