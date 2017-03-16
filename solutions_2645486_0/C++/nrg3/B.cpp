#pragma comment(linker, "/STACK:256000000")

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
//#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)


const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;

bool is(long long r, long long n, long long t) {
	unsigned long long a = (2 * r + 1 + 2 * (n - 1));
	unsigned long long b = n;
	if (a > t / b || t % b && a == t / b) {
		return 0;
	}

	return a * b <= t;
}


class Solver {
public:
	int e, r;
	vector<int> v;	
	map< pair<int,int>, long long > memo;

	Solver(int e, int r, const vector<int>& v) 
		: e(e), r(r), v(v) {
	}

	long long find(int index, int energy) {
		if (index == v.size()) return 0;
		map< pair<int,int>, long long >::iterator it;
		if ((it = memo.find(make_pair(index, energy))) != memo.end()) {
			return it->second;
		}



		long long answer = 0 ;//max(find(index + 1, r) + (long long) energy * v[index],
							//	 find(index + 1, min(e, energy + r)));

		for (int i = 0; i <= energy; ++i) {
			answer = max(answer, find(index + 1, min(e, energy - i + r)) + v[index] * i);
		}


		//answer = max(answer, find(index + 1, energy) + min(energy, r) * v[index]);
		


		return memo[make_pair(index, energy)] = answer;
	}
};

long long solve(int e, int r, const vector<int>& v) {
	Solver s(e, r, v);
	return s.find(0, e);	
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#else
#define taskname "comb"
    //freopen(taskname".in","r",stdin); 
    //freopen(taskname".out","w",stdout);
#endif

	int T; cin >> T;

	for (int test = 1; test <= T; ++test) {
		long long e, r, n;
		cin >> e >> r >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		cout << "Case #" << test << ": " << solve(e, r, v) << endl;
	}

	
	return 0;
}
