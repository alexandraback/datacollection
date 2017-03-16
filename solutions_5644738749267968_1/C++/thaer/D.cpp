//============================================================================
// Name        : D.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>
#include <vector>
using namespace std;

int main() {
	freopen("output.txt", "w", stdout);
	int t, tc = 0;
	cin>>t;
	while (tc++ < t) {
	int N, i, j;
	cin>>N;
	double ken[N], naomi[N];
	for (i = 0; i < N; i++) cin>>naomi[i];
	for (i = 0; i < N; i++) cin>>ken[i];
	
	int kenWins = 0;
	int naomiWins = 0;
	
	bool kenValid[N], naomiValid[N];
	
	sort(naomi, naomi + N);
	sort(ken, ken + N);
	
	memset(naomiValid, false, sizeof(naomiValid));
	memset(kenValid, false, sizeof(kenValid));
	
	
	
	for (i = 0; i < N; i++) {
		bool found = false;
		for (j = 0; j < N; j++) {
			if (ken[j] > naomi[i] && !kenValid[j]) {
				kenValid[j] = true;
				kenWins++;
				found = true;
				break;
			}
		}
		if (!found) {
			for (int k = 0; k < N; k++)
				if (!kenValid[k]) {
					kenValid[k] = true;
					break;
				}
		}
	}
	//cout<<kenWins<<endl;
	int rev = N - 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (naomi[i] < ken[j] && !naomiValid[j]) {
				naomiValid[rev--] = true;
				break;
			} else if (naomiValid[j]) {
				continue;
			} else {
				naomiValid[j] = true;
				//cout<<naomi[i]<<" "<<ken[j]<<endl;
				naomiWins++;
				break;
			}
			
		}
	}
	//cout<<naomiWins<<endl;
	
	printf("Case #%d: %d %d\n", tc, naomiWins, N - kenWins);
	
	}
	return 0;
}