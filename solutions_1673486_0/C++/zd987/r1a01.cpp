#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;

double p[4], re_min, re_tmp;
int T, A, B;

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &T);
	int i, j, k;
	double re_keep, re_enter;
	double correct, wrong, p_cur;
	for (i = 1; i <= T; i++) {
		scanf("%d%d", &A, &B);
		correct = 1;
		for (j = 1; j <= A; j++) {
			scanf("%lf", &p[j]);
			correct *= p[j];
		}
		p[0] = correct;
		re_keep = correct *(B - A + 1) + (1 - correct) * ((B - A) + B + 2);
		re_enter = B + 2;
		re_min = re_keep < re_enter ? re_keep : re_enter;
		correct = 1; wrong = 1;
		for (j = 1; j <= A; j++) {
			correct = 1;
			for (k = 1; k <= A - j; k++)
				correct *= p[k];
			re_tmp = (j * 2 + B - A + 1) * correct + (j * 2 + B - A + B + 2) * (1 - correct);
			if (re_tmp < re_min)
				re_min = re_tmp;
		}
		printf("Case #%d: %.6lf\n", i, re_min);
	}
	return 0;
}