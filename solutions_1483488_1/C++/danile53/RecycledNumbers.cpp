/*
 * Google Code Jam
 * Qualification Round 2012
 * Problem C. Recycled Numbers
 */

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int power[7] = {1,10,100,1000,10000,100000,1000000};

int main() {
	int prev[2000001];
	memset(prev,0,sizeof(prev));
	// fill
	for (int i = 10; i <= 2000000; i++) {
		int p = log(i) / log(10);
		int j = i;
		for (int k=1; k<=p; k++){
			j = (j % power[p]) * 10 + (j / power[p]);
			if (j < i && j > prev[i])
				prev[i] = j;
		}
	}
	// read
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int a, b;
		cin >> a >> b;
		// count
		int sol = 0;
		for (int i=a+1; i<=b; i++){
			int j = prev[i];
			while (j >= a){
				sol++;
				j = prev[j];
			}
		}
		printf("Case #%d: %d\n",t,sol);
	}
	return 0;
}
