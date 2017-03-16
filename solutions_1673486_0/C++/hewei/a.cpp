//#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

double p[100<<10];
double pi[100<<10];

int A, B;


double f(int k) {
    if (k < 0) {
	return B+2;
    }
    return (2*B - A + 2) + (2*k - (B + 1)*pi[A-k]);
}

int main()
{
    int nCase;
    scanf("%d", &nCase);
    for (int iCase = 1; iCase <= nCase; ++iCase) {
	
	scanf("%d%d", &A, &B);
	pi[0] = 1;
	for (int i = 0; i < A; ++i) {
	    scanf("%lf", &p[i]);
	    pi[i+1] = pi[i]*p[i];
	}
	
	double m = 10000000;
	for (int k = -1; k <= A; ++k) {
	    m = min(m, f(k));
	}

	printf("Case #%d: %.6lf\n", iCase, m);
    }

    return 0;
}

