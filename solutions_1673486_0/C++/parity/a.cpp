#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

double p[100000];

int main()
{
	
	int T;
	scanf("%d", &T);

	double A, B, P;

	for(int t = 1; t <= T; t++){

		scanf("%lf %lf", &A, &B);
		double ret = B + 2;

		p[0] = 1;
		for(long i = 1; i <= A; i++){
			scanf("%lf", &P);
			p[i] = p[i - 1] * P;
		}

		for(long k = A; k; k--){

			ret = MIN(ret, B - A + 1 + 2 * (A - k) + (1 - p[k]) * (B + 1));
		}

		printf("Case #%d: %lf\n", t, ret);
	}

	return 0;
}

// vi: ts=2 sw=2
