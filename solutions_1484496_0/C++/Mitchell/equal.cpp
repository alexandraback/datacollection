#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
using namespace std;
FILE * fout = fopen("C.out", "w");
FILE * fin = fopen("C.in", "r");
int nums[500];

int main(){
	int T;
	fscanf(fin, "%d", &T);
	for(int casenum=0;casenum<T;casenum++){
		map<int, int> sums;
		int N;
		fscanf(fin, "%d", &N);
		for(int i=0;i<N;i++){
			fscanf(fin, "%d", &nums[i]);
		}
		int ans1 = -1;
		int ans2;
		for(int i=0;i < (1 << N); i++){
			int sum = 0;
			for(int j=0;j<N;j++){
				if((1 << j) & i){
					sum += nums[j];
				}
			}
			
			if(sums.count(sum)){
				ans1 = i;
				ans2 = sums[sum];
				break;
			}
			sums[sum] = i;
		}
		fprintf(fout, "Case #%d:\n", casenum + 1);
		if(ans1 == -1){
			fprintf(fout, "Impossible\n");
			continue;
		}
		bool first = true;
		for(int j=0;j<N;j++){
			if((1 << j) & ans1){
				if(!first){
					fprintf(fout, " ");
				} else {
					first = false;
				}
				fprintf(fout, "%d", nums[j]);
			}
		}
		fprintf(fout, "\n");
		first = true;
		for(int j=0;j<N;j++){
			if((1 << j) & ans2){
				if(!first){
					fprintf(fout, " ");
				} else {
					first = false;
				}
				fprintf(fout, "%d", nums[j]);
			}
		}
		fprintf(fout, "\n");
	}
}
