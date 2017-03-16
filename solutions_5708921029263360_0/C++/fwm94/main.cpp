#include <bits/stdc++.h>
#define maxn 5009
#define maxm 5000009
using namespace std;
int X[maxn],Y[maxn],Z[maxn];
int tx[maxn],ty[maxn],tz[maxn];
int ansx[maxn],ansy[maxn],ansz[maxn];
map<int,int>mp;
int J,S,P,K,ans,n;
int getid(int a,int b,int c){
	int val=a*20*20+b*20+c;
	return val;
}
void dfs(int cur,int num){
	if(num>ans){
		ans=num;
		for(int i=0;i<num;i++){
			ansx[i]=tx[i];
			ansy[i]=ty[i];
			ansz[i]=tz[i];
		}
	}
	if(cur>n)
		return;
	if(cur<=n){
		bool ok=1;
		int val1=getid(X[cur],Y[cur],0);
		if(mp[val1]>=K) ok=0;
		int val2=getid(X[cur],0,Z[cur]);
		if(mp[val2]>=K) ok=0;
		int val3=getid(0,Y[cur],Z[cur]);
		if(mp[val3]>=K) ok=0;
		if(ok){
			tx[num]=X[cur];
			ty[num]=Y[cur];
			tz[num]=Z[cur];
			mp[val1]++;mp[val2]++;mp[val3]++;
			dfs(cur+1,num+1);
			mp[val1]--;mp[val2]--;mp[val3]--;
		}
	}
	dfs(cur+1,num);
}
void solve(int a,int b,int c){
	mp.clear();
	n=0;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			for(int k=1;k<=c;k++){
				n++;
				X[n]=i;
				Y[n]=j;
				Z[n]=k;
			}
		}
	}
	dfs(1,0);
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int tt,cot=1;
	scanf("%d",&tt);
	while(tt--){
		ans=0;
		cin>>J>>P>>S>>K;
		if(K>=S){
			printf("Case #%d: %d\n",cot++,J*P*S);
			for(int i=1;i<=J;i++){
				for(int j=1;j<=P;j++){
					for(int k=1;k<=S;k++){
						printf("%d %d %d\n",i,j,k);
				}
				}
			}
			continue;
		}
		mp.clear();
		ans=0;
		solve(J,P,S);
		printf("Case #%d: %d\n",cot++,ans);
		for(int i=0;i<ans;i++){
			printf("%d %d %d\n",ansx[i],ansy[i],ansz[i]);
		}
	}
	return 0;
}