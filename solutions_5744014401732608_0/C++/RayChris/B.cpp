#include <string>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <fstream>

using namespace std;

#define PQ priority_queue
typedef long long LL;
typedef pair<LL,LL> pll;

int T,B;
LL M;
bool tab[51][51];

int main() {
	ifstream F;
	F.open ("B-small-attempt0.in");
	ofstream O;
	O.open ("B_out.txt");

	F >> T;
	for (int i=1;i<=T;i++) {
		O << "Case #" << i << ": ";
		F >> B >> M;
		LL res = M;
		for (int j=0;j<B;j++)
			for (int k=0;k<B;k++)
				tab[j][k] = 0;

		res --;
		tab[0][B-1] = 1;
		for (int j=1;j<B-1;j++) {
			if (res==0) break;
			tab[0][j] = 1;
			int tmp;
			if (res>(1<<(j-1))) tmp = 1<<(j-1);
			else tmp = res;
			//O << j << " " << res << endl;
			res -= tmp;
			tmp--;
			tab[j][B-1] = 1;
			int pos = 1;
			while (tmp>0) {
				if (tmp%2==1) tab[j][pos] = 1;
				pos++;
				tmp/=2;
			}
		}
		if (res>0) {
			O << "IMPOSSIBLE\n";
			continue;
		}
		O << "POSSIBLE\n";
		for (int j=0;j<B;j++) {
			for (int k=0;k<B;k++) O << tab[j][k];
			O << endl;
		}
	}
	return 0;
}
