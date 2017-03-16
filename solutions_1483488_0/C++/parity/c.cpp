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

long A, B;

int digits[11];

int get_ans(long x){

	int ndigit = 0;
	long y = x;

	long prod = 1;
	while(y){
		ndigit++;
		y /= 10;
		prod *= 10;
	}

	int ret = 0;

	y = x;
	set<long> S;
	for(int k = 1; k < ndigit; k++){

		int good = y % 10;

		y += prod * good;
		y /= 10;

		if(good && y > x && y <= B){
			//ret++; 
			//printf("%ld %ld\n", y, x);
			S.insert(y);
		}
	}

	//return ret;
	return S.size();
}

int main()
{
	
	int T;

	scanf("%d", &T);

	for(int case_idx = 1; case_idx <= T; case_idx++){

		scanf("%ld %ld", &A, &B);

		long ret = 0;

		long x = A;
		int ndigit = 0;
		while(x){
			digits[ndigit++] = x % 10;
			x /= 10;
		}

		for(long i = A; i < B; i++){

			ret += get_ans(i);

			/*
			int idx = 0;
			digits[0]++;
			while(digits[idx] >= 10){
				digits[idx] = 0;
				digits[++idx]++;
			}
			*/

		}

		printf("Case #%d: %ld\n", case_idx, ret);
	}
	return 0;
}

// vi: ts=2 sw=2
