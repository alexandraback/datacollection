#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
		int N;
		cin >> N;

		vector<int> counts(10000,0);

		for (int i=0;i<2*N-1;i++) {
			for (int j=0;j<N;j++) {
				int h;
				cin >> h;
				if (h >= counts.size()) counts.resize(h+1,0);
				counts[h]++;
			}
		}

    printf("Case #%d:", t);
		for (int i=0;i<counts.size();i++) {
			if (counts[i]%2==1) printf(" %d", i);
		}

		printf("\n");
  }

}
