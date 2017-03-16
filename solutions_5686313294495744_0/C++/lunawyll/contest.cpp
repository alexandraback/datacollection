#include <bits/stdc++.h>

using namespace std;


void task();

int main() {
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	 freopen("segmentupdate.in", "r", stdin);
//	 freopen("segmentupdate.out", "w", stdout);
#endif
	task();
#ifdef LUNAWYLL
	//cout << "\n============\n" <<(double)clock()/CLOCKS_PER_SEC;
#endif
	return 0;
}

#ifdef LUNAWYLL
#define dbg(x) cout << #x << " = " << (x) << endl;
#define dbg2(a, b) cout << #a << " = " << (a) << "; "<<\
#b << " = " << (b) << endl;
#define dbg3(a, b, c) cout << #a << " = " << (a) << "; "<<\
		#b << " = " << (b) << "; "<<\
#c << " = " << (c) << endl;
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#endif

typedef long long int llint;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ALL(v) ((v).begin()), ((v).end())

const int N = 3e3 + 10;
const llint MOD = (llint)1e9 + 7;
const int INF = 0x3f3f3f3f;
const llint LINF = (llint)8e18 + 100;
const int BUF_SIZE = (int)1e6 + 10;


void task(){
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i){
		int n;
		cin >> n;
		set <string> alls;
		map<string, set<string> > fwords;
		for (int i = 0; i < n; ++i){
			string s, t;
			cin >> s >> t;
			fwords[s].insert(t);
			alls.insert(t);
		}
		set <string> marked;
		for (auto it = fwords.begin(); it != fwords.end(); ){
			if (it->second.size() == 1){
				marked.insert(*(it->second.begin()));
				auto it2 = it;
				++it;
				fwords.erase(it2);
			} else{
				++it;
			}
		}
		vector<string> v;
		vector<set<string>> vs;
		for (auto x: fwords){
			v.push_back(x.first);
			vs.push_back(x.second);
		}
		vector<int> p(v.size());
		for (int i = 0; i < (int)p.size(); ++i)
			p[i] = i;

		int ans = 0;
		do{
			int tans = 0;
			set<string> marked2;
			for (int i = 0; i < (int)p.size(); ++i){
				int tres = 0;
				for (auto x: vs[p[i]]){
					if (marked.count(x) > 0 || marked2.count(x) > 0)
						++tres;
					marked2.insert(x);
				}
				tans += min(tres, (int)vs[p[i]].size() - 1);
			}
			ans = max(ans, tans);
		} while (next_permutation(ALL(p)));

		printf("Case #%d: %d\n", i + 1, ans);
	}


}

