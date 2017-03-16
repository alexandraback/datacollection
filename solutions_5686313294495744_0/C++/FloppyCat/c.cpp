#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <unordered_map>

typedef std::pair<std::string, std::string> Topic;
struct Graph {
	typedef std::unordered_map<std::string, int> Map;
	Map leftWords, rightWords;
	std::vector<int> matchRight;

	std::vector<std::vector<int>> out_edges;
	bool match(int leftVertex, std::vector<bool> &visited);
	int runMatch();
	Graph(const std::vector<Topic> &topics);
};

Graph::Graph(const std::vector<Topic> &topics) {
	int leftCount = 0;
	int rightCount = 0;
	auto insert = [](Map &m, const std::string &w, int &counter) -> int {
		auto it = m.find(w);
		if (it==m.end())
			return m[w] = counter++;
		else return it->second;
	};
	for (const auto &t : topics) {
		int leftIndex = insert(leftWords, t.first, leftCount);
		int rightIndex = insert(rightWords, t.second, rightCount);
		if (this->out_edges.size()<=leftIndex)
			this->out_edges.resize(leftIndex+1);
		this->out_edges[leftIndex].push_back(rightIndex);
	}
	matchRight = std::vector<int>(rightWords.size(), -1);
}

bool Graph::match(int leftVertex, std::vector<bool> &visited) {
	if (visited[leftVertex])
		return false;
	visited[leftVertex] = true;
	for (int rightVertex : out_edges[leftVertex]) {
		if (matchRight[rightVertex]==-1) {
			matchRight[rightVertex] = leftVertex;
			return true;
		}
		if (match(matchRight[rightVertex], visited)) {
			return true;
		}
	}
	return false;
}

int Graph::runMatch() {
	for (int leftVertex=0; leftVertex<out_edges.size(); leftVertex++) {
		std::vector<bool> visited(out_edges.size(), false);
		if (match(leftVertex, visited))
			leftVertex = -1;
	}
	int ans = 0;
	for (int x : matchRight)
		if (x!=-1)
			ans++;
	return ans;
}
 
int main() {
	int T;
	std::istream &fi = std::cin;
	fi >> T;
	for (int i=1; i<=T; i++) {
		int n;
		fi >> n;
		std::vector<Topic> topics(n);
		for (auto &t : topics)
			fi >> t.first >> t.second;
		Graph graph(topics);
		int matched = graph.runMatch();
		int nonFake = graph.leftWords.size() + graph.rightWords.size() - matched;
		int ans = topics.size() - nonFake;
		std::cout << "Case #" << i << ": " << ans << std::endl;
	}

	return 0;
}
