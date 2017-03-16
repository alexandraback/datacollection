#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <ctime>

using namespace std;
FILE *fin  = fopen("a.in", "r");
FILE *fout = fopen("gcj-a.out", "w");

int main () {
    int T, R, C, W;
	fscanf(fin, "%d", &T);
	for(int t = 1; t <= T; t++) {
		fscanf(fin, "%d %d %d", &R, &C, &W);
		fprintf(fout, "Case #%d: %d\n", t, R * (C / W) + W - ((C % W == 0)? 1:0));
		printf("Case #%d: %d\n", t, R * (C / W) + W - ((C % W == 0)? 1:0));
	}
	return 0;
}
