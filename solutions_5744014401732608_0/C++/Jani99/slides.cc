#include <iostream>
#include <cstdio>
#include <string>
#include <vector>


unsigned long long pow2(unsigned n) {
	unsigned long long r = 1;
	while (n != 0) {
		r*=2;
		--n;
	}
	return r;
}

std::string base2(unsigned long long M1) {
	std::string r;
	while (M1>0) {
		r = std::string(1,'0'+(char)(M1%2)) + r;
		M1/=2;
	}
	return r;
}

int main(int argc, char **argv) {

	unsigned T;
	std::cin >> T;

	for (unsigned i=0; i<T; ++i) {

		unsigned long long B;
		std::cin >> B;

		unsigned long long M;
		std::cin >> M;

		printf("Case #%d: ",i+1);

		if (pow2(B-2)<M) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		std::string firstRow = base2(M-1) + "1";
		while (firstRow.length() < B) {
			firstRow = std::string("0") + firstRow;
		}
		printf("POSSIBLE\n%s\n",firstRow.c_str());

		for (unsigned j=0;j<B-1;++j) {
			for (unsigned k=0;k<B;++k) {
				if (k<j+2) {
					printf("0");
				} else {
					printf("1");
				}
			}
			printf("\n");
		}
	}

	return 0;
}








