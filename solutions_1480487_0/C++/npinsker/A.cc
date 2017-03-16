#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>

#define INF 100000000
#define MAX 1048576

using namespace std;

int r, a, k[5000];

int main() {
    scanf("%d", &r);
    
    for (int z=0; z<r; ++z) {
	scanf("%d", &a);
	int sum = 0;
	
	for (int i=0; i<a; ++i) {
	    scanf("%d", &k[i]);
	    sum += k[i];
	}
	printf("Case #%d: ", z+1);
	for (int i=0; i<a; ++i) {
	    double low = 0., high = 1., mid;
	    double required;
	    
	    while (low < high - 1e-8) {
		mid = (low + high) / 2, required = 0;
		double toBeat = (double)k[i] + mid * sum;
		for (int j=0; j<a; ++j) {
		    if (i == j || k[j] >= toBeat) continue;
		    else required += (double)(toBeat - k[j]) / ((double)sum - mid*sum);
		}
		if (required > 1) high = mid;
		else low = mid;
	    }
	    printf("%lf%c", 100*low, (i < a-1 ? ' ' : '\n'));
	}
    }
   
    return 0;
}