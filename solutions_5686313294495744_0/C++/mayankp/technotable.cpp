#include <bits/stdc++.h> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

template<class T> inline T maxm(T& a, T b){return a = a < b ? b : a;}
template<class T> inline T minm(T& a, T b){return a = a > b ? b : a;}

const int MAXN = 1000;
string s[MAXN][2];
int main(){

    int T;
    cin >> T;

    for(int i_ = 0; i_ < T; ++i_){
    
	cout << "Case #" << i_ + 1 << ": ";

	int N;
	cin >> N;

	for(int i = 0; i < N; i++) cin >> s[i][0] >> s[i][1];

	int ans = 0;
	bool dbg = 0;
	for(int mask = 0; mask < (1<<N); ++mask){
	    //if(mask == 4 && i_ == 0) dbg = 1;
	    map<string, bool> r1;
	    map<string, bool> r2;
	    for(int i = 0; i < N; ++i){
		if((mask>>i)%2 == 0) {
		    r1[s[i][0]] = 1;
		    r2[s[i][1]] = 1;
	//	    cout << "r1 " << s[i][0] << " = " << 1 << '\n';
	//	    cout << "r2 " << s[i][1] << " = " << 1 << '\n';
		}
	    }

	    bool f = 0;
	    for(int i = 0; i < N; ++i){
		if(mask&(1<<i)) {
		    if(!r1[s[i][0]]) f = 1;
		    if(!r2[s[i][1]]) f = 1;
		    //if(dbg && f) cout << s[i][0] << ' ' << s[i][1] << ' ' << r1[s[i][0]] << ' ' << r2[s[i][1]] << '\n';
		}
		if(f) break;
	    }

	    if(f) continue;
	    maxm(ans, __builtin_popcount(mask));
	}

	cout << ans << '\n';
    
    }

    return 0;

}
