#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
double c, f, x;

int main() {
	freopen("B-large.in", "r", stdin);
		freopen("B-large.out", "w", stdout);
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca ++ ) {
		scanf("%lf%lf%lf", &c, &f, &x);
		double ti = 0;
		int n = 0;
		while (1) {
  			  if (x / (f * (n + 1) + 2) + c / (f * n + 2) < x / (f * n + 2)) 
  			  	 ti += c / (f * n + 2), n ++ ;
	          else break;
        }
        printf("Case #%d: %.9f\n", ca, ti + x / (f * n + 2));
	}
	//system("pause");
	return 0;	
}