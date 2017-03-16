#include <iostream>
#include <cstdio>
using namespace std;
#define forn(i,n) for(int i=0; i<(int)(n); i++)
typedef long long tint;


int main(){
	int t; cin>>t;
	int caso=0;
	while(t>0){
		t--;
		caso++;
		int x, y; cin>>x>>y;
		printf("Case #%d: ", caso);
		
		if(x>0)while(x>0){
			printf("WE"); x--;
		}
		else while(x<0){
			printf("EW"); x++;			
		}
		if(y>0)while(y>0){
			printf("SN"); y--;
		}
		else while(y<0){
			printf("NS"); y++;			
		}
		printf("\n");
	}
}
