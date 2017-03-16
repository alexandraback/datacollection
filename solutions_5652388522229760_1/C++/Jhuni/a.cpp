#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 2147483647
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;


void f(int n,int *d){
	while(n){
		d[n%10]=1;
		n/=10;
	}
}
int T;
int main(){
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){
		int n;
		int d[10]={};
		scanf("%d",&n);
		if(n==0){
			printf("Case #%d: INSOMNIA\n",TT);
			continue;
		}
		int x=0;
		while(1){
			
			int t=0;
			for(int i=0;i<10;i++){
				if(d[i]==0){
					t=1;
					break;
				}
			}
			if(t==0){
				break;
			}
			x+=n;
			f(x,d);
			
		}
		printf("Case #%d: %d\n",TT,x);
	}
}