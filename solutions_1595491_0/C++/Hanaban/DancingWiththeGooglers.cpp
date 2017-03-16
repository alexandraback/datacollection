#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

long long solve() {
	int N, S, P;
	long long ans = 0;
	vector<int> t;
	
	cin >> N >> S >> P;
	t.clear();
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x % 3 == 0) {
			if (x >= P * 3) ++ans;
			else if (x < (P - 1) * 3 || P < 2) continue;
			else t.push_back(x);
		} else if (x % 3 == 1) {
			if (x >= P * 3 - 2) ++ans;
			else continue;
		} else {
			if (x >= P * 3 - 1) ++ans;
			else if (x < P * 3 - 4 || P < 2) continue;
			else t.push_back(x);
		}
	}
	//for (int i = 0; i < t.size(); ++i) cout << t[i] << " ";
	//cout << endl;
	ans += min( static_cast<int>(t.size() ), S);
	
	return ans;
}

int main()
{
	int T;
	
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": " << solve() << endl;
	}
	
	return 0;
}
