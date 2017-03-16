#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define pritnf printf
#define N 1514
using namespace std;
typedef long long int lnt;
typedef double dou;
int n;
int p[N*N],np[N*N];
map<int,int>sss;
int cmp(int a,int b){return a>b;}

int tans;
void dfs(int t){
	if(t-1>=tans)return;
	//////////
	int tmp=sss.rbegin()->first;
	tans=min(tans,t-1+tmp);
	if(--sss[tmp]==0)sss.erase(tmp);
	for(int i=1;i*2<=tmp;i++){
		sss[i]++;
		sss[tmp-i]++;
		dfs(t+1);
		if(--sss[i]==0)sss.erase(i);
		if(--sss[tmp-i]==0)sss.erase(tmp-i);
	}
	sss[tmp]++;
	/////////
}
void sol(int uuu){
	RI(n);
	for(int i=0;i<n;i++){
		RI(p[i]);
	}
	///////
	sort(p,p+n);
	tans=p[n-1];
	sss.clear();
	for(int i=0;i<n;i++)sss[p[i]]++;
	dfs(1);
	printf("Case #%d: %d\n",uuu,tans);
	return;
	///////
	sort(p,p+n,cmp);
	int ans=p[0];
	for(int t=0;t<N*N;t++){
		int w=p[0];pop_heap(p,p+n);n--;
		if(w==1)break;
		p[n++]=0+w/2;push_heap(p,p+n);
		p[n++]=w-w/2;push_heap(p,p+n);
		ans=min(ans,p[0]+t+1);
	}
	printf("Case #%d: %d\n",uuu,ans);
}
int main(){
	//freopen("B-small-attempt2.in","r",stdin);
	//freopen("Bout_s.txt","w",stdout);
	int t;RI(t);
	for(int i=1;i<=t;i++)sol(i);
	return 0;
}

