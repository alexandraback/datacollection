#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 200;
const int M = 3000;
int n;
int a[N][N];
int cou[M];
//#define LOCAL
int main(){
	#ifdef LOCAL
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	for(int times=1;times<=T;times++){
		scanf("%d",&n);
		memset(cou,0,sizeof(cou));
		for(int i=1;i<2*n;i++) {
			for(int j=0;j<n;j++) {
				scanf("%d",&a[i][j]);
				cou[a[i][j]] ++;
			}
		}
		printf("Case #%d:",times);
		for(int i=1;i<=2500;i++) if (cou[i]&1) printf(" %d",i);
		puts("");
	}
	return 0;
}