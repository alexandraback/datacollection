#include <bits/extc++.h>
#include <iostream>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif
#define WRITE(x) DEBUG { cout << (x) << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << (x) << endl; }
//#define ALL(x) (x).begin(), (x).end()
//#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); ++i)
//#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

int warScore(const vector<double>& she, const vector<double>& he){
	set<double> q;
	for(const auto& x : he) q.insert(x);
	int score = 0;
	for(const auto& x : she){
		const auto it = q.upper_bound(x);
		if(it == q.end()){
			q.erase(q.begin());
			score++;
		}else{
			q.erase(it);
		}
	}
	return score;
}

int deceitfulWarScore(const vector<double>& she, const vector<double>& he){
	int next = 0;
	int score = 0;
	for(const auto x : she){
		if(x > he[next]){
			next++;
			score++;
		}
	}
	return score;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ntc;
	cin >> ntc;
	for(int tc = 0; tc < ntc; tc++){
		int n;
		cin >> n;
		vector<double> she(n);
		for(int i = 0; i < n; i++) cin >> she[i];
		vector<double> he(n);
		for(int i = 0; i < n; i++) cin >> he[i];
		
		sort(she.begin(), she.end());
		sort(he.begin(), he.end());

		const int war = warScore(she, he);
		const int deceitful_war = deceitfulWarScore(she, he);
		cout << "Case #" << (tc + 1) << ": " << deceitful_war << ' ' << war << '\n';
	}
}
