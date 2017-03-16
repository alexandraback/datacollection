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

int T, N, S, p;

int t;

int main()
{
	
	scanf("%d", &T);
	for(int case_idx = 1; case_idx <= T; case_idx++){

		scanf("%d", &N);
		scanf("%d", &S);
		scanf("%d", &p);

		int ret = 0;
		for(int i = 0; i < N; i++){
			scanf("%d", &t);

			int f = t / 3 + 1;
			if(t % 3 == 2)	f++;

			if((t + 2) / 3 >= p)	ret++;
			else if(f >= p && S && t){
				ret++;
				S--;
			}
		}

		printf("Case #%d: %d\n", case_idx, ret);

	}

	return 0;
}

// vi: ts=2 sw=2
