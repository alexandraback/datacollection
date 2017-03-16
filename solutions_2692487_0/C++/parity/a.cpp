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

int T;

int A, N, nnode;

vector<int> rest;

int D[11][9010];

vector<int> v;

int get_ans(int pos, int a){

	//printf("Asking %d %d\n", pos, a);

	if(pos >= nnode)	return 0;

	if(D[pos][a] >= 0)	return D[pos][a];

	int ret;

	int acc = 0;
	int aa = a;
	while(aa <= v[pos] && aa - 1){
		aa = -1 + (aa << 1);
		acc++;
	}

	int npos = pos;
	while(npos < nnode && v[npos] < aa){
		aa += v[npos];
		npos++;
	}

	if(npos - pos)
		ret = MIN(nnode - pos, get_ans(npos, aa) + acc);
	else
		ret = nnode - pos;
	return D[pos][a] = ret;

}

int main()
{
	scanf("%d", &T);

	for(int caseidx = 1; caseidx <= T; caseidx++){

		rest.clear();
		scanf("%d %d", &A, &N);

		for(int i = 0; i < N; i++){

			int x;
			scanf("%d", &x);
			rest.push_back(x);
		}

		sort(rest.begin(), rest.end());

		unsigned i;
		for(i = 0; i < rest.size(); i++){

			if(rest[i] >= A)
				break;

			A += rest[i];
		}

		int ans = rest.size() - i;

		v.clear();
		for(; i < rest.size(); i++)
			v.push_back(rest[i]);

		for(int i = 0; i < 10; i++)
			for(int j = 0; j <= 1000; j++)
				D[i][j] = -1;

		nnode = v.size();

		ans = get_ans(0, A);

		printf("Case #%d: %d\n", caseidx, ans);
	}

	return 0;
}

// vi: ts=2 sw=2
