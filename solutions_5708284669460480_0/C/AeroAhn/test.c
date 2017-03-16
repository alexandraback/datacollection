#include <cstdio>
#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string strTarget;
string strKey;

int findPattern(){
	int i, j, k;
	int length;
	length = strTarget.length();
	for(i = 1; i < length; i++) {
		k = 0;
		for(j = i; j < length; j++, k++) {
			if (strTarget[j] != strTarget[k])
				break;
		}
		if (j == length)
			return i;
	}
	return 0;
}

double computeResult(int K, int L, int S){
	int key[256] = {0};
	int needs = 0;
	int i;
	int pattern;
	double expect = 1;
	double result;

	for(i = 0; i < K; i++) {
		key[((char)strKey[i])] += 1;
	}
	for(i = 0; i < S; i++) {
		if(key[strTarget[i]] == 0) {
			return 0.0;
		}
		expect *= ((double)key[strTarget[i]]) / (double)K;
	}

	pattern = findPattern();
	if (pattern == 0)
		needs = L / S;
	else {
		needs = (L - S + pattern) / pattern;
	}
	
	if (expect < 0.0000001)
		return needs;
	result = needs * (1 - expect);
	return result;
}

int main(void)
{
	int T;
	int K;
	int S;
	int L;
	double result;
	assert(scanf("%d", &T));

	for (int i = 0; i < T; i++) {
		assert(scanf("%d %d %d", &K, &L, &S));
		cin >> strKey;
		cin >> strTarget;

		result = computeResult(K, S, L);
		if (result == -0.0)
			result = 0.0;
		cout << "Case #" << i + 1 << ": " << result << endl;
	}
	return 0;
}
