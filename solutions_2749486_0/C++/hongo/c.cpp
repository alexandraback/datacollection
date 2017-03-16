#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

int main(){
	int t, c = 1;
	int x, y;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", c++);
		int a = x;
		if(a < 0) a = -a;
		int posy = 0, i = 0;
		if(x>0) for(i = 1; i < a; ++i) {printf("N"); posy+=i;}
		else for(i = 1; i < a; ++i) {printf("S"); posy-=i;}
		i = a+1;
		if(x>0) printf("E");
		else if(x < 0) printf("W");
		while(posy > y){
			if(posy-i >= y){
				posy-=i; i++; continue;
			}
			posy+=i++;
			printf("N");
			posy-=i++;
			printf("S");
		}
		while(posy < y){
			if(posy+i <= y){
				posy+=i; i++; continue;
			}
			posy-=i++;
			printf("S");
			posy+=i++;
			printf("N");
		}
		printf("\n");
	}

return 0;
}
