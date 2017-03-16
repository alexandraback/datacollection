#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		int E, R, N;
		cin >> E >> R >> N;
		vector<int> v(N);
		for(int i = 0; i < N; ++i){ cin >> v[i]; }
		vector<int> s(v);
		sort(s.begin(), s.end(), greater<int>());
		s.erase(unique(s.begin(), s.end()), s.end());
		vector<int> maxe(N + 1, E), mine(N + 1, 0);
		maxe[N] = min(E, R);
		ll answer = 0;
		for(int i = 0; i < s.size(); ++i){
			for(int j = 0; j < N; ++j){
				if(v[j] == s[i]){
					mine[j] = maxe[j];
					ll spent = maxe[j] - max(mine[j + 1] - R, 0);
					answer += spent * v[j];
					maxe[j + 1] = min(max(mine[j + 1], R), E);
				}else if(v[j] < s[i]){
					maxe[j + 1] = min(maxe[j] + R, E);
				}
			}
			for(int j = N - 1; j >= 0; --j){
				if(v[j] < s[i]){ mine[j] = max(mine[j + 1] - R, 0); }
			}
		}
		cout << "Case #" << caseNum << ": " << answer << endl;
	}
	return 0;
}

