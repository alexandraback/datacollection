#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#define fou(i,j,k) for (int i=j;i<=k;i++)
#define fod(i,j,k) for (int i=j;i>=k;i--)
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> Pii;

const int maxn=1010;
const int inf=0x3f3f3f3f;
const LL infLL=0x3f3f3f3f3f3f3f3fLL;

struct node{
	string x,y;
}a[maxn];

int n,ans,b[maxn];
bool fz,f[maxn];
map<string, int> c,d,e;

void init(){
	scanf("%d",&n);
	fou(i,1,n)
		cin>>a[i].x>>a[i].y;
}

void dfs(int k,int m)
{
	if (k>n){
		fou(i,1,n)
			if (!f[i]){
			//	if ((e.find(a[i].x+' '+a[i].y)!=e.end() && e[a[i].x+' '+a[i].y])
			//	|| !c.find(a[i].x) || !d.find(a[i].y) || !c[a[i].x] || !d[a[i].y]) return;
				bool f1,f2;
			/*	f1=e[a[i].x+' '+a[i].y];
				f2=c[a[i].x];
				f3=d[a[i].y];
				string s1=a[i].x;
				string s2=a[i].y;*/
				fou(j,1,m)
					if (a[i].x==a[b[j]].x && a[i].y==a[b[j]].y) return;
				f1=false;
				fou(j,1,m)
					if (a[i].x==a[b[j]].x) f1=true;
				f2=false;
				fou(j,1,m)
					if (a[i].y==a[b[j]].y) f2=true;
				if (!f1 || !f2) return;
				//if (e[a[i].x+' '+a[i].y] || !c[a[i].x] || !d[a[i].y]) return;
			}
		if (ans<n-m) ans=n-m;
		return;
	}
	dfs(k+1,m);
	b[m+1]=k;
	f[k]=true;
	c[a[k].x]=1;
	d[a[k].y]=1;
//	if (k==1) cout<<a[k].y<<endl;
	e[a[k].x+' '+a[k].y]=1;
	dfs(k+1,m+1);
	f[k]=false;
	c[a[k].x]=0;
	d[a[k].y]=0;
	e[a[k].x+' '+a[k].y]=0;
}

void solve(){
	memset(f,false,sizeof(f));
	fz=false;
	e.clear();
	c.clear();
	d.clear();
	ans=0;
	dfs(1,0);
	printf("%d\n",ans);
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	fou(i,1,T){
//	while (scanf("",)!=EOF){
		printf("Case #%d: ",i);
		init();
		solve();
	}
	return 0;
}
