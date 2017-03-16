#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

pair<ll, pair<ll, ll> > gao(string &s1, string &s2, int f, int lg) {
	ll ss1 = 0, ss2 = 0;
	ll T = 1;
	int l = s1.length();
	DEP(i,l-1,0) {
		if(i >= f) {
			if(lg == 1) {
				ss1 += (s1[i] == '?' ? 0 : s1[i] - '0') * T;
				ss2 += (s2[i] == '?' ? 9 : s2[i] - '0') * T;
			}else{
				ss1 += (s1[i] == '?' ? 9 : s1[i] - '0') * T;
				ss2 += (s2[i] == '?' ? 0 : s2[i] - '0') * T;
			}
		}else{
			if(s1[i] == '?' && s2[i] == '?') {
				//0
			}else if(s1[i] != '?') {
				ss1 += T * (s1[i]-'0');
				ss2 += T * (s1[i]-'0');
			}else if(s2[i] != '?') {
				ss1 += T * (s2[i]-'0');
				ss2 += T * (s2[i]-'0');	
			}
		}
		T*=10;
	}
	return MP(abs(ss1-ss2), MP(ss1, ss2));
}

int good(string s, int n) {
	int l = (int)s.length()-1;
	while(l>=0) {
		if(s[l] != '?' && s[l]-'0' != n%10) return false;
		l--;
		n/=10;
	}
	return true;
}

void gao1(string s1, string s2) {
	int l = s1.length();
	int t = 1;
	pair<int, PII> p = MP(INF,MP(0,0));
	REP(i,l) t*=10;
	REP(i,t) {
		REP(j,t) {
			if(good(s1, i) && good(s2, j)) {
				p = min(p, MP(abs(i-j), MP(i,j)));
			}
		}
	}
			cout<<setw(l)<<setfill('0')<<p.Y.X<<' '
				<<setw(l)<<setfill('0')<<p.Y.Y<<endl;
}

int main()
{
#ifdef LOCAL
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int t,cs=1;
	cin>>t;
	while(t--) {
		string s1, s2;
		cin>>s1>>s2;
		//cout<<endl;
	//gao1(s1, s2);
		int l = s1.length();
		int f = -1;
		REP(i,l) {
			if(s1[i] == '?' && s2[i] == '?') {
				//s1[i] = s2[i] = '0';
			}else if(s1[i] == '?') {
				//s2[i] = s1[i];
			}else if(s2[i] == '?') {
				//s1[i] = s2[i];
			}else if(s1[i] != s2[i]) {
				f = i;
				break;
			}
		}
		cout<<"Case #"<<cs++<<": ";
		if(f == -1) {
			REP(i,l) {
				if(s1[i] == '?' && s2[i] == '?') {
					s1[i] = s2[i] = '0';
				}else if(s1[i] == '?') {
					s1[i] = s2[i];
				}else if(s2[i] == '?') {
					s2[i] = s1[i];
				}
			}
			cout<<s1<<' '<<s2<<endl;
		}else{
			pair<ll, pair<ll, ll> > p = MP(LLONG_MAX, MP(0, 0));
			
			ll mn = LLONG_MAX;
			if(s1[f] > s2[f]) {
				p = min(p, gao(s1, s2, f, 1));
				if(f) {
					DEP(ff, f-1,0) {
						char c1 = s1[ff];
						char c2 = s2[ff];
						int err = 0;
						if(s2[ff] == '?' && s1[ff] != '9') {
							if(s1[ff] == '?') {
								s1[ff] = '0';
								s2[ff] = '1';
							}else{
								s2[ff] = s1[ff] + 1;
							}
						}else if(s1[ff] == '?' && s2[ff] != '0') {
							s1[ff] = s2[ff] - 1;
						}else err = 1;
						if(!err) p = min(p, gao(s1, s2, ff, 0));
					s1[ff] = c1;
					s2[ff] = c2;
					}
				}
			}else{
				p = min(p, gao(s1, s2, f, 0));
				DEP(ff, f-1,0) {
					char c1 = s1[ff];
					char c2 = s2[ff];
					
					int err = 0;
					if(s2[ff] == '?' && s1[ff] != '0') {
						if(s1[ff] == '?') {
							s1[ff] = '1';
							s2[ff] = '0';
						}else{
							s2[ff] = s1[ff] - 1;
						}
					}else if(s1[ff] == '?' && s2[ff] != '9') {
						s1[ff] = s2[ff] + 1;
					}else err = 1;
					if(!err) p = min(p, gao(s1, s2, ff, 1));
					
					s1[ff] = c1;
					s2[ff] = c2;
				}
			}
			cout<<setw(l)<<setfill('0')<<p.Y.X<<' '
				<<setw(l)<<setfill('0')<<p.Y.Y<<endl;
		}
		
	}
	return 0;
}


