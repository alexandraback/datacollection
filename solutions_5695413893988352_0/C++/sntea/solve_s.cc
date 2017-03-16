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
		string cs,js;
		cin >> cs >> js;
		string ans1, ans2;
		int cn = INF, jn = INF;
		int sa = INF;
		REP(c,1000){
			REP(j,1000){
				int sat = abs(c-j);
				string s1;
				string s2;
				int cp = c;
				int jp = j;
				REP(i,SZ(cs)){
					s1 += '0'+cp%10;
					cp /= 10;
				}
				reverse(ALL(s1));
				REP(i,SZ(js)){
					s2 += '0'+jp%10;
					jp /= 10;
				}
				reverse(ALL(s2));
				int ccc = 0, jjj = 0;
				REP(i,SZ(s1)){
					ccc *= 10;
					ccc += s1[i]-'0';
				}
				//DEBUG(s1); DEBUG(ccc);
				REP(i,SZ(s2)){
					jjj *= 10;
					jjj += s2[i]-'0';
				}
				//DEBUG(s2); DEBUG(jjj);
				bool f = true;
				REP(i,SZ(cs)){
					if(cs[i] != '?' and cs[i] != s1[i]){
						f = false;
					}
				}
				REP(i,SZ(js)){
					if(js[i] != '?' and js[i] != s2[i]){
						f = false;
					}
				}
				bool ff = false;
				if(f){
					if(sat < sa){
						ff = true;
					}else if(sat == sa){
						if(ccc < cn){
							ff = true;
						}else if(ccc == cn){
							if(jjj < jn){
								ff = true;
							}
						}
					}
				}
				if(ff){
					cn = ccc;
					jn = jjj;
					ans1 = s1;
					ans2 = s2;
					sa = sat;
				}
			}
		}
		WRC(hoge);
		cout << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}
