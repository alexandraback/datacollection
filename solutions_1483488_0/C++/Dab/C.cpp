#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2000000;

bool used[MAXN+5];

vector< vector<int> > v;

void init() {

	memset(used, false, sizeof(used));

	int digits = 1;
	for (int i = 1; i <= MAXN; i++) {
		while(digits <= i) digits *= 10;

		if(used[i]) continue;

		int j = i;
		int shift = 10;


		vector<int> w;
		do {
			j = (digits/shift)*(i%shift) + i/shift;
			shift*=10;

			if(j <= MAXN && 10*j >= digits && !used[j]) {
				used[j] = true;
				w.push_back(j);
			}


		} while(i != j) ;

		v.push_back(w);

	}

}

int solve() {
	int A, B;
	scanf("%d %d", &A, &B);

	int res = 0;
	
	for(int i = 0; i < v.size(); i++) {
		int c = 0;
		for(int j = 0; j < v[i].size(); j++){
			if(A <= v[i][j] && v[i][j] <= B) c++;
		}
		res += (c*(c-1))/2;
	}
	return res;

}

int main() {
	init();

	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) printf("Case #%d: %d\n", i, solve());

}