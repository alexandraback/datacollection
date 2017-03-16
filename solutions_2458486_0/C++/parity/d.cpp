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

int T, K, N;

map<pair<vector<int>, long>, bool> ans;

int Map[201];

set<int> keys;
int init[200];

int need0[200];
int need[200];

int nhas[200];

int nkey;
vector<int> has[200];
vector<int> inc[200];

int cur[200];

void print_ans(){

	for(int i = 0; i < N; i++)
		printf(" %d", cur[i] + 1);

}

int get_ans(vector<int>& ini, long done, int pos){


	if(pos == N)
		return true;

	pair<vector<int>, long>P(ini, done);

	map<pair<vector<int>, long>, bool>::iterator it = ans.find(P);
	if(it != ans.end())
		return it -> second;

	bool ret = false;

	for(int i = 0; !ret && i < N; i++){
		if(1 & (done >> i))
			continue;


		if(!ini[need[i]])
			continue;

		/*
		printf("done = %ld\n", done);
		printf("keys:\n");
		for(int j = 0; j < nkey; j++){
			printf("%d ", ini[j]);
		}
		printf("\n");
		printf("trying %d..\n", i);
		*/

		ini[need[i]]--;
		for(int j = 0; j < nkey; j++)
			ini[j] += inc[i][j];

		cur[pos] = i;

		if(get_ans(ini, done | ((long)1 << i), pos + 1))
				ret = true;

		ini[need[i]]++;
		for(int j = 0; j < nkey; j++)
			ini[j] -= inc[i][j];
	}


	return ans[P] = ret;
}

int main()
{
	scanf("%d", &T);

	for(int caseidx = 1; caseidx <= T; caseidx++){

		ans.clear();

		scanf("%d %d", &K, &N);

		int i, j, k, m;

		keys.clear();
		memset(init, 0, sizeof(init));
		for(i = 0; i < K; i++){
			scanf("%d", &j);
			init[i] = --j;

			keys.insert(j);
		}

		for(i = 0; i < N; i++){

			scanf("%d %d", &j, &k);
			j--;
			need0[i] = j;
			keys.insert(j);

			has[i].clear();
			for(j = 0; j < k; j++){
				scanf("%d", &m);
				has[i].push_back(--m);
				keys.insert(m);
			}
		}

		nkey = keys.size();
		i = 0;
		for(set<int>::iterator it = keys.begin(); it != keys.end(); it++){
			Map[*it] = i++;
			//printf("original key %d\n", *it);
		}

		for(i = 0; i < N; i++){

			need[i] = Map[need0[i]];

			inc[i].clear();
			inc[i] = vector<int>(nkey, 0);

			for(j = 0; j < int(has[i].size()); j++){
					inc[i][Map[has[i][j]]]++;
			}
		}

		vector<int> ini(nkey, 0);
		for(int i = 0; i < K; i++){
			ini[Map[init[i]]]++;
		}

		printf("Case #%d:", caseidx);
		if(!get_ans(ini, 0, 0))
			printf(" IMPOSSIBLE");
		else
			print_ans();

		printf("\n");
	}

	return 0;
}

// vi: ts=2 sw=2
