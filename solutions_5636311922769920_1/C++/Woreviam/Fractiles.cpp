
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		
		if(c == 1){
		
			if(s >= k){
				
				printf("Case #%d:", caso++);
				for(int i = 1; i <= k; i++)printf(" %d", i);
				puts("");
				
			}
			else printf("Case #%d: IMPOSSIBLE\n", caso++);
		}
		else{
			
			if(k == 1){
				
				printf("Case #%d: 1\n", caso++);
			}
			else{
				
				if(s >= k - 1){
					
					printf("Case #%d:", caso++);
					for(int i = 2; i <= k; i++)printf(" %d", i);
					puts("");
				}
				else printf("Case #%d: IMPOSSIBLE\n", caso++);
			}
			
		}
	}


}

