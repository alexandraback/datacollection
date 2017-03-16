#include <bits/stdc++.h>

#define i64 long long
#define u64 unsigned long long
#define i32 int
#define u32 unsigned int

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;
struct o{
	int j, p, s;
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int tests; cin >> tests;
	for(int test = 1; test <= tests; test++){
		int j, p, s, k; cin >> j >> p >> s >> k;
		vector<o> os;
		for(int i = 1; i <= j; i++){
			for(int j = 1; j <= p; j++){
				for(int k = 1; k <= s; k++){
					o ot;
					ot.j = i;
					ot.p = j;
					ot.s = k;
					os.push_back(ot);
				}
			}
		}
		vector<o> be;
		int cc = 10000;
		while(cc--){
			random_shuffle(os.begin(), os.end());
			int jp[11][11] = {0}, js[11][11] = {0}, ps[11][11] = {0};
			vector<o> ans;
			for(int i = 0; i < os.size(); i++){
				o cu = os[i];
				if(jp[cu.j][cu.p] < k && js[cu.j][cu.s] < k && ps[cu.p][cu.s] < k){
					jp[cu.j][cu.p]++;
					js[cu.j][cu.s]++;
					ps[cu.p][cu.s]++;
					ans.push_back(cu);
				}
			}
			if(ans.size() > be.size())
				be = ans;
		}
		cout << "Case #" << test << ": "<< be.size() << endl;
		for(auto f: be)
			cout << f.j << " " << f.p << " " << f.s << endl;

	}
	return 0;
}