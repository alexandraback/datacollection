#define _HAS_CPP0X 0
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)


struct Tribe{
	LL d, n, w, e, s, delta_d, delta_p, delta_s;
	void read(){
		cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
	}
};

struct Wall{
	map<LL, LL> H;
	bool lower(LL a, LL b, LL h){
		a *= 3;
		b *= 3;
		for (LL i = a; i <= b; i++){
			if (H[i] < h){
				return true;
			}
		}
	}
	void set(LL a, LL b, LL h){
		a *= 3;
		b *= 3;
		for (LL i = a; i <= b; i++){
			if (H[i] < h){
				H[i] = h;
			}
		}
	}
};
void Go(){
	int n;
	cin >> n;
	vector<Tribe> tribes(n);
	for (int i = 0; i < n; i++){
		tribes[i].read();
	}
	Wall wall;
	LL res = 0;
	for (;;){
		LL best_d = -1;
		bool has_best = false;
		for (int i = 0; i < n; i++){
			if (tribes[i].n <= 0){
				continue;
			}
			if (!has_best || tribes[i].d < best_d){
				best_d = tribes[i].d;
				has_best = true;
			}
		}
		if (!has_best){
			break;
		}
		vector<int> cc;
		for (int i = 0; i < n; i++){
			if (tribes[i].n <= 0){
				continue;
			}
			if (tribes[i].n > 0 && tribes[i].d == best_d){
				cc.push_back(i);
			}
		}

		for (int i = 0; i < cc.size(); i++){
			Tribe& t = tribes[cc[i]];
			if (wall.lower(t.w, t.e, t.s)){			
				//cout << 'o' << i << ' ' << t.w << ' ' << t.e << ' ' << t.s << endl;
				res++;					
			}
			else{
				//cout << 'f' << i << ' ' << t.w << ' ' << t.e << ' ' << t.s << endl;
			}
		}
		for (int i = 0; i < cc.size(); i++){
			Tribe& t = tribes[cc[i]];
			wall.set(t.w, t.e, t.s);			
		}
		for (int i = 0; i < cc.size(); i++){
			Tribe& t = tribes[cc[i]];			
			t.n--;
			t.d += t.delta_d;
			t.w += t.delta_p;
			t.e += t.delta_p;
			t.s += t.delta_s;			
		}
	}
	cout << res;
}

int main(){
	const string task = "C";
	const string folder = "gcj/2013/1C";
	const int attempt = 1;
	const bool dbg = 0;


	if (dbg){
		freopen("inp.txt", "r", stdin);
	}
	else{
		stringstream ss;
		if (attempt < 0)
			ss << folder << '/' << task << "-large";
		else
			ss << folder << '/' << task << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	FOR(i, t){
		printf("Case #%d: ", i + 1);
		Go();
		printf("\n");
	}
	return 0;
}