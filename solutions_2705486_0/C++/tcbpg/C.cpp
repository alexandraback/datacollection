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
#include <fstream>
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

int dp[64][6],wordc;
string words[521197];
const int INF = 1000000;
string t;
pii cost(int st, int en, const string & s, int pv){
	int lchg = -pv,cost = 0;
	forn(i,en-st){
		if(s[i] != t[i+st]){
			if(i-lchg >= 5){
				cost++;	
				lchg = i;
			}else{
				return pii(INF,0);
			}
		}
	}
	return make_pair(cost,min(en-lchg,5));
}
bool cmp(const string & s, const string & q){
	return (s.size() == q.size()) ? 
		s < q
		: s.size() < q.size();
}
int search(int len){
	int l = 0, r = wordc;
	while(r-l > 1){
		int m = (r+l)/2,l2=words[m].size();
		if(l2 < len)
			l = m;
		else r = m;
	}
	return r;
}

int main()
{
	ifstream fs("garbled_email_dictionary.txt");
	for(wordc = 0; fs >> words[wordc]; wordc++);
	sort(words,words+wordc,cmp);
	int tests; cin >> tests;
	forsn(test,1,tests+1){
		cin >> t;
		int n = t.size();
		forn(chg,6)
			dp[n][chg] = 0;
		dforn(i,n){
			forn(chg,6){
				dp[i][chg] = INF;
				forsn(k,i+1,n+1){
					int st = search(k-i);
					int en = search(k-i+1);
					forsn(j,st,en){
						if(words[j].length() != k-i)
							break;
						pii p = cost(i,k,words[j],chg);
						int cand = p.first+dp[k][p.second];
						if(dp[i][chg] > cand) dp[i][chg] = cand;
					}
				}
			}
		}
		cout << "Case #" << test << ": " << dp[0][5] << endl;
	}
	return 0;
}
