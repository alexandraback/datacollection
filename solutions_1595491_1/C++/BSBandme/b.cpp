/*
 * b.cpp
 *
 *  Created on: 2012-4-14
 *      Author: cj
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>

using namespace std;

int ncase, nsu, p, nhave, nwill, n;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &ncase);
	for(int i = 0; i < ncase; i++){
		nhave = 0; nwill = 0;
		scanf("%d%d%d", &n, &nsu, &p);
		for(int j = 0; j < n; j++){
			int num;
			scanf("%d", &num);
			int now = num / 3 + bool(num % 3);
			int will = now;
			if(num % 3 == 0 && num != 0) will++;
			if(num % 3 == 2 ) will++;
			if(now >= p) nhave++;
			else if(will >= p) nwill++;
		}
		printf("Case #%d: %d\n", i + 1,  nhave + (nsu < nwill ? nsu : nwill));
	}
	return 0;
}




