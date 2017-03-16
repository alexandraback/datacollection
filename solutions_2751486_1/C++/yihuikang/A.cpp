#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define repeat(t) for (int asdfg=0; asdfg < (t); asdfg++)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int n,k,c[1100000];
string s;

inline bool ok(char x) {
	if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return false;
	return true;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int cas;
	cin >> cas;
	for (int T=1; T<=cas; T++) {
		cin >> s >> k;
		int n=s.size();
		c[0]=0;
		if (ok(s[0])) c[0]++;
		for (int i=1; i<n; i++) {
			if (ok(s[i])) c[i]=c[i-1]+1;
			else c[i]=0;
		}
		ull ans=0;
		int p=0;
		for (int i=0; i<n; i++) if (c[i]>=k) {
			// printf("%d : p=%d %d %d\n",i,p,(n-i),(i-k-p+2));
			ans+=(n-i)*(i-k-p+2);
			p=i-k+2;
		}
		cout << "Case #" << T << ": " << ans << endl;
	}

	return 0;
}