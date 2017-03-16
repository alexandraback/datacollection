#include <bits/stdc++.h>
using namespace std;
int tcs, cts[300];
char buf[10000];
int main(){
	scanf("%i\n", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		gets(buf);
		int n = strlen(buf);
		memset(cts, 0, sizeof cts);
		for(int i=0;i<n;i++){
			cts[buf[i]]++; 
		}
		int nums[10];
		memset(nums, 0, sizeof nums);
		//0
		nums[0] = cts['Z'];
		nums[1] = cts['O'] - cts['Z'] - cts['W'] - cts['U'];
		nums[2] = cts['W'];
		nums[3] = cts['R'] - cts['Z'] - cts['U'];
		nums[4] = cts['U'];
		nums[5] = cts['F'] - cts['U'];
		nums[6] = cts['X'];
		nums[7] = cts['V'] - nums[5];
		nums[8] = cts['H'] - nums[3];
		nums[9] = (cts['N'] - nums[7] - nums[1]) /2;
		printf("Case #%i: ", tc);
		for(int i=0;i<10;i++){
			for(int j=0;j<nums[i];j++){
				printf("%i", i);
			}
		}
		puts("");
	}
}