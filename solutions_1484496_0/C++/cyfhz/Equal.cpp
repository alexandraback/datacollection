#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>

#include <set>
using namespace  std;
#include <vector>
int val[200];
vector<vector<int> > sum;
int res_j, res_k;
bool canfind(int s)
{
	int i, j, k;
	for(i = 0; i <= s; i ++) {
		if(sum[i].size() >= 2) {
			int len = sum[i].size();
			for(j = 0; j < len; ++j) {
				for(k = j + 1; k < len; ++ k) {
					if( (sum[i][j] & sum[i][k]) == 0 ) {
						res_j = sum[i][j];
						res_k = sum[i][k];
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Equal ()
{
	//FILE * fp_open, * fp_out;
	freopen(".\\C-small-attempt1.in","r", stdin);
	 	 	freopen(".\\C-samll-attempt1.out", "w", stdout);
// 	freopen(".\\A-large.in","r", stdin);
// 	freopen(".\\A-large.out", "w", stdout);
	//FILE * fp = fopen("debug.txt", "w");
	int T, n, i, j, k, cas = 0, s = 0;
	double v, left_vote;
	scanf("%d", &T);

	sum.resize(2000010);
	while(T--){
		s = 0;
		scanf("%d", &n);
		
		for(i  = 0; i < n; i ++){
			scanf("%d", &val[i]);
			s += val[i];
		}

		for(i = 0; i <= s; i ++)
			sum[i].clear();
		for(i =  0; i < (1 << n); ++i) {
			int cursum = 0;
			for( j = 0; j < n; j ++) {
				if(i & (1 << j))
					cursum += val[j];
			}
			sum[cursum].push_back(i);
		}
		printf("Case #%d:\n", ++cas);
		if(canfind(s)) {
			k = 0;
			for(i = 0; i < n;  i++) {
				if((1<<i) & res_j) {
					if(k == 0)
					{
						printf("%d", val[i]);
						k ++;
					}
					else printf(" %d", val[i]);
				}
			}
			printf("\n");
			k = 0;
			for(i = 0; i < n;  i++) {
				if((1<<i) & res_k) {
					if(k == 0)
					{
						printf("%d", val[i]);
						k ++;
					}
					else printf(" %d", val[i]);
				}
			}
			printf("\n");
		}
		else {
			printf("Impossible\n");
		}
	}

}

int main() {

	Equal();
	return 0;
}
