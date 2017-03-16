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

int jp[10][10], ps[10][10], js[10][10];

int main(){

    int T;
    cin >> T;

    for(int i_ = 0; i_ < T; i_++){
    
	int J, P, S, K;
	cin >> J >> P >> S >> K;
	int numT = J * P * S;

	int bstMsk = 0;
	int ans = min(J, K) * min(P, K) * min(S, K);
	//if(max(J * P, max(J * S, S * K)) 
	for(int msk = 1; msk < (1<<numT); ++msk){
	    bool f = 0;
	    if(__builtin_popcount(msk) < ans){ 
		//cout << "going on\n";
		continue;
	    }
	    memset(jp, 0, sizeof(jp));
	    memset(ps, 0, sizeof(ps));
	    memset(js, 0, sizeof(js));
	    for(int i = 0; i < numT; ++i){
	    
		int j = i%J;
		int p = i/J%P;
		int s = i/J/P;

		if(msk&(1<<i)){
		    jp[j][p]++;
		    ps[p][s]++;
		    js[j][s]++;
		}
		if(max(jp[j][p], max(ps[p][s], js[j][s])) > K){
		    f = 1;
		    break;
		}
	    
	    }
	    if(!f && __builtin_popcount(msk) >= ans){
		bstMsk = msk;
		ans = __builtin_popcount(msk);
	    }
	}

	cout << "Case #" << i_ + 1 << ": " << ans << '\n';
    
	for(int i = 0; i < numT; ++i){

	    int j = i%J;
	    int p = i/J%P;
	    int s = i/J/P;
	    if(bstMsk&(1<<i))cout << j + 1 << ' ' << p + 1 << ' ' << s + 1 << '\n';
	}
    }
	return 0;

}
