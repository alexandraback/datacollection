#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int curr_case = 1; curr_case <= T; ++curr_case){
		int A;
		int N;
		scanf("%d%d", &A, &N);
		vector<int> mote_sizes;
		mote_sizes.reserve(N);
		for(int i = 0; i < N; ++i){
			int t;
			scanf("%d", &t);
			mote_sizes.push_back(t);
		}
		sort(mote_sizes.begin(), mote_sizes.end());
		int best_cost = N;
		int curr_size = A;
		int size_cost = 0;
		bool done = false;
		for(int i = 0; i < N; ++i){
			int curr_cost = N-i-1;
			while(mote_sizes[i]>=curr_size){
				//curr_cost += 1;
				size_cost ++;
				if(curr_size == 1){
					if(N-i<best_cost){
						best_cost = N-i;}
						done = true;
						break;
					
				}
				curr_size += curr_size-1;
			}
			curr_size += mote_sizes[i];
			if(done)
				break;
			if(curr_cost +size_cost< best_cost){
				best_cost = curr_cost+size_cost;
			}
		}
		printf("Case #%d: %d\n", curr_case, best_cost);
	}
    return 0;
}
