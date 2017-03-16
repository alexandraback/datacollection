
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 55

using namespace std;

int M[N][N];

int main(){

	int tc = 0,caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int b;
		long long m;
		scanf("%d%lld", &b, &m);
		
		memset(M, 0, sizeof M);
		vector<int>ans;
		
		if(m == (1LL<<(b - 2))){
			
			printf("Case #%d: POSSIBLE\n", caso++);
			for(int i = 1; i <= b; i++){
				for(int j = 1; j <= b; j++){
					
					if(j <= i)printf("0");
					else{
						
						if(i < b)printf("1");
						else printf("0");
					}
				}
				puts("");
			}
		}
		else{
			
			int last = b;
			M[1][b] = 1;
			m--;
			
			for(int i = 0; i < 62; i++)
				if((m>>i)&1LL)ans.pb(b - 1 - i), last = b - 1 - i;
			
				
				if(last <= 1)printf("Case #%d: IMPOSSIBLE\n", caso++);
				else{
					
					for(int i = 0; i < ans.size(); i++)M[1][ans[i]] = 1;
					
					for(int i = last; i < b; i++){
						for(int j = 1; j <= b; j++){
							
							
							if(j <= i)M[i][j] = 0;
							else M[i][j] = 1;
						}
					}
					/*
					for(int i = ans.size() - 1; i >= 0; i--){
						
						for(int j = ans[i] + 1; j <= b; j++)M[ans[i]][j] = 1;
					}
					*/
					
					printf("Case #%d: POSSIBLE\n", caso++);
					
					for(int i = 1; i <= b; i++){
						for(int j = 1; j <= b; j++){
							
							printf("%d", M[i][j]);	
						}
						puts("");
					}	
				}
			}
			
	}


}

