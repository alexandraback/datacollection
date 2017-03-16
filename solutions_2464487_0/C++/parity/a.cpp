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
#include<cassert>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T;

long long r, t;

int main()
{
	
	scanf("%d", &T);

	for(int caseidx = 1; caseidx <= T; caseidx++){

		scanf("%lld %lld", &r, &t);


		double rr = r;
		double tt = t;

		double x = (1. - 2 * rr + sqrt(8. * tt + (2. * rr - 1) * (2. * rr - 1))) / 4.;

		long long ret;

		for(ret = x - 2; ret <= x + 2; ret++){
			long long y = ret * (1 + 2 * r + 2 * (ret - 1)) - t;

			if(y > 0)
				break;
		}
		ret--;

		printf("Case #%d: %lld\n", caseidx, ret);
	}


	return 0;
}

// vi: ts=2 sw=2
