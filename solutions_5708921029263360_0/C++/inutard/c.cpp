#include <bits/stdtr1c++.h>

using namespace std;

int m[11][11][11];
int jp[11][11], ps[11][11], js[11][11];
int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    //for (int ca = 1; ca <= t; ca++) {
    //    cout << "Case #" << ca << ": ";
		
		int J, P, S, K; //cin >> J >> P >> S >> K;
	for (S = 1; S <= 3; S++) 
	for (P = 1; P <= S; P++)
	for (J = 1; J <= P; J++)
	for (K = 1; K <= 10; K++) {
		// best case: 1000 days.
		
		vector<tuple<int, int, int>> best, curr;
		vector<tuple<int, int, int>> tups;
		for (int i = 0; i < J; i++) {
			for (int j = 0; j < P; j++) {
				for (int k = 0; k < S; k++) {
					tups.push_back(tuple<int,int,int>{i, j, k});
				}
			}
		}
		
		for (int bs = 0; bs < (1<<(J*P*S)); bs++) {
			curr.clear();
			memset(m, 0, sizeof m);
			memset(jp, 0, sizeof jp);
			memset(js, 0, sizeof js);
			memset(ps, 0, sizeof ps);
			for (int i = 0; i < J*P*S; i++) {
				if ((1<<i) & bs) {
					int a = get<0>(tups[i]), b = get<1>(tups[i]), c = get<2>(tups[i]);
					if (m[a][b][c] || 
						jp[a][b] >= K || ps[b][c] >= K || js[a][c] >= K) {
						break;
					}
					
					m[a][b][c] = 1;
					jp[a][b]++;
					ps[b][c]++;
					js[a][c]++;
					curr.push_back(tuple<int,int,int>{a+1,b+1,c+1});
				}
			}
			
			if (curr.size() > best.size()) best = curr;
		}
		
		cout << J << " " << P << " " << S << " " << K << endl;
		cout << best.size() << "\\n";
		for (auto p : best) {
			cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << "\\n";
		}
		cout << endl;
	}
	return 0;
}