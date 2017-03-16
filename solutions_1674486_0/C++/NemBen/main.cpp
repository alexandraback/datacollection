#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

bool bfs(const std::vector<std::vector<int> >& diagram, const int s) {
	std::vector<bool> c; c.resize(diagram.size()); for (unsigned int i = 0; i < diagram.size(); ++i) c[i] = false;
	std::queue<int> q;

	c[s] = true;
	q.push(s);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (unsigned int i = 0; i < diagram[u].size(); ++i) {
			if (c[diagram[u][i]] == false) {
				c[diagram[u][i]] = true;
				q.push(diagram[u][i]);
			} else {
				return true;
			}
		}
	}

	return false;
}

bool search(const std::vector<std::vector<int> >& diagram, std::queue<int>& sources) {
	printf("SOURCES: %d\n",sources.size());
	while (!sources.empty()) {
		int u = sources.front(); sources.pop();
		if (bfs(diagram,u)) return true;
	}

	return false;
}

void solve(std::string infile, std::string outfile) {
	std::ifstream in(infile);
	std::ofstream out(outfile);

	int cnt; in >> cnt;
	for (int c = 1; c <= cnt; ++c) {
		std::vector<bool> source;
		std::vector<std::vector<int> > diagram;
		std::queue<int> sources;
		int n; in >> n;
		diagram.resize(n);
		source.resize(n); for (int i = 0; i < n; ++i) source[i] = true;
		for (int i = 0; i < n; ++i) {
			int m; in >> m;
			diagram[i].resize(m);
			for (int j = 0; j < m; ++j) {
				in >> diagram[i][j];
				--diagram[i][j];
				source[diagram[i][j]] = false;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (source[i] == true) {
				sources.push(i);
			}
		}	

		out << "Case #" << c << ": " << (search(diagram,sources)?"Yes":"No") << std::endl;
	}

	out.close();
	in.close();
}

int main() {
	solve("small2.in","small2.out");

	return 0;
}