#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#define SQ(a) ((a)*(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483647;
const int mod = 1000000007;


int main(){
	int TT;
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++){
		printf("Case #%d: ",T);
		int a[3],k;
		int p[3],ans=0;
		int x[3];
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&k);
		

		printf("%d\n",min(a[0]*a[1]*a[2],a[0]*a[1]*k));
		for(int i=1;i<=a[0];i++){
			x[0]=i;
			int q=i;
			for(int j=1;j<=a[1];j++){
				x[1]=j;
				for(int ii=0;ii<min(k,a[2]);ii++){
					x[2]=(q-1)%(a[2])+1;
					q++;
					printf("%d %d %d\n",x[0],x[1],x[2]);
				}
			}
		}

	}
}