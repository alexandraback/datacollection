#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

void problema(int t) {
	int N;
	string s;
	cout << "Case #" << (t + 1) << ": ";
	cin >> N >> s;
	LL res = 0;
	LL acc = 0;
	for (int i = 0; i < s.length(); ++i) {
		auto val = (int)(s[i] - '0');
		auto diff = i - acc;
		acc += val;
		if (diff > 0) {
			res += diff;
			acc += diff;
		}
	}
	cout << res << endl;
}

int main()
{
	int T;
	cin >> T;
	for (auto t = 0; t < T; ++t)
	{
		problema(t);
	}
	
	return 0;
}

