#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstdint>

#define D(x) x

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
    	int64_t K, C, S;
    	cin >> K >> C >> S;

    	vector<int64_t> result;
    	if (C * S >= K) {
    		int start = 0;
    		while (start < K) {
    			int end = min(K, start+C);

    			int64_t pos = 0;
    			for (int i = start; i < end; i++) {
    				pos *= K;
    				pos += i;
    			}
    			pos++;
    			result.push_back(pos);

    			start = end;
    		}
    	}

        cout << "Case #" << testCase << ":";
        if (result.size() == 0) {
        	cout << " IMPOSSIBLE";
        } else {
        	for (auto& x : result) {
        		cout << " " << x;
        	}
        }
        cout << endl;
    }
}
