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

    	vector<vector<int>> lines(2*N-1, vector<int>(N));
    	for (int i = 0; i < 2*N-1; i++) {
    		for (int j = 0; j < N; j++) {
    			cin >> lines[i][j];
    		}
    	}

    	vector<vector<int>> rows, cols;

    	int t = -1;
    	vector<bool> visited(2*N-1);

    	for (int i = 0; i < N; i++) {
    		int min_val = 9999;
    		vector<int> indices;
    		for (int j = 0; j < lines.size(); j++) {
    			if (visited[j]) continue;
    			if (lines[j][i] < min_val) {
    				min_val = lines[j][i];
    				indices.clear();
    			}
    			if (lines[j][i] == min_val) {
    				indices.push_back(j);
    			}
    		}

			rows.push_back(lines[indices[0]]);
			visited[indices[0]] = true;
    		if (indices.size() == 1) {
    			cols.push_back(vector<int>(N, -1));
    			t = i;
    		} else {
    			cols.push_back(lines[indices[1]]);
    			visited[indices[1]] = true;
    		}
    	}

    	vector<int> result(N);
    	for (int i = 0; i < N; i++) {
    		//D(cerr << "i=" << i << " match=" << rows[t][i] << "choices=" << cols[i][t] << " " << rows[i][t] << endl);
    		if (i == t) {
    			result[i] = rows[i][t];
    		} else if (rows[t][i] == cols[i][t]) {
    			result[i] = rows[i][t];
    		} else {
    			result[i] = cols[i][t];
    		}
    	}
        cout << "Case #" << testCase << ":";
        for (int i = 0; i < result.size(); i++) {
        	cout << " " << result[i];
        }
        cout << endl;
    }
}
