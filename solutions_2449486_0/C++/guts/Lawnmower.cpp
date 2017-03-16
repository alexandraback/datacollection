#include <iostream>
using namespace std;

#define RT freopen("a.in", "r", stdin)
#define WT freopen("b.out", "w", stdout)
#define MAX 101

int N, M;

struct {
	int Max_R;
	int Max_C;
	int Val;
} Grid[MAX][MAX];

bool isValid() {
	for(int i= 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			if(!(Grid[i][j].Val == Grid[i][j].Max_R || Grid[i][j].Val == Grid[i][j].Max_C))
				return false;
	return true;
}

int main() {
	RT, WT;
	int cases; cin >> cases;
	for(int c = 0; c < cases; ++c) {
		cin >> N >> M;
		for(int i= 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				cin >> Grid[i][j].Val;
		int tmp;
		for(int i = 0; i < N; ++i) {
			tmp = 0;
			for(int j = 0; j < M; ++j) tmp = max(tmp, Grid[i][j].Val);
			for(int j = 0; j < M; ++j) Grid[i][j].Max_R = tmp;
		}
		for(int i = 0; i < M; ++i) {
			tmp = 0;
			for(int j = 0; j < N; ++j) tmp = max(tmp, Grid[j][i].Val);
			for(int j = 0; j < N; ++j) Grid[j][i].Max_C = tmp;
		}
		cout << "Case #" << c + 1 << ": ";
		if(isValid()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}