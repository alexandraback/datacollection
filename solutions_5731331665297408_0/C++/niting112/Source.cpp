#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	int N, M;
	for(int t = 1; t <= T; ++t){
		cin >> N >> M;
		vector<string> v;
		for(int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			v.push_back(s);
		}

		for(int i = 0; i < M; ++i) {
			int X, Y;
			cin >> X >> Y;
		}

		vector<int> tt;
		for(int i = 0; i < N; ++i) {
			tt.push_back(i);
		}

		string ans(N+1, 'Z');
		do{
			string s;
			for(int i = 0; i < tt.size(); ++i){
				s += v[tt[i]];
			}
			ans = min(ans, s);
		}while(next_permutation(tt.begin(), tt.end()));
		cout << "Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}