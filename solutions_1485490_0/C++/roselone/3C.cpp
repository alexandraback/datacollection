#include <iostream>
#include <cmath>
using namespace std;

long long numa[3],numb[100];
int typea[3],typeb[100];
int pointb,a,b;
long long sum,maxm;

void init(){
	cin>>a>>b;
	for (int i=0;i<a;i++) cin>>numa[i]>>typea[i];
	for (int i=0;i<b;i++) cin>>numb[i]>>typeb[i];
	maxm=sum=pointb=0;
	return ;
}

void dfs(int i){
	int j;
	if (i==a || pointb==b){
		maxm=max(maxm,sum);
		return ;
	}
	int tmpp=pointb;
	for (j=pointb;j<b;j++) {
		if (typeb[j]==typea[i]){
			if (numa[i]==numb[j]){
				sum+=numa[i];
				pointb=j+1;
				dfs(i+1);
				pointb=tmpp;
				sum-=numa[i];
				goto end;
			}
			if (numa[i]>numb[j]){
				sum+=numb[j];
				pointb=j+1;
				numa[i]-=numb[j];
				dfs(i);
				numa[i]+=numb[j];
				pointb=tmpp;
				sum-=numb[j];
				goto end;
			}
			if (numa[i]<numb[j]){
				sum+=numa[i];
				pointb=j;
				numb[j]-=numa[i];
				dfs(i+1);
				numb[j]+=numa[i];
				sum-=numa[i];
				pointb=tmpp;
				goto end;
			}
		}
	}
end:	dfs(i+1);
}
	

void solve(){
	dfs(0);
	cout<<maxm<<endl;
}

int main (){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("3C1.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;++t){
		init();
		printf("Case #%d: ",t);
		solve();
	}
	return 0;
}