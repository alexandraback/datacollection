#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <map>
typedef long long int LLI;
using namespace std;

LLI E, R, N;
LLI V[20000];
bool compare(LLI a, LLI b)
{
	return a > b;
}

void input()
{
	scanf("%lld %lld %lld", &E, &R, &N);
	for (int i = 0 ; i < N ; i++) {
		scanf("%lld", &V[i]);
	}
	//sort(V, V + N ,compare);
}

LLI solve()
{
	LLI result = 0;

	LLI C_ = E;
	
	for (int i = 0 ; i < N ; i++) {
		LLI TMPC = 0;
		LLI COST = 0;
		LLI TMPC_ = R;
		
		bool FINDMAX = true;
		for (int j = i + 1 ; j < N ; j++) {
			if (V[i] <= V[j]) {
				FINDMAX = false;
				COST = TMPC_ + C_ - E;
				if (COST < 0)
					COST = 0;
				break;
			}
			TMPC_ += R;
			if (TMPC_ > E) break;
		}

		if (FINDMAX) {
			result += V[i] * C_;
			C_=0;
		} else {
			result += COST * V[i];
			C_ -= COST;
		}

		C_ = C_ + R > E ? E : C_ + R;
	}
	
	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	for (int i = 0 ; i < n ; i++) {
		input();
		printf("Case #%d: %lld\n", i + 1, solve());
	}

	return 0 ;
}