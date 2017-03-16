#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<tr1/unordered_map>
#include<set>
#include<tr1/unordered_set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T;

long long A, B, K;

int main()
{

	cin >> T;

	for(int caseidx = 1; caseidx <= T; caseidx++){

		cin >> A >> B >> K;
		long long ret = 0;

		for(long long i = 0; i < A; i++){
			for(long long j = 0; j < B; j++){
				if((i & j) < K)
					ret++;
			}
		}

		printf("Case #%d: %lld\n", caseidx, ret);
	}
	return 0;
}

// vi: ts=2 sw=2
