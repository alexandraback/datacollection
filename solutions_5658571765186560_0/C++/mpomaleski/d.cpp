#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf(" %d", &t);
	
	for(int k = 1; k <= t; k++){
		int x, r, c;
		int res;
		scanf(" %d %d %d", &x, &r, &c);
		if(r > c)
			swap(r, c);
		switch (x){
			case 1:
				res = 0;
				break;
			case 2:
				res = (r*c)%2;
				break;
			case 3:
				if(r == 1 || (r*c)%3 != 0)
					res = 1;
				else 
					res = 0;
				break;
			case 4:
				if(r <= 2 || (r*c)%4 != 0)
					res = 1;
				else res = 0;
				break;
			case 5:
				if(r <= 2 || ((r == 3) && c == 5) || (r*c)%5 != 0)
					res = 1;
				else res = 0;
				break;
			case 6:
				if((r*c)%6 != 0 || r <= 3 || c < 6)
					res = 1; 
				else res = 0;
				break;
			default:
				res = 1;
				break;
		}
		if(res == 1)
			printf("Case #%d: RICHARD\n", k);
		else printf("Case #%d: GABRIEL\n", k);
	}
			
	return 0;
}