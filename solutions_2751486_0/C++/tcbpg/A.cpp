#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <climits>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);++i)
#define forall(i,c) for(typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define dforsn(i,s,n) for(int i=((int)(n)-1);i>=(int)(s);--i)
#define all(v) (v).begin(),(v).end()
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << "=============================================" << endl

typedef long long tint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vii;

bool vowel(char c){
	if(c == 'a') return true;
	if(c == 'e') return true;
	if(c == 'i') return true;
	if(c == 'o') return true;
	if(c == 'u') return true;
	return false;
}

int main()
{
	int tests; cin >> tests;
	for(int test = 1; test <= tests; test++){
		tint res = 0;
		string s; cin >> s;
		int n; cin >> n;
		tint count = 0; int last = 0;
		forn(i,s.size()){
			if(!vowel(s[i])){
				count++;
				if(count >= n){
					res += (1LL*(i-n-last+2))*(s.size()-i);
					last = i-n+2;
				}
			}else{
				count = 0;
			}
		}	

		cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}
