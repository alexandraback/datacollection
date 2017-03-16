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
#include <set>
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
	long long ans = 0;
	int A, B;
	
	cin >> A >> B;
	int g = 0;
	int x = A;
	int t = 1;
	int y;
	set<int> s;
	
	while (x >= 10) {
		x /= 10;
		++g;
		t *= 10;
	}
	
	for (int i = A; i <= B; ++i) {
		x = i;
		y = i;
		s.clear();
		for (int j = 0; j < g; ++j) {
			y = (y % t) * 10 + (y / t);
			if (x < y && y <= B && s.find(y) == s.end() ) {
				++ans;
				s.insert(y);
			}
		}
	}
	
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
