#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const int INF 2147483647;
//const int mod 1000000007;


int T;
int main(){
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){
		printf("Case #%d: ",TT);
		int n;
		int a[110][52];
		int b[2511];
		int ans[55],p=0;
		for(int i=0;i<=2500;i++){
			b[i]=0;
		}
		scanf("%d",&n);
		for(int i=0;i<n*2-1;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				b[a[i][j]]++;
			}
		}
		for(int i=1;i<=2500;i++){
			if(b[i]%2!=0){
				ans[p++]=i;
			}
		}
		sort(ans,ans+p);
		for(int i=0;i<p;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		
	}
}