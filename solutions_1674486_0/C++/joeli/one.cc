#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Class {
	vector<int> parents;
	bool visited;
};

int nodes;
int edges;

void search(vector<Class>& classes, int start) {
	if (classes[start].visited) {
		return;
	}
	else {
		nodes++;
		classes[start].visited = true;
		for (int i = 0; i < classes[start].parents.size(); i++) {
			edges++;
			search(classes, classes[start].parents[i]);
		}
	}
}

bool diamond(vector<Class>& classes, int start) {
	nodes = 0;
	edges = 0;

	for (int i = 0; i < classes.size(); i++) {
		classes[i].visited = false;
	}

	search(classes, start);

	if (edges >= nodes) {
		return true;
	}
	else {
		return false;
	}
}

void handle_case(int case_nbr) {
	cout << "Case #" << case_nbr << ": ";

	int N;
	cin >> N;

	vector<Class> classes(N);

	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		for (int j = 0; j < M; j++) {
			int parent;
			cin >> parent;
			classes[i].parents.push_back(parent-1);
		}
	}

	for (int i = 0; i < N; i++) {
		if (diamond(classes, i)) {
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl;
}

int main(void) {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		handle_case(i+1);
	}

	return 0;
}
