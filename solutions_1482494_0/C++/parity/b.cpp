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

int needed[2][1001];

//int hit[2][1001];


int main()
{
	
	int T, N;

	scanf("%d", &T);

	set<pair<int, int> >S[3];

	for(int t = 1; t <= T; t++){

		for(int i = 0; i < 3; i++)	S[i].clear();

		scanf("%d", &N);

		for(int i = 0; i < N; i++){
			scanf("%d %d", &needed[0][i], &needed[1][i]);

			S[0].insert(pair<int, int>(needed[0][i], i));
			S[2].insert(pair<int, int>(needed[1][i], i));

		}
		//memset(hit, 0, sizeof(hit));

		int cur = 0;
		int rem = N;
		int ret = 0;

		while(rem){

			assert(S[0].size() == S[2].size());
			assert(rem == S[0].size() + S[1].size());

			set<pair<int, int> >::iterator it;

			if(0 == S[2].size())	goto ONE;

			it = S[2].begin();

			if((it -> first) <= cur){

				int idx = it -> second;

				cur += 2;
				ret++;
				rem--;

				assert(it -> first == needed[1][idx]);

				S[2].erase(pair<int, int>(needed[1][idx], idx));
				S[0].erase(pair<int, int>(needed[0][idx], idx));

				//assert(hit[0][idx] == 0);
				//assert(hit[1][idx] == 0);

				//hit[0][idx] = 1;
				//hit[1][idx] = 1;

				//printf("hitting level %d with full rating 2 -> cur = %d\n", idx, cur);

				continue;
			}
ONE:
			if(0 == S[1].size())	goto ZERO;

			it = S[1].begin();
			if((it -> first) <= cur){

				int idx = it -> second;
				cur++;
				ret++;
				rem--;

				assert(needed[1][idx] == it -> first);

				S[1].erase(pair<int, int>(needed[1][idx], idx));

				//assert(hit[0][idx] == 1);
				//assert(hit[1][idx] == 0);

				//hit[1][idx] = 1;
				//printf("hitting level %d with partial rating 2 -> cur = %d\n", idx, cur);

				continue;
			}

ZERO:
			if(0 == S[0].size())	break;

			it = S[0].begin();
			if((it -> first) <= cur){

				int idx = it -> second;
				cur++;
				ret++;

				assert((it -> first) == needed[0][idx]);

				S[2].erase(pair<int, int>(needed[1][idx], idx));
				S[0].erase(pair<int, int>(needed[0][idx], idx));
				
				S[1].insert(pair<int, int>(needed[1][idx], idx));

				//printf("hitting level %d with rating 1 -> cur = %d\n", idx, cur);

				//assert(hit[0][idx] == 0);
				//assert(hit[1][idx] == 0);

				//hit[0][idx] = 1;

				continue;
			}
			else	break;

		}//while rem

		printf("Case #%d: ", t);
		if(rem)
			printf("Too Bad\n");
		else{
			assert(ret <= (N << 1));
			printf("%d\n", ret);
		}


	}

	return 0;
}

// vi: ts=2 sw=2
