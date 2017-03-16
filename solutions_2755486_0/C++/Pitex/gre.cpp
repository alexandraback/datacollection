#include <cstdio>
#include <algorithm>
using namespace std;

int wall[1000];
int D[11],N[11],W[11],E[11],S[11],DD[11],DP[11],DS[11];
int result,n;

void checkWall(int a){//printf("DAY %d IN %d %d %d\n",D[a],a,W[a],E[a]);
	for (int i=500+W[a]; i<=500+E[a]; i++){
		if (S[a]>wall[i]){
			result++;//printf("HIT!\n");
			return;
		}
	}
}

void raiseTheWalls(int a){
	for (int i=500+W[a]; i<=500+E[a]; i++){
		wall[i] = max(wall[i],S[a]);
	}
}

void solve(){
	int anything = 1;
	while (anything){
		anything = 0;
		int curDay = 1000000;
		for (int i=0; i<n; i++){
			if (D[i]<curDay && D[i]!=-1) {curDay = D[i];anything=1;}
		}
		for (int i=0; i<n; i++){
			if (curDay==D[i]){N[i]--;
				checkWall(i);
			}
		}
		for (int i=0; i<n; i++){
			if (curDay==D[i]){
				raiseTheWalls(i);
				D[i]+=DD[i];
				if (N[i]==0) D[i] = -1;
				W[i]+=2*DP[i];
				E[i]+=2*DP[i];
				S[i]+=DS[i];
			}
		}
	}
}

int main(){
	int z;
	scanf("%d", &z);
	for (int i=1; i<=z; i++){
		scanf("%d", &n);
		for (int j=0; j<1000;j++) wall[j] = 0;
		for (int j=0; j<n; j++){
			scanf("%d%d%d%d%d%d%d%d",&D[j],&N[j],&W[j],&E[j],&S[j],&DD[j],&DP[j],&DS[j]);
			W[j]*=2;
			E[j]*=2;
		}
		result=0;
		solve();
		printf("Case #%d: %d\n",i,result);
	}
}
