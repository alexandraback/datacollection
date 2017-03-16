#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<int> vi;
const int MAXN = 64, MAXL = 1000010;

int n;
vi lista[MAXN*2];
int mat[MAXN][MAXN];

int jumped, row;
bool solve(int a, int b, int l);

bool cmp(vi a, vi b) {
	for(int i=0; i<n; i++) {
		if(a[i] < b[i]) return true;
		else if(a[i] > b[i]) return false;
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("B-small-attempt1.in", "r", stdin);
	//freopen("output-small.txt", "w", stdout); 

	int t;
	scanf("%d", &t);

	for(int test=1; test<=t; test++) {
		printf("Case #%d:", test);

		scanf("%d", &n);
		for(int i=0; i<n*2-1; i++) {
			lista[i].clear();
			//printf("clear %d\n", i);

			for(int j=0; j<n; j++) {
				int aux;
				scanf("%d", &aux);

				lista[i].push_back(aux);
			}
		}
		sort(lista, lista+n*2-1, cmp);
		//printf("sorteado\n");

		//for(int i=0; i<n*2-1; i++) for(int j=0; j<n; j++) printf("%d%c", lista[i][j], j == n-1 ? '\n' : ' ');

		//printf("%d\n", n);
		bool solved = false;
		for(int i=0; !solved and i<n; i++) {
			//printf("%d trying %d\n", n, i);
			jumped = i;
			row = true;
			solved = solve(0, 0, 0);
			if(solved) break;

			row = false;
			solved = solve(0, 0, 0);
		}
	}
}

bool solve(int a, int b, int l) {
	if(row == true and a == jumped) return solve(a+1, b, l);
	if(row == false and b == jumped) return solve(a, b+1, l);

	//printf("%d %d\n", a, b);
	if(a == n and b == n) {
		for(int i=0; i<n; i++) {
			printf(" %d", row == true ? mat[jumped][i] : mat[i][jumped]);
		}
		printf("\n");
		return true;
	}

	if(a < n) {
		int i;
		for(i=0; i<n; i++) {
			if(i < b and row == false and jumped == i) {
			} else if(i < b and lista[l][i] != mat[a][i]) {
				break;
			}

			mat[a][i] = lista[l][i];
		}
		if(i == n and solve(a+1, b, l+1)) return true;
	}
	if(b < n) {
		int i;
		for(i=0; i<n; i++) {
			if(i < a and row == true and jumped == i) {
			} else if(i < a and lista[l][i] != mat[i][b]) {
				break;
			}

			mat[i][b] = lista[l][i];
		}
		if(i == n and solve(a, b+1, l+1)) return true;
	}
	return false;
}
