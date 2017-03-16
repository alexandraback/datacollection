#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 64
#define JJ 511

int t, N, J;
int64_t pows[11];
vector<char> binary;

void print_binary(int i)
{
	binary.clear();
	binary.reserve(33);
	while (i != 0) {
		if (i % 2) {
			binary.push_back('1');
		} else {
			binary.push_back('0');
		}
		i >>= 1;
	}
	if (binary.empty()) {
		binary.push_back('0');
	}
	reverse(binary.begin(), binary.end());
	binary.push_back('\0');
	printf("%s%s", binary.data(), binary.data());
}

int main()
{
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		printf("Case #%d:\n", ti+1);
		scanf("%d%d", &N, &J);
		int K = N/2;
		int K2 = (N+1)/2;
		int fr = (1 << (K-1)) + 1;
		for (int b = 1; b < 11; ++b) {
			int64_t pow = 1;
			for (int k = 0; k < K2; ++k) {
				pow *= b;
			}
			pows[b] = pow + 1;
		}
		for (int i = 0; i < J; ++i) {
			print_binary(fr + i*2);
			for (int b = 2; b < 11; ++b) {
				printf(" %lld", pows[b]);
			}
			printf("\n");
		}
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
