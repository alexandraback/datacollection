#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	int n, x, a[2550], b[100], k = 0;
    	for(int j = 0; j < 2550; j++){
    		a[j] = 0;
    	}
    	cin >> n;
    	for(int j = 0; j < (2*n*n - n); j++){
    		cin >> x;
    		a[x]++;
    	}
    	for(int j = 1; j <= 2500; j++){
    		if(a[j] != 0 && a[j] % 2 != 0){
   				b[k++] = j; 			
       		}
    	}
    	printf("Case #%d: ", i);
    	for(int j = 0; j < k - 1; j++)
    		cout << b[j] << " ";
    	cout << b[k - 1] << endl;
    }
	return 0;
}
