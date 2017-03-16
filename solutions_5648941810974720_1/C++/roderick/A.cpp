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

const int maxn=2010;
const int inf=0x3f3f3f3f;
const LL infLL=0x3f3f3f3f3f3f3f3fLL;

int c[50],ans[50];
char s[maxn];

void init(){
	scanf("%s",s);
}

void solve(){
	int n;
	n=strlen(s);
	memset(c,0,sizeof(c));
	memset(ans,0,sizeof(ans));
	fou(i,0,n-1)
		c[s[i]-'A']++;
	if (c['Z'-'A']){
		ans[0]+=c['Z'-'A'];
		c['E'-'A']-=c['Z'-'A'];
		c['R'-'A']-=c['Z'-'A'];
		c['O'-'A']-=c['Z'-'A'];
		c['Z'-'A']=0;;
	}
	if (c['W'-'A']){
		ans[2]+=c['W'-'A'];
		c['T'-'A']-=c['W'-'A'];
		c['O'-'A']-=c['W'-'A'];
		c['W'-'A']=0;;
	}
	if (c['U'-'A']){
		ans[4]+=c['U'-'A'];
		c['F'-'A']-=c['U'-'A'];
		c['O'-'A']-=c['U'-'A'];
		c['R'-'A']-=c['U'-'A'];
		c['U'-'A']=0;;
	}
	if (c['R'-'A']){
		ans[3]+=c['R'-'A'];
		c['T'-'A']-=c['R'-'A'];
		c['H'-'A']-=c['R'-'A'];
		c['E'-'A']-=2*c['R'-'A'];
		c['R'-'A']=0;;
	}
	if (c['F'-'A']){
		ans[5]+=c['F'-'A'];
		c['I'-'A']-=c['F'-'A'];
		c['V'-'A']-=c['F'-'A'];
		c['E'-'A']-=c['F'-'A'];
		c['F'-'A']=0;;
	}
	if (c['X'-'A']){
		ans[6]+=c['X'-'A'];
		c['S'-'A']-=c['X'-'A'];
		c['I'-'A']-=c['X'-'A'];
		c['X'-'A']=0;;
	}
	if (c['V'-'A']){
		ans[7]+=c['V'-'A'];
		c['S'-'A']-=c['V'-'A'];
		c['N'-'A']-=c['V'-'A'];
		c['E'-'A']-=2*c['V'-'A'];
		c['V'-'A']=0;;
	}
	if (c['G'-'A']){
		ans[8]+=c['G'-'A'];
		c['E'-'A']-=c['G'-'A'];
		c['I'-'A']-=c['G'-'A'];
		c['H'-'A']-=c['G'-'A'];
		c['T'-'A']-=c['G'-'A'];
		c['G'-'A']=0;;
	}
	if (c['O'-'A']){
		ans[1]+=c['O'-'A'];
		c['N'-'A']-=c['O'-'A'];
		c['E'-'A']-=c['O'-'A'];
		c['O'-'A']=0;;
	}
	if (c['I'-'A']){
		ans[9]+=c['I'-'A'];
		c['E'-'A']-=c['I'-'A'];
		c['N'-'A']-=2*c['I'-'A'];
		c['I'-'A']=0;;
	}
	fou(i,0,9)
		fou(j,1,ans[i]) printf("%d",i);
	printf("\n");
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	//g[0]['Z'-'A']=g[0]['E'-'A']=g[0]['R'-'A']=g[0]['O'-'A']=1;
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
