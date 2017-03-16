#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[1010],b[2010], d[1010];
int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        cin>>s;
        int len = strlen(s);
        int answer = 0, maxChar = 0, e = 1, f = 1;
        for(int i= 0; i < 2005  ; i++) b[i] = -1;
        b[1001] = s[0];
        maxChar = s[0] - 65;
		for(int i= 1; i < len  ; i++) {
			if(s[i] - 65 >= maxChar) {
				maxChar = s[i] - 65;
				b[1001-e] = s[i]; 
				e++;
			} else	{
				b[1001+f] = s[i]; 
				f++;
			}	
	    }	

		printf("Case #%d: ",c++);
	    for(int i= 0; i < 2005  ; i++) {
		     if(b[i] != -1) {
		     	cout<<b[i];
		     }    	
		}
        printf("\n");
	}
	return 0;
}
