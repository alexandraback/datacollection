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

int E, R, N;
int v[10];

int ans[11][6];

int get_ans(int pos, int e){

	if(pos >= N)	return 0;

	if(ans[pos][e] >= 0)	return ans[pos][e];

	int ret = 0;

	for(int spend = 0; spend <= e; spend++){

		ret = MAX(ret, v[pos] * spend + get_ans(pos + 1, MIN(E, e - spend + R)));
	}

	return ans[pos][e] = ret;
}

int main()
{
	
	scanf("%d", &T);

	for(int caseidx = 1; caseidx <= T; caseidx++){

		scanf("%d %d %d", &E, &R, &N);

		for(int i = 0; i < N; i++)
			scanf("%d", &v[i]);

		for(int i = 0; i < N; i++)
			for(int j = 0; j <= E; j++)
				ans[i][j] = -1;

		printf("Case #%d: %d\n", caseidx, get_ans(0, E));

	}

	return 0;
}

// vi: ts=2 sw=2
