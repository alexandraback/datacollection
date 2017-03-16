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

long long A, N, nnode;

vector<long long> rest;

vector<long long> v;

long long ans;

void get_ans(long long pos, long long a, long long acc){

	if(pos >= nnode){
		ans = MIN(ans, acc);
		return;
	}

	ans = MIN(acc + nnode - pos, ans);

	bool change = false;
	while(a <= v[pos] && a - 1){
		a = (a << 1) - 1;
		acc++;
	}

	while(pos < nnode && v[pos] < a){
		a += v[pos];
		pos++;
		change = true;
	}

	if(change)
		get_ans(pos, a, acc);
}

int main()
{
	scanf("%d", &T);

	for(int caseidx = 1; caseidx <= T; caseidx++){

		rest.clear();
		scanf("%lld %lld", &A, &N);

		for(long long i = 0; i < N; i++){

			long long x;
			scanf("%lld", &x);
			rest.push_back(x);
		}

		sort(rest.begin(), rest.end());

		unsigned long long i;
		for(i = 0; i < rest.size(); i++){

			if(rest[i] >= A)
				break;

			A += rest[i];
		}

		ans = rest.size() - i;

		v.clear();
		for(; i < rest.size(); i++)
			v.push_back(rest[i]);

		nnode = v.size();

		get_ans(0, A, 0);

		printf("Case #%d: %lld\n", caseidx, ans);
	}

	return 0;
}

// vi: ts=2 sw=2
