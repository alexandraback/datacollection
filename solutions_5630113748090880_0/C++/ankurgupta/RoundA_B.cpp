#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[2501],b[2010], d[1010];
int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        int n, b,index = 0;
        cin>>n;
        for(int i= 0; i < 2501  ; i++) a[i] = 0; 
        for(int i= 0; i < 2*n - 1 ; i++) {
           for(int j= 0; j < n  ; j++) {
           	  cin>> b;
           	  a[b]++;
           }
        }
        printf("Case #%d: ",c++);
	    for(int i= 0; i < 2501  ; i++) {
		     if(a[i] % 2 == 1) {
		     	cout<<i<<" ";
		     }    	
		}
        printf("\n");
	}
	return 0;
}
