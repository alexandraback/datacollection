#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main () {
	
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
    	int x, y;
    	cin >> x >> y;
    	printf("Case #%d: ", t);
    	if (x >= 0) {
    		for (int i=1; i<=x; i++) {
    			printf("WE");
    		}
    	}else{
    		for (int i=-1; i>=x; i--) {
    			printf("EW");
    		}
    	}
    	if (y >= 0) {
    		for (int i=1; i<=y; i++) {
    			printf("SN");
    		}
    	}else{
    		for (int i=-1; i>=y; i--) {
    			printf("NS");
    		}
    	}
    	printf("\n");
    }
    return 0;
}