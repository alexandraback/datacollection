#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RBP(i,a) for(auto& i : a)
#ifdef LOCAL111
	#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
#else
	#define DEBUG(x)
#endif
#define F first
#define S second
#define SNP string::npos
#define WRC(hoge) cout << "Case #" << (hoge)+1 << ": "
#define INF 1e8

typedef pair<int,int> P;
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> LP;

void ios_init(){ ios::sync_with_stdio(false); cin.tie(0);	
	//cout.setf(ios::fixed);
	//cout.precision(12);
}

int main()
{
	ios_init();
	int t;
	cin >> t;
	REP(hoge,t){
		int n;
		cin >> n;
		vector<string> s1(n),s2(n);
		set<string> ss1, ss2;
		REP(i,n){
			cin >> s1[i] >> s2[i];
			ss1.insert(s1[i]);
			ss2.insert(s2[i]);
		}
		int ans = 0;
		REP(sss, 1 << n){
			auto st1 = ss1;
			auto st2 = ss2;
			int a = sss;
			int cnt = 0;
			REP(i,n){
				if(a&1){
					cnt++;
					st1.erase(s1[i]);
					st2.erase(s2[i]);
				}
				a >>= 1;
			}
			if(st1.empty() and st2.empty()){
				ans = max(ans,n-cnt);
			}
		}
		WRC(hoge);
		cout << ans << endl;
	}
	return 0;
}
