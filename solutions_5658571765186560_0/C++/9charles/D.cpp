#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define INF 1000000000
 
int T, X, R, C;
char resp[1111];
//"GABRIEL" "RICHARD"
int main(){
	scanf("%d", &T);
	for(int caso=1; caso<=T; caso++){
		scanf("%d %d %d", &X, &R, &C);
		if(X==1){
			strcpy(resp, "GABRIEL");
		}	
		else if(X==2){
			if(R%2 && C%2) strcpy(resp, "RICHARD");
			else strcpy(resp, "GABRIEL");
		}
		else if(X==3){
			if(R!=3 && C!=3){
				strcpy(resp, "RICHARD");
			}
			else{
				if(R!=3){
					swap(R, C);			
				}
				if(C==1) strcpy(resp, "RICHARD");
				else strcpy(resp, "GABRIEL");
			}
		}
		else{
			if(R<4 && C<4) strcpy(resp, "RICHARD");
			else{
				if(R<4){
					swap(R, C);
				}
				if(C<=2){
					strcpy(resp, "RICHARD");
				}
				else{
					strcpy(resp, "GABRIEL");
				}	
			}
		}
		printf("Case #%d: %s\n", caso, resp);	
	}		
	return 0;
}

