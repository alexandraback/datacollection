#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define mod 1000000007
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

string s[200];
vector<int> a[200];
int v[200],p[200],w[200],h[200];
ll fac[200];
int n;
string now;

void dfs(int x) {
	int i,y;
	now+=s[x];
	v[x]=1;
	for (i=0;i<a[x].size();i++) {
		y=a[x][i];
		if (!v[y] && p[y]) {
			dfs(y);
			return;
		}
	}
	for (i=0;i<a[x].size();i++) {
		y=a[x][i];
		if (!v[y]) {
			dfs(y);
			return;
		}
	}
}

int main() {
	int i,j,te,tt,u;
	fac[0]=1;
	for (i=1;i<=100;i++) fac[i]=fac[i-1]*i%mod;
	scanf("%d",&tt);
	for (te=1;te<=tt;te++) {
		scanf("%d",&n);
		memset(h,0,sizeof(h));
		memset(p,0,sizeof(p));
		memset(w,0,sizeof(w));
		for (i=0;i<n;i++) a[i].clear();
		for (i=0;i<n;i++) cin>>s[i];
		for (i=0;i<n;i++) {
			p[i]=1;
			for (j=0;j<s[i].size();j++) p[i]&=s[i][j]==s[i][0];
			if (p[i]) w[s[i][0]-'a']++;
		}
		for (i=0;i<n;i++) 
			for (j=i+1;j<n;j++) 
				if (s[i][s[i].size()-1]==s[j][0]) {
					a[i].push_back(j);
					h[j]++;
				}
				else if (s[j][s[j].size()-1]==s[i][0]) {
					a[j].push_back(i);
					h[i]++;
				}
		memset(v,0,sizeof(v));
		now="";
		u=0;
		for (i=0;i<n;i++) if (!v[i] && h[i]==0) {
			dfs(i);
			u++;
		}	
		int flag=1;
		for (i=0;i<n;i++) if (!v[i]) flag=0;
		if (flag) {
			char last=now[0];
			memset(v,0,sizeof(v));
			v[last-'a']=1;
			for (i=1;i<now.size();i++) if (last!=now[i]) {
				if (v[now[i]-'a']) flag=0;
				last=now[i];
				v[last-'a']=1;
			}
		}
		printf("Case #%d: ",te);
		if (flag) {
			ll ans=fac[u];
			for (i=0;i<26;i++) ans=ans*fac[w[i]]%mod;
			cout<<ans<<endl;
		}
		else puts("0");
	}
}
