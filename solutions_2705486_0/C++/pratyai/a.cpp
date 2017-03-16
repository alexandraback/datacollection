#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef double dbl;
typedef float flt;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define eps 1e-9
#define inf 1000000000
#define infll 1000000000000000000LL
#define abs(x) ((x)<0?-(x):(x))
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define px first
#define py second
#define sz(x) ((int)(x).size())
#define intclz(x) __builtin_clz(x)
#define intctz(x) __builtin_ctz(x)
#define intln(x) (32-intclz(x))
#define intbc(x) __builtin_popcount(x)
#define llclz(x) __builtin_clzll(x)
#define llctz(x) __builtin_ctzll(x)
#define llln(x) (64-llclz(x))
#define llbc(x) __builtin_popcountll(x)
#define atbit(x,i) (((x)>>(i))&1)
#define tof(x) __typeof(x)
#define FORab(i,a,b) for (int i=(a); i<=(b); ++i)
#define RFORab(i,a,b) for (int i=(a); i>=(b); --i)
#define FOR1(i,n) FORab(i,1,(n))
#define RFOR1(i,n) RFORab(i,(n),1)
#define FOR(i,n) FORab(i,0,(n)-1)
#define RFOR(i,n) RFORab(i,(n)-1,0)
#define allstl(i,x,t) for (t::iterator i = (x).begin(); i!=(x).end(); ++i)
#define rallstl(i,x,t) for (t::reverse_iterator i = (x).rbegin(); i!=(x).rend(); ++i)
#define begend(x) (x).begin(),(x).end()
#define ms(a,v) memset(a,v,sizeof(a))
#define msn(a,v,n) memset(a,v,n*sizeof(a[0]))
#define mcp(d,s,n) memcpy(d,s,n*sizeof(s[0]))
#define clamp(x,a,b) min(max(x,a),b)

struct node;
node* root;
int ccas;

struct node {
	char val;
	node* child[27];
	int dpcas;
	map<pii,int> dp;
	node(char val) : val(val) {
		FOR(i,27) child[i] = NULL;
		dpcas = 0;
	}
	~node() {
		FOR(i,27) {
			if (child[i] != NULL) {
				delete child[i];
			}
		}
	}
	node* push(char c) {
		int cp = c;
		if (cp) cp = cp - 'a' + 1;
		if (child[cp] == NULL) {
			child[cp] = new node(c);
		}
		return child[cp];
	}
	int search(string& s, int at, int err) { // current step matches
		if (at+1 == sz(s)) { // end of case
			if (child[0] != NULL) { // must finish word
				return 0;
			} else {
				return inf;
			}
		}
		if (ccas > dpcas) {
			dp.clear();
			dpcas = ccas;
		}
		pii key(at,err);
		if (dp.find(key) != dp.end()) {
			return dp[key];
		}
		int res = inf;
		int ns = s[at+1] - 'a' + 1;
		// no error search
		{
			if (child[ns] != NULL) { // next word must exist
				int tres = child[ns]->search(s, at + 1, max(0, err-1));
				res = min(res, tres);
			}
			if (child[0] != NULL) { // or can go to new word
				int tres = root->search(s, at, err);
				res = min(res, tres);
			}
		}
		// error search
		if (err == 0) { // can make error now
			FOR1(i,26) if (i!=ns) { // all chars
				if (child[i] != NULL) { // next word must exist
					int tres = 1 + child[i]->search(s, at + 1, 4);
					res = min(res, tres);
				}
				if (child[0] != NULL and root->child[i] != NULL) { // or can go to new word
					int tres = 1 + root->child[i]->search(s, at + 1, 4);
					res = min(res, tres);
				}
			}
		}
		return dp[key] = res;
	}
};

void dic() {
	freopen("dic.txt", "rt", stdin);
	char w[51];
	while (scanf("%s", w)==1) {
		int wz = strlen(w);
		node* cur = root;
		FOR(i,wz) {
			cur = cur->push(w[i]);
		}
		cur->push(0);
	}
}

int main()
{
	root = new node(0);
	dic();
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    int T;
    cin>>T;
    FOR1(cas,T) {
		ccas = cas;
		string s;
		cin>>s;
		int res = root->search(s, -1, 0);
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	delete root;
    return 0;
}
