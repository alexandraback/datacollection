#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string C, J;

void input()
{
	cin >> C >> J;
}

bool match(int x, string X) {
	for (int i=X.length()-1; i >=0; --i) {
		int d = x%10;
		x /= 10;
		if (X[i] == '?') continue;
		if (X[i] != '0' + d) return false;
		
	}
	return true;
}

void solv()
{
	int len = C.length();
	int state = 0; // -1: C > J, 0: C = J, 1 C < J
	int limit = 1;
	
	for (int i=0;i<C.length();++i) limit *= 10;

	int minD = limit;
	int resC, resJ;
	
	for (int c=0;c<limit;++c) {
		if (!match(c, C)) continue;
		for (int j=0;j<limit; ++j) {
			if (!match(j, J)) continue;
			int d = abs(c-j);
			if (d < minD) {
				minD = d;
				resC = c;
				resJ = j;
			}
		}
	}
	printf("%0*d %0*d\n", len, resC, len, resJ);
}

int main()
{
	int T, nCase = 1;
	cin >> T;
	for (nCase = 1; nCase <= T; ++nCase) {
		input();
		
		printf("Case #%d: ", nCase);
		solv();
	}
	
	return 0;
}