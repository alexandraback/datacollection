#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
long long res[1100];
int key[1100][20];
int pr[]={3,5,7,11};
int main(){
	int T;scanf("%d",&T);
	int N,J;
	scanf("%d%d",&N,&J);
	set<long long>S;
	int ind=0;
	while(ind<J){
		long long cur=0;
		for(int i=0;i<N;i++){
			if(i==0||i==N-1||rand()%2){
				cur+=(1LL<<i);
			}
		}
		if(S.count(cur))continue;
		bool ok=true;
		for(int i=2;i<=10;i++){
			bool OK=false;
			for(int j=0;j<4;j++){
				int p=0;
				int mod=pr[j];
				int v=1;
				for(int j=0;j<N;j++){
					if(cur&(1LL<<j))p+=v;
					v=v*i%mod;
				}
				if(p%mod==0){
					OK=true;
					key[ind][i-2]=mod;
					break;
				}
			}
			if(!OK)ok=false;
		}
		if(ok){
			S.insert(cur);
			res[ind++]=cur;
		}
	}
	printf("Case #1:\n");
	for(int i=0;i<J;i++){
		for(int j=N-1;j>=0;j--){
			printf("%d",!!(res[i]&(1LL<<j)));
		}
		for(int j=0;j<9;j++)printf(" %d",key[i][j]);
		printf("\n");
	}
}