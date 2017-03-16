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

string ns[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

// 0 4  2 6  1 3 7  8 5 

int na[] = {0, 4,  2, 6,  1, 3, 7,  8, 5 , 9};

int main()
{
	//ios_init();
	/*string s;
	REP(i,10){
		if(i != 0 and i != 4 and i != 2 and i != 6 and i != 1 and i != 3 and i != 7) s += ns[i];
	}
	sort(ALL(s));
	cout << s << endl;*/
	int n;
	cin >> n;
	vector<int> cnt(26,0);
	REP(hoge,n){
		//DEBUG(hoge);
		string s;
		cin >> s;
		REP(i,SZ(s)){
			cnt[s[i]-'A']++;
		}
		vector<int> ans;
		REP(i,10){
			int num = na[i];
			bool f = true;
			while(f){
				REP(j,SZ(ns[num])){
					if(cnt[ns[num][j]-'A'] == 0){
						f = false;
					}
				}
				if(f){
					REP(j,SZ(ns[num])) cnt[ns[num][j]-'A']--;
					ans.push_back(num);
				}
			}
		}
		REP(i,SZ(cnt)) assert(cnt[i] == 0);
		sort(ALL(ans));
		WRC(hoge);
		REP(i,SZ(ans)) cout << ans[i];
		cout << endl;
	}
	return 0;
}
