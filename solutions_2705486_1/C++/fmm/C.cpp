#include <bits/stdc++.h>
#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second
using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

char s[4444];
int f[4444][10];
int n;

const int maxt=5111111;
struct Trie {
	int adj[26],end;
	Trie() {
		memset(adj,-1,sizeof adj);
		end=0;
	}
} trie[maxt+10];
int nt;

void add(string s) {
	int x=0;
	rep(i,s.size()) {
		int &nx=trie[x].adj[s[i]-'a'];
		if(nx==-1) {
			nx=nt++;
			assert(nt<=maxt);
		}
		x=nx;
	}
	trie[x].end=1;
}

void pre() {
	nt=1;
	ifstream in("data.txt");
	for(string s;in>>s;add(s));
}

int go(int,int);

int go2(int pos, int node, int need) {
	if(need<0) need=0;
	if(node==-1) return 1e9;
	int res = 1e9;
	if(trie[node].end) res = go(pos,need);
	for(char next='a';next<='z';next++) {
		if(need&&next!=s[pos]) continue;
		int nres=go2(pos+1,trie[node].adj[next-'a'],next!=s[pos]?4:need-1);
		if(next!=s[pos]) nres++;
		if(nres<res)res=nres;
	}
	return res;
}

int go(int pos, int need) {
	if(pos>=n) return 0;
	int &res = f[pos][need];
	if(res==-1) res=go2(pos,0,need);
	return res;
}

int main() {
	pre();
  int T;
	cin>>T;
	for(int testcase=1;testcase<=T;++testcase) {
		printf("Case #%d: ",testcase);
		cin>>s;
		n=strlen(s);
		memset(f,-1,sizeof f);
		int res=go(0,0);
		printf("%d\n",res);
	}
	return 0;
}

