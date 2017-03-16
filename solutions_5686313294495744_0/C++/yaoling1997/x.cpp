#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
set<string> fir,sec;
string a[maxn],b[maxn];
int d[maxn];
int T,i,j,ans,n;
void check(){
	fir.clear();
	sec.clear();
	int i,cnt= 0;
	for (i= 1;i<=n;i++)
		if (d[i]){
			fir.insert(a[i]);
			sec.insert(b[i]);
		}else cnt++;
	for (i= 1;i<=n;i++){
		if (d[i]) continue;
		if (fir.count(a[i])&&sec.count(b[i])) continue;
		return;
	}
	ans= max(ans,cnt);
}
void dfs(int o){
	if (o>n){
		check();
		return;
	}
	d[o]= 0;//0 false
	dfs(o+1);
	d[o]= 1;//1 true;
	dfs(o+1);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		ans= 0;
		scanf("%d",&n);
		for (i= 1;i<=n;i++)
			cin>>a[i]>>b[i];
		dfs(1);
		printf("%d\n",ans);
	}return 0;
}
