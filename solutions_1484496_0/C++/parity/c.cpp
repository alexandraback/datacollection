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

long long x[30];

int N;

void print_set(long y){

	int start = 1;
	for(int i = 0; i < N; i++){

		if(1 & (y >> i)){
			if(!start)	printf(" ");
			start = 0;
			printf("%lld", x[i]);
		}
	}
	printf("\n");
}

int main()
{
	
	int T;

	scanf("%d", &T);

	for(int case_idx = 1; case_idx <= T; case_idx++){

		scanf("%d", &N);

		long long S = 0;
		for(int i = 0; i < N; i++){
			scanf("%lld", &x[i]);
			S += x[i];
		}

		map<long long, long> M;
		M.clear();

		printf("Case #%d:\n", case_idx);

		for(long i = 1; i < ((long)1 << N); i++){

			long long s = 0;
			for(int j = 0; j < N; j++){
				if(1 & (i >> j))
					s += x[j];
			}
			long long ss = S - s;

			map<long long, long>::iterator itr;
			itr = M.find(s);

			if(itr != M.end()){
				print_set(i);
				print_set(itr -> second);
				goto done;
			}
			itr = M.find(ss);
			if(itr != M.end()){
				print_set(i ^ (((long long)1 << N) - 1));
				print_set(itr -> second);
				goto done;
			}

			M[s] = i;
			M[ss] = i ^ (((long long)1 << N) - 1);

		}
		printf("Impossible\n");

done:
		;
	}
	return 0;
}

// vi: ts=2 sw=2
