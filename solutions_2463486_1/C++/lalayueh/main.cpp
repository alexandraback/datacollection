#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
vector<double> T;
double A;
double B;

void input()
{
	scanf("%lf %lf\n", &A, &B);
	//printf("%lf %lf\n", A, B);
}

bool check(double d) 
{
	char tmp[1024];
	sprintf(tmp, "%.0lf", d);
	int length = strlen(tmp);
	for (int i = 0 ; i < length / 2 ; i++) {
		if (tmp[i] != tmp[length - i - 1]) {
			return false;
		}
	}

	return true;
}

int solve()
{
	int result = 0;
	for (size_t i = 0 ; i < T.size() ; i++) {
		if (T[i] > B) {
			break;
		} else if (B >= T[i] && T[i] >= A) {
			result++;
		}
	}

	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	for (double d = 1.0 ; d < 10000000.0 ; d = d + 1.0) {
		if (check(d)) {
			double val = pow(d, 2);
			if (check(val)) {
				T.push_back(val);
			}
		}
	}

	

	int nCase;
	scanf("%d\n", &nCase);
	for (int i = 0 ; i < nCase ; i++) {
		input();
		printf("Case #%d: %d\n", i + 1, solve());
	}

	return 0 ;
}