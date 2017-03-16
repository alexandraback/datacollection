#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

int N;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		scanf("%d",&N);
		if(N==0){
			printf("Case #%d: INSOMNIA\n",Case);
			continue;
		}
		int mask=0;
		int n;
		for(n=N;mask!=(1<<10)-1;n+=N){
			int x=n;
			while(x){
				mask|=1<<(x%10);
				x/=10;
			}
		}
		printf("Case #%d: %d\n",Case,n-N);
	}
}
