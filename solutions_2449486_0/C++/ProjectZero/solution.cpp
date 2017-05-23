#include <cstdio>
#include <algorithm>
using namespace std;

int T,N,M,a[105][105];

int maxvalx[105],maxvaly[105];
int ans;

void cutx(int row,int val){
	int check = true;
	for(int i=1;i<=M;i++){
		if(a[row][i] == val || a[row][i] == 0) continue;
		else{
			check = false;
			break;
		}
	}
	if(check == true) for(int i=1;i<=M;i++) a[row][i] = 0;
}
void cuty(int col,int val){
	int check = true;
	for(int i=1;i<=N;i++){
		if(a[i][col] == val || a[i][col] == 0) continue;
		else{
			check = false;
			break;
		}
	}
	if(check == true) for(int i=1;i<=N;i++) a[i][col] = 0;
}

int main(){
	freopen("output-B-small.txt","w",stdout);
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) scanf("%d",&a[i][j]);
		for(int i=1;i<=100;i++){
			for(int j=1;j<=N;j++) cutx(j,i);
			for(int j=1;j<=M;j++) cuty(j,i);
		}
		ans = 0;
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) ans += a[i][j];
		if(ans == 0)printf("Case #%d: YES\n",_i);
		else printf("Case #%d: NO\n",_i);
	}
	return 0;
}