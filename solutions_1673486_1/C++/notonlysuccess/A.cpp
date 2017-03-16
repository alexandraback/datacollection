#include <cstdio>
#include <cstdlib>
#include <string>
#include <climits>
#include <iostream>   
#include <vector>
#include <set>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 111111;
double func(int C,int A,int B,int op) {
	if (op == 0) {
		if (C == A) {
			return B - A + 1;
		} else {
			return B - A + 1 + B + 1;
		}
	} else {
		return B + 2;
	}
}
int main() {
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int T ;
	scanf("%d",&T);
	for (int cas = 1 ; cas <= T ; cas ++) {
		int A , B;
		scanf("%d%d",&A,&B);
		double x = 1;
		double a = 0 , b = 0 , c = 0 , bb = 1e20;
		for (int i = 0 ; i <= A ; i ++) {
			double p;
			double pp;
			if (i == A) {
				pp = x;
			} else {
				scanf("%lf",&p);
				pp = x * (1 - p);
				x *= p;
			}
			
			
			a += pp * func(i , A , B , 0);
	//		b += pp * func(i , A , B , 1);
			c += pp * func(i , A , B , 2);
			if (i == 0) {
				b = B - A + (A - i) * 2 + 1;
	//			cout << b << endl;
			}
			
			if (b < bb) bb = b;
			if (i < A - 1) {
				b = (B - A + (A - i - 1) * 2 + 1) * x + (B - A + (A - i - 1) * 2 + 1 + B + 1) * (1 - x);
	//			cout << b << endl;
				
			}
			
			if (b < bb) bb = b;

		}
		printf("Case #%d: %.6lf\n" , cas , min(a , min(bb , c)));
	}
	return 0;
}