#include <stdio.h>
#include <vector>

using namespace std;

int Ap[210];
bool D[1 << 21];
int i, test, j, mask;
int N, T, Nr, W;
int A[100];
vector<int> V[100];
int Colour[100];
int Comut[210];

inline void Normal()
{
	W = 0;
	for (int i = 0; i <= 200; ++i)
		if (Ap[i] != 0)
			Comut[i] = ++W;
	for (int i = 1; i <= A[0]; ++i)
		A[i] = Comut[A[i]];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < V[i].size(); ++j)
			V[i][j] = Comut[V[i][j]];
	for (int i = 0; i < N; ++i)
		Colour[i] = Comut[Colour[i]];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d", &T);
	for (test = 1; test <= T; ++test){
		scanf("%d %d", &A[0], &N);
		for (i = 1; i <= A[0]; ++i){
			scanf("%d", &A[i]);
			Ap[A[i]]++;
		}
		for (i = 0; i < N; ++i){
			scanf("%d", &Colour[i]);
			++Ap[Colour[i]];
			scanf("%d", &Nr);
			V[i].resize(Nr);
			for (j = 1; j <= Nr; ++j){
				scanf("%d", &V[i][j - 1]);
				++Ap[V[i][j - 1]];
			}
		}
		
		Normal();
		
		D[0] = true;//1 - inchis...0 - deschis
		for (mask = 1; mask < (1<<N); ++mask){
			D[mask] = false;
			for (j = 1; j <= W; ++j)
				Ap[j] = 0;
			for (j = 1; j <= A[0]; ++j)
				Ap[A[j]]++;
			for (i = 0; i < N; ++i){
				if (mask & (1<<i)) continue;
				Ap[Colour[i]]--;
				for (j = 0; j < V[i].size(); ++j)
					Ap[V[i][j]]++;
			}
			bool Ok = false;
			for (i = 1; i <= W; ++i)
				if (Ap[i] < 0){
					Ok = true;
					break;
				}
			if (Ok) continue;
			
			for (i = 0; i < N; ++i)
				if (mask & (1<<i)){
					if (Ap[Colour[i]] == 0) continue;
					D[mask] |= D[mask - (1 << i)];
				}
		}
		printf("Case #%d: ", test);
		if (D[(1<<N) - 1] == false)
			printf("IMPOSSIBLE\n");
		else{
			mask = (1 << N) - 1;
			for (i = 1; i <= N; ++i){
				for (j = 1; j <= W; ++j)
					Ap[j] = 0;
				for (j = 1; j <= A[0]; ++j)
					Ap[A[j]]++;
				for (j = 0; j < N; ++j){
					if (mask & (1<<j)) continue;
					Ap[Colour[j]]--;
					for (int aux = 0; aux < V[j].size(); ++aux)
						Ap[V[j][aux]]++;
				}
				for (j = 0; j < N; ++j)
					if (mask & (1 << j) && Ap[Colour[j]] && D[mask - (1<<j)]){
						mask -= (1 << j);
						printf("%d ", j + 1);
						break;
					}
			}
			printf("\n");
		}
	}

	return 0;
}