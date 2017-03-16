#include <stdio.h>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <utility>
#include <memory.h>

using namespace std;

int main()
{
	scanf("%*d");
	printf("Case #1:\n");
	scanf("%d%d%d%d",&R,&N,&M,&K);
	while(R-->0){
		int maxcounts[10]={0,};
		int total[10]={0,};
		int freq[10][4]={0,};
		vector<int> ans;
		for(int i = 0; i < K; i++) {
			int val;
			scanf("%d",&val);
			for(int dv = 2; dv <= 8; dv++) {
				int count = 0;
				while(val % dv == 0) {
					val /= dv;
					count ++;
					pfacts.push_back(dv);
					total[dv]++;
				}
				freq[dv][count]++;
				maxcounts[dv] = max(maxcounts[dv], count);
			}
		}
		for(int i = 0; i < maxcounts[5]; i++)
			ans.push_back(5);
		for(int i = 0; i < maxcounts[7]; i++)
			ans.push_back(7);
		for(int i = 0; i < maxcounts[3]; i++)
			ans.push_back(3);
		int leftcount = 12 - ans.size();
		for(int i = 0; i < leftcount; i++) ans.push_back(2);

		for(int i = 0; i < 12; i++) {
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
