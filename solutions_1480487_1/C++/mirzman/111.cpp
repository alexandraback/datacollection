#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory>
#include <string.h>
using namespace std;



int main()
{
    int nn;
    scanf("%d\n", &nn);
    for (int ii = 1; ii <= nn; ++ii) {
    	int n;
    	double p[10000];
    	double sum = 0;
    	scanf("%d", &n);
    	for (int i = 0; i < n; ++i) {
    		scanf("%lf", p + i);
    		sum += p[i];
    	}

    	printf("Case #%d:", ii);

    	int m = 0;
    	double sum2 = 0;
    	for (int i = 0; i < n; ++i) {
    		float v1 = 100.0 * (2.0 / double(n) - p[i] / sum);
    		if (v1 >= 0) {
    			++m;
    			sum2 += p[i];
    		}
    	}

    	for (int i = 0; i < n; ++i) {
    		double v1 = 100.0 * (2.0 / double(n) - p[i] / sum);
    		if (v1 < 0) {
    			v1 = 0;
    			//printf("#");
    		} else {
    			if (sum2 < 1e-4) {
    			    v1 = 100.0 / double(m);
    			} else {
    				v1 = 100.0 * ((1.0 + sum2 / sum) / double(m) - p[i] / sum);
    			}
    		}
    		printf(" %.8lf", v1);
    	}

    	printf("\n");
    }

	return 0;
}
