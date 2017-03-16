#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#define P(x,y) make_pair(x,y)
using namespace std;

map<pair<int, int>, int> mp1, mp2, mp3;
int main() {

	freopen("c2.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int T;
	cin >> T;
	for (int cas = 1;cas <= T;++cas) {
		printf("Case #%d: ", cas);
		mp1.clear();
		mp2.clear();
		mp3.clear();
		vector<pair< pair<int, int>, int > > sol;
		int N, M, K;
		cin >> N >> M >> K;
		int lim;
		cin >> lim;
		
			
				for (int k = 1;k <= K;++k)
					for (int j = 1;j <= M;++j)
					for (int i = 1;i <= N;++i){
					if (mp1[P(i, j)] < lim && mp2[P(i, k)] < lim && mp3[P(j, k)] < lim) {
						mp1[P(i, j)]++;mp2[P(i, k)]++;mp3[P(j, k)]++;
						sol.push_back(P(P(i, j), k));
					}
				}
		cout << sol.size() << endl;
		for (int i = 0;i < sol.size();++i) {
			cout << sol[i].first.first << " " << sol[i].first.second << " " << sol[i].second << endl;
		}
	}
}