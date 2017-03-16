#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;
bool mysorter(vector<int> &v, vector<int> &w) {
	int n = v.size();
	int i;
	for (i = 0; v[i] == w[i]; i++)
	return (v[i] < w[i]);
}
int nums[2501];

int main(int argc, char **argv) {
	FILE *fp = fopen(argv[1], "r");
	int max, i,j, k; 
	fscanf(fp, "%d\n", &max);

	for(i=1; i<=max; i++) {
		memset(nums, 0, sizeof(nums));
		int len;
		fscanf(fp, "%d", &len);
		//vector<vector<int>> col;
		vector<int> list;
		for (j=0; j < (2*len - 1); j++) {
			vector<int> row;
			for(k=0; k < len; k++) {
				int foo;
				fscanf(fp, "%d", &foo);
				nums[foo]++;
			}
		}
		for (j=1; j<2501; j++)
			if(nums[j] % 2)
				list.push_back(j);

		sort(list.begin(), list.end());
		printf("Case #%d: ", i);
		for(int i = 0; i < len; i++)
			printf("%d ", list[i]);
		printf("\n");
	}
}
