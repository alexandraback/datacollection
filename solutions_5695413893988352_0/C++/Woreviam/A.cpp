
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

char C[N], J[N];
char aux1[N], aux2[N];

int main(){
	
	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%s %s", C, J);
		
		int val1 = 0, val2 = 0;
		int n = strlen(C), pr = -1, pl = -1;
		
		for(int i = 0; i < n; i++){
			
			if(C[i] != '?' && J[i] != '?' && C[i] != J[i]){
				
				pr = i;
				break;
			}
		}

		for(int i = 0; i < pr - 1; i++){
					
			if(C[i] == '?' && J[i] == '?')C[i] = J[i] = '0';
			else{
						
				if(C[i] == '?')C[i] = J[i];
				if(J[i] == '?')J[i] = C[i];	
			}
		}
		
		long long ans1 = 0, ans2 = 0, dif = (1ULL<<62) - 1;
	
		if(pr != -1){
			
			
			//igualdad en (pr - 1)
			for(int i = pr; i < n; i++){
					
				if(C[i] != '?')ans1 = ans1 * 10 + C[i] - '0';
				if(J[i] != '?')ans2 = ans2 * 10 + J[i] - '0';
					
				if(C[pr] > J[pr]){
						
					if(C[i] == '?')ans1 = ans1 * 10;
					if(J[i] == '?')ans2 = ans2 * 10 + 9;
				}
				else{
						
					if(C[i] == '?')ans1 = ans1 * 10 + 9;
					if(J[i] == '?')ans2 = ans2 * 10;	
				}
			}
			
			dif = abs(ans1 - ans2);
			//cout2("diff: ", dif);
			
			if(pr > 0){
				
				int sw = 0;
				if(C[pr] < J[pr]){
					
					sw = 1;
					swap(C[pr], J[pr]);
					swap(C[pr - 1], J[pr - 1]);
				}
				
				if(C[pr] > J[pr]){
					
					if(J[pr - 1] == '?' && C[pr - 1] == '?'){
						
						aux1[pr - 1] = '0';
						aux2[pr - 1] = '1';
					}
					else{
						
						if(C[pr - 1] == '?'){
							
							aux1[pr - 1] = char('0' + max(0, J[pr - 1] - '0' - 1));
							aux2[pr - 1] = J[pr - 1];
						}
						else{
							
							aux1[pr - 1] = C[pr - 1];
							aux2[pr - 1] = char('0' + min(9, C[pr - 1] - '0' + 1));
						}	
					}
					
					aux1[pr] = C[pr];
					aux2[pr] = J[pr];
					
					ans1 = aux1[pr - 1] - '0';
					ans2 = aux2[pr - 1] - '0';

					ans1 = ans1 * 10 + C[pr] - '0';
					ans2 = ans2 * 10 + J[pr] - '0';
					
					int g1 = 0, g2 = 0;
					if(ans1 > ans2)g1 = 1;
					else g2 = 1;
					
					for(int i = pr + 1; i < n; i++){
					
						if(g1 > g2){
							
							if(C[i] == '?')ans1 = ans1 * 10, aux1[i] = '0';
							else ans1 = ans1 * 10 + C[i] - '0', aux1[i] = C[i];
							
							if(J[i] == '?')ans2 = ans2 * 10 + 9, aux2[i] = '9';
							else ans2 = ans2 * 10 + J[i] - '0', aux2[i] = J[i];
						}
						else{
							
							if(C[i] == '?')ans1 = ans1 * 10 + 9, aux1[i] = '9';
							else ans1 = ans1 * 10 + C[i] - '0', aux1[i] = C[i];
							
							if(J[i] == '?')ans2 = ans2 * 10, aux2[i] = '0';
							else ans2 = ans2 * 10 + J[i] - '0', aux2[i] = J[i];	
						}
					}				
				}
				
				//cout2(abs(ans1 - ans2), dif);
				if(sw){
					
					swap(aux1, aux2);
					swap(C[pr], J[pr]);
					swap(C[pr - 1], J[pr - 1]);
				}
						
				if(dif > abs(ans1 - ans2)){
						
					for(int i = pr - 1; i < n; i++){
							
						C[i] = aux1[i];
						J[i] = aux2[i];
					}	
				}
				else{
					
					if(pr > 0){
						
						if(C[pr - 1] == '?' && J[pr - 1] == '?')C[pr - 1] = J[pr - 1] = '0';
						else{
						
							if(C[pr - 1] == '?')C[pr - 1] = J[pr - 1];
							if(J[pr - 1] == '?')J[pr - 1] = C[pr - 1];
						}
					}
					
					for(int i = pr; i < n; i++){
						
						if(C[pr] > J[pr]){
								
							if(C[i] == '?')C[i] = '0';//ans1 = ans1 * 10;
							if(J[i] == '?')J[i] = '9';//ans2 = ans2 * 10 + 9;
						}
						else{
								
							if(C[i] == '?')C[i] = '9';
							if(J[i] == '?')J[i] = '0';	
						}
					}
				}
			}
			else{
			
				for(int i = pr; i < n; i++){
					
					if(C[pr] > J[pr]){
								
						if(C[i] == '?')C[i] = '0';//ans1 = ans1 * 10;
						if(J[i] == '?')J[i] = '9';//ans2 = ans2 * 10 + 9;
					}
					else{
								
						if(C[i] == '?')C[i] = '9';
						if(J[i] == '?')J[i] = '0';	
					}
				}
			}
		}
		else{
			
			for(int i = 0; i < n; i++){
				
				if(C[i] == '?' && J[i] == '?')C[i] = J[i] = '0';
				else{
					
					if(C[i] == '?')C[i] = J[i];
					if(J[i] == '?')J[i] = C[i];	
				}
			}
		}
		
		
		printf("Case #%d: %s %s\n", caso++, C, J);
		
	}

}


