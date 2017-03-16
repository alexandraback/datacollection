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

int d[50];

int T;

vector<long long>a;

int is_pa(long long x){

	int idx = 0;

	while(x){
		d[idx++] = x % 10;
		x /= 10;
	}


	for(int i = 0; (i << 1) < idx; i++){
		if(d[i] - d[idx - 1 - i])
			return 0;
	}

	return 1;
}

long long A, B;

int get_pos(long long x){
	int ret = 0;
	for(unsigned i = 0; i < a.size(); i++){
		if(a[i] <= x)
			ret++;
		else
			return ret;
	}

	return ret;
}

int main()
{

	scanf("%d", &T);

	a.push_back(1);
	for(long long i = 2; i <= 10000000; i++){

		long long j = i * i;
		if(is_pa(i) && is_pa(j)){
			a.push_back(j);
		}
	}


	for(int caseidx = 1; caseidx <= T; caseidx++){

		scanf("%lld %lld", &A, &B);

		printf("Case #%d: %d\n", caseidx, get_pos(B) - get_pos(A - 1));
	}

	return 0;
}

// vi: ts=2 sw=2
