#include<bits/stdc++.h>
#define N 3000
using namespace std;
vector < int > all;
int c[N + 5] , n;
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tc = 1 ; tc <= T ; tc++){
		all.clear();
		memset(c , 0 , sizeof c);
		scanf("%d",&n);
		for(int i = 1 ; i <= (2*n - 1)*n ; i++){
			int x;
			scanf("%d",&x);
			c[x] ^= 1;
		}
		for(int i = 1 ; i <= N ; i++)	if(c[i] == 1)	all.push_back(i);
		sort(all.begin() , all.end());
		printf("Case #%d: ",tc);
		for(int i = 0 ; i < all.size() ; i++)	printf("%d ",all[i]);
		printf("\n");
	}
}

