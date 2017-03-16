#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FORi(m) for( int i = 0; i < (m); ++i )
#define FOR(i, M) for( int i = 0; i < (M); ++i )
#define FOR1(i, M) for( int i = 1; i <= (M); ++i )
#define DEBUGGING 1
#define CERRL() if (DEBUGGING) { std::cerr << '\n'; }
#define EXAM(var) if (DEBUGGING) { std::cerr << #var << ": " << (var) << '\n'; }
#define EXAMARR(var, size) if (DEBUGGING) { std::cerr << #var << ": "; for(int __i__ = 0; __i__ < (size); ++__i__) std::cerr << (var)[__i__] << " "; std::cerr << '\n'; }


class City {
public:
	int zip;
	int tag;
	vector<bool> fls;
};

bool operator<(const City& a, const City& b) {
	return a.zip < b.zip;
}

vector<City> cities;

string work(int from, int count, string res, vector<bool> visited) {
//	if (sols[from] != "") return true;
	if (count == visited.size()) {
//		sols[from] = res;
		return res;
	}
	visited[from] = true;
	for (int i = 0; i < visited.size(); ++i) {
		if (!visited[i] && cities[from].fls[cities[i].tag]) {
			string s = work(i, count+1, res+to_string(cities[i].zip), visited);
			if (s != "") return s;
		}
	}
	
	return "";
}


void solve(int T) {
	FOR1(t, T) {
		int N, M;
		cin >> N >> M;
		
		cities = vector<City>(N);
		
		FOR(n, N) {
			int zip;
			cin >> zip;
			cities[n].zip = zip;
			cities[n].tag = n+1;
			cities[n].fls = vector<bool>(N+1, false);
		}
		
		FOR(m, M) {
			int i, j;
			cin >> i >> j;
			cities[i-1].fls[j] = true;
			cities[j-1].fls[i] = true;
		}
		
		sort(cities.begin(), cities.end());
		
		
		cout << "Case #" << t << ": ";
		
		string res;
		FOR(n, N) {
			res = work(n, 1, to_string(cities[n].zip), vector<bool>(N, false));
			if (res != "") break;
		}
		cout << res;
		
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	solve(T);
}



