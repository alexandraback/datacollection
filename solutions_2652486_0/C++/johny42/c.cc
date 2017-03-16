#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> prod[6][6][6];
int res[7];

int main() {
	int q1,q2,q3,q4,q5;
	scanf("%d %d %d %d %d", &q1, &q2, &q3, &q4, &q5);
	
	printf("Case #1:\n");
	
	for (int a = 2; a <= 5; ++a)
		for (int b = a; b <= 5; ++b)
			for (int c = b; c <= 5; ++c) {
				for (int i = 1; i <= 125; ++i) {
					prod[a][b][c][i] = 0;
				}
				++prod[a][b][c][a];
				++prod[a][b][c][b];
				++prod[a][b][c][c];
				++prod[a][b][c][a*b];
				++prod[a][b][c][a*c];
				++prod[a][b][c][b*c];
				++prod[a][b][c][a*b*c];
				++prod[a][b][c][1];
			}
	
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 7; ++j) {
			scanf("%d", &res[j]);
		}
		
		int xa, xb, xc;
		long double xp = -1;
		
		for (int a = 2; a <= 5; ++a)
			for (int b = a; b <= 5; ++b)
				for (int c = b; c <= 5; ++c) {
					long double p = 1;
					for (int j = 0; j < 7; ++j) {
						p *= prod[a][b][c][res[j]]/8.0;
					}
					//printf("prob[%d][%d][%d] = %Lf\n", a, b, c, p);
					if (p > xp) {
						xa=a;xb=b;xc=c;xp=p;
					}
				}
		
		printf("%d%d%d\n", xa, xb, xc);
	}
}
