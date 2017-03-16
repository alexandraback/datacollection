#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define D(x)

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

    	vector<int> distinct_nodes(N), min_cycle_node(N), cycle_size(N), first_cycle_node(N);
    	vector<int> cycle_ids(N, -1);
    	vector<bool> on_cycle(N), visited(N);
    	vector<int> cycle_sizes(N);
    	int nextCycleId = 0;

    	for (int i = 0; i < N; i++) {
    		vector<bool> visited(N);
    		int current = i;
    		vector<int> path;

    		int distinct = 0;
    		while (!visited[current]) {
    			D(cerr << "@" << (current+1) << endl);
    			distinct++;
    			visited[current] = true;
    			path.push_back(current);
    			current = F[current];
    		}

    		first_cycle_node[i] = current;
    		int cycle = 1;
    		int cycle_min = current;
    		int next = F[current];
    		while (next != current) {
    			cycle++;
    			cycle_min = min(cycle_min, next);
    			next = F[next];
    		}

    		distinct_nodes[i] = distinct;
    		min_cycle_node[i] = cycle_min;
    		cycle_size[i] = cycle;
    		D(cerr << "i=" << i << " dist=" << distinct << " cycle_min=" << (cycle_min+1) << " cycle=" << cycle << endl);
    	}

    	int max_single_cycle = 0;
    	map<int, int> max_duo_cycles;
    	for (int i = 0; i < N; i++) {
    		max_single_cycle = max(max_single_cycle, cycle_size[i]);
    	}
    	D(cerr << "max_single_cycle=" << max_single_cycle << endl);

    	int max_twoway_duo = 0;
    	for (int i = 0; i < N; i++) {
    		for (int j = i+1; j < N; j++) {
    			if (min_cycle_node[i] != min_cycle_node[j]) continue;
    			if (first_cycle_node[i] == first_cycle_node[j]) continue;
    			if (cycle_size[i] > 2) continue;

    			vector<bool> visited(N);
    			int distinct = 0;

    			int current = i;
    			while (!visited[current]) {
    				distinct++;
    				visited[current] = true;
    				current = F[current];
    			}

    			current = j;
    			while (!visited[current]) {
    				distinct++;
    				visited[current] = true;
    				current = F[current];
    			}

    			D(cerr << "twoway duo: i=" << (i+1) << " j=" << (j+1) << " -- " << distinct << endl);
    			max_duo_cycles[min_cycle_node[i]] = max(
    				max_duo_cycles[min_cycle_node[i]] , distinct);
    		}
    	}

    	int best_duo_cycles = 0;
    	for (auto& p : max_duo_cycles) {
    		D(cerr << "max_duo_cycles[" << (p.first+1) << "]=" << p.second << endl);
    		best_duo_cycles += p.second;
    	}

    	int result = max(max_single_cycle, max(best_duo_cycles, max_twoway_duo));
        cout << "Case #" << testCase << ": " << result << endl;
    }
}
