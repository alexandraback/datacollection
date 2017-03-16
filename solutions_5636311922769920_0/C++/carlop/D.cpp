#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(void) {
	int num_test;
	cin>>num_test;
	
	for (int test=1; test<=num_test; test++) {
		int K, C, S;
		cin>>K>>C>>S;
		
		cout<<"Case #"<<test<<":";
		
		if (C*S < K) cout << " IMPOSSIBLE";
		else {
			
			vector <long long> depth(C);
			depth[0] = 1;
			for (int d=1; d<C; d++) depth[d] = depth[d-1] * K;
			
			reverse(depth.begin(), depth.end());
			
			vector <long long> to_be_tested;
			
			int next = 0;
			long long curr = 0;
			int curr_depth = 0;
			while (next < K) {
				curr += next++ * depth[curr_depth++];
				
				if (curr_depth == C) {
					to_be_tested.push_back(curr);
					curr = 0;
					curr_depth = 0;
				}
			}
			
			if (to_be_tested.empty() || curr > 0) to_be_tested.push_back(curr);
			
			for (long long T : to_be_tested) cout << " " << T+1;
		}

		cout << "\n";
	}
	return 0;
}
