#include <bits/stdc++.h>
using namespace std;

#define q(i,j) quat[8*i+j]

/*  1 = 0
 *  i = 1
 *  j = 2
 *  k = 3
 * -1 = 4
 * -i = 5
 * -j = 6
 * -k = 7
 */

int quat[64] = { 	0, 1, 2, 3, 4, 5, 6, 7, 
									1, 4, 3, 6, 5, 0, 7, 2,
									2, 7, 4, 1, 6, 3, 0, 5,
									3, 2, 5, 4, 7, 6, 1, 0,
									4, 5, 6, 7, 0, 1, 2, 3, 
									5, 0, 7, 2, 1, 4, 3, 6,
									6, 3, 0, 5, 2, 7, 4, 1,
									7, 6, 1, 0, 3, 2, 5, 4 };

char buf[10010];
int str[10010];
									
int main(){
	int t, l;
	long long int x;
	
	scanf(" %d", &t);
	
	for(int k = 1; k <= t; k++){
		scanf(" %d %lld", &l, &x);
		scanf(" %s", buf);
		
		int valStr = 0;
		
		for(int i = 0; i < l; i++){
			if(buf[i] == '1')
				str[i] = 0;
			else str[i] = 1 + buf[i]-'i';
			
			valStr = q(valStr,str[i]);
		}
		int val = 0, test = 2;
		int j;
		for(j = 0; j < min(x,(long long int)8); j++){
			if(test == 0)
				break;
			for(int i = 0; i < l; i++){
				val = q(val,str[i]);
				if(test == 2 && val == 1){
					test = 1;
					val = 0;
				} else if(test == 1 && val == 2){
					test = 0;
					val = 0;
				}
			}
		}
		if(test == 0){
			x-=j;
			for(j = 0; j < x%4; j++){
				val = q(val,valStr);
			}
			if(val == 3){
				printf("Case #%d: YES\n", k);
			} else printf("Case #%d: NO\n", k);
		} else printf("Case #%d: NO\n", k);
	}
	
	return 0;
}