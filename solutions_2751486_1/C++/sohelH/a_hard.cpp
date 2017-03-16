#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

// ------------- PRE-WRITTEN CODES ---------------------------------

// defines and const
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

// input reading
template<class T>
vector<T> takeInput(int n) {
	vector<T> list;
	T a; int i;
	for(i = 0; i < n; i++) { cin >> a; list.push_back(a); }
	return list;
}

// math
long long ncr[305][305] = {0};
void gen_ncr(int n) {
	int i, j;
	for(i = 0; i <= n; i++) ncr[i][0] = 1;
	for(i=1; i<=n; i++) for(j=1;j<=n;j++)  ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
}

double dis(double x1, double y1, double x2, double y2) {
	return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// --------------- END of PRE-WRITTEN CODES --------------------------

bool cons(char c) {
	string vowel = "aeiou";
	if( vowel.find(c) == -1 ) return true;
	return false;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for(cases = 1; cases <= test; cases++) {
		string s; cin >> s;
		int n; cin >> n;

		long long int res = 0;
		int cnt = 0;
		int start = 0;
		int i;
		long long total;
		total = s.size();
		total = total * (total + 1);
		total /= 2;
		for(i = 0; i < s.size(); i++) {
			if( cons(s[i]) ) cnt++;
			else cnt = 0;
			if( cnt == n ) {
				start = i - n + 2;
				res += (i - start + 1);
				cnt = n - 1;
			}
			else
				res += (i - start + 1);
		}
		cout << "Case #" << cases << ": " << total - res << endl;


	}
	return 0;
}
