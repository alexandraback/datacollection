#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;


int main() {
	int cases;
	int caseid = 1;
	int X, R, C;

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &cases);
	while(cases--) {

		scanf("%d%d%d", &X, &R, &C);

		if ( ((R * C) % X) != 0 || (X > R && X > C)) {
			printf("Case #%d: RICHARD\n", caseid++);
			continue;
		}
		switch (X) {
		case 1:
		case 2:
			printf("Case #%d: GABRIEL\n", caseid++);
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			if (R <= X / 2 || C <= X / 2) {
				printf("Case #%d: RICHARD\n", caseid++);
			}
			else {
				printf("Case #%d: GABRIEL\n", caseid++);
			}
			break;
		default:
			printf("Case #%d: RICHARD\n", caseid++);
			break;
		}
	}
	return 0;
}

