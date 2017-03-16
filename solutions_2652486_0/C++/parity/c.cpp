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

int M, N, R, K, X;

int prod[10];

int times[10];

vector<int> ans;

void analyze(int p){

	for(int k = 0; k < K; k++){

		int x = prod[k];

		int acc = 0;
		while(!(x % p)){
			x /= p;
			acc++;
		}

		times[p] = MAX(times[p], acc);
	}

	if(p == 3 || p == 5)
		for(int i = 0; i < times[p]; i++)
			ans.push_back(p);
}

void guess(){

	memset(times, 0, sizeof(times));

	ans.clear();
	analyze(3);
	analyze(5);
	analyze(2);

	if(ans.size() == N)	return;

	if(ans.size() + (times[2] >> 1) == N){
		for(int i = 0; i < (times[2] >> 1); i++)
			ans.push_back(4);

		return;
	}

	if(ans.size() == N - 1){
		ans.push_back(times[2] >= 2 ? 4: 2);
	}
}

int main()
{
	scanf("%d", &T);
	
	for(int caseidx = 1; caseidx <= T; caseidx++){

		scanf("%d %d %d %d", &R, &N, &M, &K);

		printf("Case #%d:\n", caseidx);

		for(int r = 0; r < R; r++){

			for(int k = 0; k < K; k++){
				scanf("%d", &prod[k]);
			}
			
			guess();

			int c = 0;
			for(unsigned i = 0; i < ans.size(); i++, c++)
				printf("%d", ans[i]);
			for(; c < N; c++)
				printf("2");

			printf("\n");
		}
	}

	return 0;
}

// vi: ts=2 sw=2
