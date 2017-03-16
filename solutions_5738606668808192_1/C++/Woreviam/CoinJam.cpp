
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

int e[35];

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n, J;
		scanf("%d%d", &n, &J);
		
		vector<int>v;
		for(int i = 0; i < n; i += 2)v.pb(i);
		
		int len = n/2, ct = 0;
		printf("Case #%d:\n", caso++);
		
		for(int i = 0; i < (1<<len); i++){
			
			if((i&1) && ((i>>(len - 1))&1)){

				memset(e, 0, sizeof e);
				for(int j = 0; j < len; j++){
					
					if((i>>j)&1){
						
						e[v[j]] = 1;
						e[v[j] + 1] = 1;
					}
				}
				
				for(int j = 0; j < n; j++)printf("%d", e[j]);
				for(int j = 2; j <= 10; j++)printf(" %d", j + 1);
				puts("");
				
				ct++;
				if(ct == J)break;
			}
		}
	}


}

