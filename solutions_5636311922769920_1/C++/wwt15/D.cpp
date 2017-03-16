#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int K,C,S;

void Main(){
	scanf("%d%d%d",&K,&C,&S);
	int cnt=K/C+bool(K%C);
	if(S<cnt){
		puts(" IMPOSSIBLE");
		return;
	}
	set<ll> ans;
	for(int i=0;i<cnt;i++){
		ll loc=0;
		for(int j=i*C;j<(i+1)*C;j++){
			loc=loc*K+min(j,K-1);
		}
		ans.insert(loc+1);
		S--;
	}
	for(int i=1;S;i++) if(ans.find(i)==ans.end()){
		ans.insert(i);
		S--;
	}
	for(set<ll>::iterator _=ans.begin();_!=ans.end();_++)
		printf(" %I64d",*_);
	printf("\n");
}

int main(){
	freopen("D-large.in","r",stdin);
	freopen("D.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		printf("Case #%d:",Case);
		Main();
	}
}