#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

#define fi          first
#define se          second
#define mp 			make_pair
#define pb          push_back
#define forall(i,a,b)               for(int i=a;i<b;++i)
#define max(a,b)                    ( (a) > (b) ? (a) : (b))
#define min(a,b)                    ( (a) < (b) ? (a) : (b))
#define mes(a,b)					memset(a,b,sizeof a)
#define endl			    		"\n"
#define ll 							long long
const int oo = 1000000009;
const double eps = 1e-9;
const int mod = 1000000007;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

bool isPalindrome(string s){
	return (s == string(s.rbegin(),s.rend()));
}

int main(){
	int t;cin >> t;
	forall(test,0,t){
		cout << "Case #" << test+1 << ": ";
		int k,c,s;cin >> k >> c >> s;
		forall(i,0,k) cout << i+1 << ' ';
		cout << endl;
	}
}