//BISM ILLAHHIRRAHMANNI RRAHIM

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector< int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

struct node{
	int nx[26];
	bool fl;
}tr[4621196];
int ls;


void gen_tri() {
	FILE *fin=fopen("garbled_email_dictionary.txt","r");
	char ln[15];
	int i,c;
	SET(tr[ls].nx);
	tr[ls].fl=0;
	while(fgets_unlocked(ln,15,fin)) {
		c=0;
		//cout<<tr[c].nx[ln[0]-'a']<<'\n';
		for(i=0;ln[i]!='\n';i++) {
			if(tr[c].nx[ln[i]-'a']==-1) {
				ls++;
				SET(tr[ls].nx);
				tr[ls].fl=0;
				tr[c].nx[ln[i]-'a']=ls;
			}
			c=tr[c].nx[ln[i]-'a'];
		}
		//cout<<ln<<' '<<c<<' '<<i<<'\n';
		//int tt;cin>>tt;
		tr[c].fl=1;
	}
	//cerr<<ls<<'\n';
}


bool find(char *ln,int p) {
	//printf("%s %d %d\n",ln,p,tr[p].fl);
	if(!(*ln)) return tr[p].fl==1;
	if((*ln)=='?') {
		int i;
		for(i=0;i<26;i++) if(tr[p].nx[i]!=-1 && find(ln+1,tr[p].nx[i])) return true;
		return false;
	}
	else {
		if(tr[p].nx[(*ln)-'a']==-1) return false;
		return find(ln+1,tr[p].nx[(*ln)-'a']);
	}
}


int dp[4100][5];
bool vis[4100][5];

char s[4100];


int dfs(int p,int lf) {
	if(!s[p]) return 0;
	if(vis[p][lf]) return dp[p][lf];
	vis[p][lf]=1;
	//cout<<p<<' '<<lf<<'\n';
	int i,j,k,l,r=1000000;
	char ln[15],t,tt,ttt;
	for(i=0;i<11 && s[p+i];i++) {
		for(j=0;j<=i;j++) ln[j]=s[p+j];
		ln[i+1]=0;
		if(find(ln,0)) r=min(r,dfs(p+i+1,max(0,lf-i-1)));
		for(j=lf;j<=i;j++) {
			t=ln[j];
			ln[j]='?';
			if(find(ln,0)) r=min(r,1+dfs(p+i+1,max(0,5-(i-j+1))));
			ln[j]=t;
		}
		for(j=lf;j<=i;j++) for(k=j+5;k<=i;k++) {
			t=ln[j];
			tt=ln[k];
			ln[j]='?';
			ln[k]='?';
			if(find(ln,0)) r=min(r,2+dfs(p+i+1,max(0,5-(i-k+1))));
			ln[j]=t;
			ln[k]=tt;
		}
		for(j=lf;j<=i;j++) for(k=j+5;k<=i;k++) for(l=k+5;l<=i;l++) {
			t=ln[j];
			tt=ln[k];
			ttt=ln[l];
			ln[j]='?';
			ln[k]='?';
			ln[l]='?';
			if(find(ln,0)) r=min(r,3+dfs(p+i+1,max(0,5-(i-l+1))));
			ln[j]=t;
			ln[k]=tt;
			ln[l]=ttt;
		}
	}
	return dp[p][lf]=r;
}



int main() {
	gen_tri();
	//char ln[15];while(gets(ln)) cout<<find(ln,0)<<'\n';
	//READ("input.in");
	//READ("C-small-attempt0.in");
	//READ("C-small-attempt1.in");
	//READ("C-small-attempt2.in");
	//READ("C-small-attempt3.in");
	READ("C-large.in");
	WRITE("output_L.out");
	int I,T;
	cin>>T;
	for(I=1;I<=T;I++) {
		scanf("%s",s);
		CLR(vis);
		SET(dp);
		
		printf("Case #%d: %d\n",I,dfs(0,0));
		/*for(int i=0;s[i];i++) {
			cout<<i<<":";
			for(int j=0;j<5;j++) cout<<' '<<dp[i][j];
			puts("");
		}*/
	}
	return 0;
}
