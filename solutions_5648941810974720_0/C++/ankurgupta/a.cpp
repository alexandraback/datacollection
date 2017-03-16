#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[2501],dig[20], d[30];
char s[5010];
int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        cin>>s;
        int len = strlen(s);
        int answer = 0, maxChar = 0, e = 1, f = 1;
        for(int i= 0; i < 10  ; i++) dig[i] = 0;
        for(int i= 0; i < 29  ; i++) d[i] = 0;
        // ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE
        
        for(int i= 0; i < len  ; i++) {
        	if(s[i] == 'Z') {
			    dig[0]++;
			}   
        	else if(s[i] == 'X') dig[6]++;
        	else if(s[i] == 'G') dig[8]++;
        	else if(s[i] == 'U') dig[4]++;
        	else if(s[i] == 'W') dig[2]++;
        	d[(s[i]-65)]++;
        }
        dig[3] = d[7] - dig[8]; // THREE
        dig[5] = d[5] - dig[4]; // FIVE
        dig[9] = d[('I'-65)] - dig[5] - dig[6] - dig[8]; // FIVE
        dig[7] = d[('S'-65)] - dig[6]; // SEVEN
        dig[1] = d[('O'-65)] - dig[0] - dig[2] - dig[4]; // FIVE
        
        printf("Case #%d: ",c++);
	    for(int i= 0; i < 10  ; i++) {
		     while(dig[i] > 0) {
		     	cout<<i;
		     	dig[i]--;
		     }    	
		}
        printf("\n");
	}
	return 0;
}
