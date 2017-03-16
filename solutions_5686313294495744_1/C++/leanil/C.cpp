#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

int M, N;
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(const vector<vector<bool>>& bpGraph, int u, vector<bool>& seen, vector<int>& matchR) {
	// Try every job one by one
	for (int v = 0; v < N; v++) {
		// If applicant u is interested in job v and v is
		// not visited
		if (bpGraph[u][v] && !seen[v]) {
			seen[v] = true; // Mark v as visited

							// If job 'v' is not assigned to an applicant OR
							// previously assigned applicant for job v (which is matchR[v]) 
							// has an alternate job available. 
							// Since v is marked as visited in the above line, matchR[v] 
							// in the following recursive call will not get job 'v' again
			if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

// Returns maximum number of matching from M to N
int maxBPM(const vector<vector<bool>>& bpGraph) {
	// An array to keep track of the applicants assigned to
	// jobs. The value of matchR[i] is the applicant number
	// assigned to job i, the value -1 indicates nobody is
	// assigned.
	vector<int> matchR(N,-1);

	int result = 0; // Count of jobs assigned to applicants
	for (int u = 0; u < M; u++) {
		// Mark all jobs as not seen for next applicant.
		vector<bool> seen(N, false);

		// Find if the applicant 'u' can get a job
		if (bpm(bpGraph, u, seen, matchR))
			result++;
	}
	return result;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		out << "Case #" << test << ": ";
		int n;
		in >> n;
		M = N = 0;
		map<string, int> fst, snd;
		vector<pair<string, string>> titles(n);
		for (int i = 0; i < n; ++i) {
			in >> titles[i].first >> titles[i].second;
			if (fst.find(titles[i].first) == fst.end()) {
				fst[titles[i].first] = M++;
			}
			if (snd.find(titles[i].second) == snd.end()) {
				snd[titles[i].second] = N++;
			}
		}
		vector<vector<bool>> graph(M, vector<bool>(N, false));
		for (const pair<string, string>& p : titles) {
			graph[fst[p.first]][snd[p.second]] = true;
		}

		out << n - (M + N - maxBPM(graph)) << endl;
	}
	return 0;
}