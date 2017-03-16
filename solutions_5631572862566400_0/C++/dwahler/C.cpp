#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define D(x) x

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
    	int N;
    	cin >> N;
    	vector<int> F(N);
    	for (int i = 0; i < N; i++) {
    		cin >> F[i];
    		F[i]--;
    	}

    	int best = 0;
		vector<int> candidates;
    	for (int bitmask = 1; bitmask < (1<<N); bitmask++) {
    		candidates.clear();
    		for (int i = 0; i < N; i++) {
    			if (bitmask & (1<<i)) candidates.push_back(i);
    		}

    		int k = candidates.size();
    		if (k <= best) continue;

    		do {
    			bool valid = true;
    			for (int i = 0; i < k; i++) {
    				int leftIdx = (i == 0) ? (k-1) : i-1;
    				int rightIdx = (i == k-1) ? 0 : i+1;

    				if (candidates[leftIdx] != F[candidates[i]] 
    					&& candidates[rightIdx] != F[candidates[i]]) {
    					valid = false;
    					break;
    				}
    			}
    			if (valid) {
    				best = k;
    				break;
    			}
    		} while (next_permutation(candidates.begin(), candidates.end()));
    	}
        cout << "Case #" << testCase << ": " << best << endl;
    }
}
