#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define PI 3.141592653589793238462643
#define MOD 1000000009
#define eps 1e-8
const int inf = 1000000005;
const int dr[]={0,1,0,-1,1,1,-1,-1};
const int dc[]={1,0,-1,0,1,-1,1,-1};

typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> mat; 
typedef pair<int,int> pii;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n) 
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mp make_pair

#define MAXN 2000000

set<int> S[MAXN+1];
void init() {
	for (int i = 10; i <= MAXN; i++) {
		stringstream ss; string s;
		ss << i;
		ss >> s;

		set<int> & v = S[i];
		int L = s.size();

		for (int j = 1; j <= L-1; j++) {
			if (s[j] == '0') continue;

			int n2 = 0;
			for (int k = j; k < j + L; k++) {
				int ind = k%L;
				n2 *= 10;
				n2 += s[ind] - '0';
			}
			if (n2 > i) v.insert(n2);

		}
	}
	
} 

int main() {
	int T, A, B;
	cin >> T;
	int loop = 1;
	init();
	/*
	for (int i = 10; i <= 40; i++) {
		cout << i << " ";
		for (int j = 0; j < S[i].size(); j++) {
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	*/
	while (loop <= T) {
		
		long long ans = 0;
		cin >> A >> B;
		
		for (int i = A; i <= B; i++) {
			//bool in = false;
			set<int>::iterator it;
			for (it = S[i].begin(); it != S[i].end(); it++) {
				int val = *it;
				if (val >= A && val <= B) ans++;
			}
		}
		cout << "Case #" << loop << ": " << ans << endl;
		loop++;
	}

	return 0;
}