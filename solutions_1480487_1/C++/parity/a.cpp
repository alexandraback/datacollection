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

double J[200], X, ans[200];

int win[201];

int main()
{
	
	int T, N;

	scanf("%d", &T);

	for(int case_idx = 1; case_idx <= T; case_idx++){

		scanf("%d", &N);

		X = 0;
		for(int i = 0; i < N; i++){
			scanf("%lf", &J[i]);
			X += J[i];
		}
		memset(win, 0, sizeof(win));

		int rem = N;

		double cur = X * 2;
		while(rem){

			int trem = rem;
			double tcur = cur;

			int change = 0;
			for(int i = 0; i < N; i++){
				if(win[i])	continue;

				if(J[i] * trem >= tcur){

					win[i] = 1;
					ans[i] = 0;
					rem--;
					cur -= J[i];
					change = 1;
				}
			}

			if(!change){

				for(int i = 0; i < N; i++){
					if(win[i])	continue;

					ans[i] = (cur / double(rem) - J[i]) / X;
				}

				break;
			}

		}//while rem

		printf("Case #%d:", case_idx);
		for(int i = 0; i < N; i++){
			printf(" %lf", ans[i] * 100);
		}
		printf("\n");

	}// for each case

	return 0;
}

// vi: ts=2 sw=2
