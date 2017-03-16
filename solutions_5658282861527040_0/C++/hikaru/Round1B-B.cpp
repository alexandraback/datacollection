#include <fstream>
#include <vector>
#include <deque>
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <algorithm>

struct C
{
	char c;
	int  len;
	C(char c_, int len_) : c(c_), len(len_) {}
};

int main(int argc, char* argv[])
{
	std::ifstream fin(argv[1]);

	int T;
	fin >> T;
	for (int t=1; t<=T; t++) {
		int A, B, K;
		fin >> A >> B >> K;

		std::multiset<int> x;
		for (int a=0; a<A; a++) {
			for (int b=0; b<B; b++) {
				x.insert(a&b);
			}
		}
		int result=0;
		for (auto it=x.begin(); it!=x.end(); ++it) {
			if (*it >= K) break;
			result++;
		}

		printf("Case #%d: %d\n", t, result);
	}

	return 0;
}
