#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <strings.h>
#include <string.h>
using namespace std;

unsigned long long getNumber(unsigned long long first, unsigned long long req, unsigned long long k){
	if (req == 1)
		return first;
	unsigned long long current = k * (first - 1) + (first + 1);
	for (unsigned long long i = 2; i < req; i++){
		current = current * k + (first + i - k);	
	}
	return current;
}

int main(){
	unsigned long long tests;
	cin >> tests;
	for (unsigned long long t = 0; t < tests; t++){
		cout << "Case #" << (t+1) << ": ";
		unsigned long long K, C, S;
		cin >> K >> C >> S;
		unsigned long long required = K / C;
		if (K % C){
			required++;
		}
		if (required > S){
			cout << "IMPOSSIBLE" << endl;
		} else {
			unsigned long long current = 1;
			for (unsigned long long i = 0; i < required; i++){
				unsigned long long next = C;
				if (current + C - 1 > K){
					next = K - current + 1;
				}
				cout << getNumber(current, next, K) << " ";
				current += next;
			}
			cout << endl;
		}
	}
}
