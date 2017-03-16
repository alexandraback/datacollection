
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
    int T, R, N, M, K;
    int products[20];
    cin >> T >> R >> N >> M >> K;
    int haveit[6];
    printf("Case #1:\n");
    for (int i=0; i<R; i++) {
    	for (int n=2; n<=5; n++) haveit[n] = 0;
    	for (int j=0; j<K; j++) {
    		cin >> products[j];
    		int xd = products[j];
    		if (xd % 5 == 0) haveit[5] = 1;
    		if (xd % 3 == 0) haveit[3] = 1;
    		if (xd % 2 == 0) haveit[2] = 1;
    		if (xd % 25 == 0) haveit[5] = 2;
    		if (xd % 9 == 0) haveit[3] = 2;
    		if (xd % 4 == 0) haveit[2] = 2;
    		if (xd % 8 == 0) haveit[2] = 3; 
    		if (xd % 16 == 0) haveit[2] = 4; 
    		if (xd % 32 == 0) haveit[2] = 5; 
    		if (xd % 64 == 0) haveit[2] = 6; 
    	}
    	int count = 0;
    	if (haveit[5] == 1) {
    		printf("5");
    		count ++;
    	}
    	if (haveit[5] == 2) {
    		printf("55");
    		count += 2;
    	}
    	if (haveit[3] == 1) {
    		printf("3");
    		count ++;
    	}
    	if (haveit[3] == 2) {
    		printf("33");
    		count += 2;
    	}
    	if ((count == 2 && haveit[2] == 2) || (count == 1 && haveit[2] >= 3)) {
    		printf("4");
    		count ++;
    	}
    	else if (haveit[2] == 4) {
    		printf("44");
    		count += 2;
    	}else if (haveit[2] == 5) {
    		printf("442");
    		count = 3;
    	}else if (haveit[2] == 6){
    		printf("444");
    		count = 3;
    	}

    	for (int tt = 0; tt < 3 - count; tt++) {
    		printf("2");
    	}
    	printf("\n");
    }
    
    return 0;
}