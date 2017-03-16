#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

bool is_visitable(const vector<vector<int>> &in_graph, int from_id, int to_id)
{
	if (from_id == to_id) {
		return true;
	} 
	vector<int> to_visit = in_graph[from_id];
	for(int i=0; i<to_visit.size(); i++) {
		bool v = is_visitable(in_graph, to_visit[i], to_id);
		if (v == true) {
			return true;
		}
	}
	return false;
}

string solve_a(const vector<vector<int>> &in_graph)
{
	for(int i=0; i<in_graph.size(); i++) {
		if (in_graph[i].size() < 2) continue;

		for(int n=0; n<in_graph.size(); n++) {
			if (n == i) continue;
			bool visitable = false;
			for(int k=0; k<in_graph[i].size(); k++) { //parents
				bool v = is_visitable(in_graph, in_graph[i][k], n);

				if (visitable && v) {
					return "Yes";
				}
				if (v) {
					visitable = true;
				}
			}
		}
	}
	return "No";
}

int main(int argc, char *argv[]) {
	std::ifstream ifs(argv[1]);
	if (!ifs.is_open()) return -1;
	std::string ofilename = std::string(argv[1]) + ".out";
	std::ofstream ofs(ofilename.c_str());
	int num;
	ifs >> num;
	for(int c=1; c<=num; c++) {
		int numc;
		ifs >> numc;
		vector<vector<int>> graph;
		for(int k=0; k<numc; k++) {
			vector<int> node;
			int nump;
			ifs >> nump;
			for(int p=0; p<nump; p++) {
				int v;
				ifs >> v;
				node.push_back(v-1); //starting from 0
			}
			graph.push_back(node);
		}
		cout << "Solving " << c << std::endl;
		string ans = solve_a(graph);
		ofs << "Case #" << c << ": " << ans << std::endl;
	}

	return 0;
}
