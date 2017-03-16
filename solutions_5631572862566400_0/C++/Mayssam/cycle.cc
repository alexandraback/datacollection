
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

using namespace std;


int solve(vector<int> bff, unordered_map<int, int> visited, int st, int N, int step) {
    visited[st] = ++step;
    int next, best = 0;
    while (true) {
	next = bff[st-1];
	if (visited[next] == 0) {
	    visited[next] = ++step;
	    st = next;
	} else if (visited[next] == step - 1) {
	    for (int k = 1; k <= N; k++) {
		if (visited[k] > 0) continue;
		unordered_map<int, int> o = visited;
		int cur = solve(bff, o, k, N, step);
		if (best < cur)
		    best = cur;
	    }
	    break;
	} else {
	    break;
	}
    }
    int sz = 0;
    for (auto it = visited.begin(); it != visited.end(); it++)
	if (it->second > 0) sz++;
    if (best < (sz - visited[next] + 1))
	best = sz - visited[next] + 1;
    return best;
}

int main() {

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
	int N;
	cin >> N;
	vector<int> bff(N, 0);
	for (int j = 0; j < N; j++)
	    cin >> bff[j];
	
	int best = 0;
	for (int j = 1; j <= N; j++) {
	    unordered_map<int, int> order;
	    int cur = solve(bff, order, j, N, 0);
	    if (cur > best)
		best = cur;
	    if (cur == N)
		break;
	}
	
	cout << "Case #" << 1+i << ": " << best << endl;
    
    }

    return 0;
}


