// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,a,n) for(int i=a;i<n;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define foreach(it, x) for(typeof(x.begin()) it = x.begin(); it!=x.end();it++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

inline int print(int d) { return printf("%d",d);}
inline int read(int &d) { 
	d=0;
	int sign=1,ch;
	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)ch=getchar_unlocked();
	if(ch=='-')
		sign=-1, ch=getchar_unlocked();
	do 
		d=(d<<3)+(d<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
	d*=sign;
	return 1;
}

int nvalue(string s, int n) {
	map<char,int> M;M['a'] = M['e'] = M['i'] = M['o'] = M['u'] = 1;
	int c = 0;
	FOR(i,s.size()) {
		if ( M.find(s[i]) == M.end()) {
			c++;
		}
		else {
			if ( c>=n) return 1;
			else c = 0;
		}
	}
	return c>=n;
}

int main(int argc,char** args) 
{
	int tc;read(tc);FOR(tests,tc) {
		string s;
		int n;
		int ans = 0;
		cin>>s>>n;
		FOR(i,s.size()-n+1) {
			for(int j = n; j<=s.size() - i;j++) {
				int v = nvalue(s.substr(i,j),n);
				cerr<<s.substr(i,j)<<" is "<<v<<endl;
				ans+=v;
			}
		}
		cout<<"Case #"<<tests+1<<": "<<ans<<endl;
	}
}
