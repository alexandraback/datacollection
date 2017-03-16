/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int calc() { 
	int _num; cin >> _num;
	string s;
	cin >> s; 
	int counter = s[0] - '0';
	int ans = 0 ; 
	for( int i = 1 ; i < sz(s) ; i++ ) { 
		int tmp = max( i - counter , 0 ) ; 
		ans += tmp;
		counter += tmp;
		counter += s[i] - '0';
	}
	return ans;
}

int main() { 
	int t;
	cin >> t;
	for( int i = 0 ; i < t; i++ ) 
		cout << "Case #" << i+1 << ": " << calc() << endl;
}
