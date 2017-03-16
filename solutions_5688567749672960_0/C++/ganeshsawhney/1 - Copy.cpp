#include <bits/stdc++.h>
#include <iostream>   // std::cout
#include <string>
int dop[1000010];
using namespace std;

int main() {

		memset(dop, 0x3f, sizeof dop);
	dop[1] = 1;
	for(int i = 1; i < 1000000; ++i) {
		std::string ert = std::to_string(i);
		std::reverse(ert.begin(), ert.end());
		int r = std::stoi(ert);
		dop[i+1] = std::min(dop[i+1], dop[i] + 1);
		dop[r] = std::min(dop[r], dop[i] + 1);
	}


	int n;
	cin>>n;
	int cas = 1,num;
	while(n--) {
		cin>>num;
		printf("Case #%d: %d\n", cas++, dop[num]);
	}
	return 0;
}
