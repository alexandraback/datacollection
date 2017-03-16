#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t; cin >> t;
	for(int k = 1; k <= t; k++) {
		int r, c, w;
		cin >> r >> c >> w;
		int init = c / w;
		int moves = init + w;
		if(c % w == 0) moves--;
		moves *= r;
		printf("Case #%d: %d\n", k, moves);
	}
}
