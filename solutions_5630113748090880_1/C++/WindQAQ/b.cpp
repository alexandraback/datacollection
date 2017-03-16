#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#define MAX 256

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	return a[0] < b[0];
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int i = 1; i <= T; i++){
		printf("Case #%d:", i);

		int N;
		scanf("%d", &N);

		int tmp[5000] = {0};
		int max = -1;
		for(int j = 0; j < 2*N-1; j++)
			for(int k = 0; k < N; k++){
				int x;
				scanf("%d", &x);
				tmp[x]++;
				if(max < x)
					max = x;
			}

		vector <int>vv;
		// printf("======\n");
		// for(int j = 1; j <= 6; j++)
		// 	printf("tmp[%d] = %d\n", j, tmp[j]);
		// printf("======\n");
		for(int j = 0; j <= max; j++)
			if(tmp[j] % 2 == 1){
				//printf("tmp[%d] = %d\n", j, tmp[j]);
				vv.push_back(j);
			}

		//sort(vv.begin(), vv.end());

		for(int j = 0; j < vv.size(); j++)
			printf(" %d", vv[j]);
		printf("\n");
	}
}