#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct node {
	size_t idx;
	size_t m;
	node** links;
};

bool findDiamondInheritance(node** nodes, size_t N, size_t start) {
	vector<bool> pathFound(N, false);
	queue<node*> q;
	q.push(nodes[start]);

	while(q.size() > 0) {
		node* current = q.front();
		q.pop();

		if(pathFound[current->idx])
			return true;

		pathFound[current->idx] = true;

		for(size_t i = 0; i < current->m; i++)
			q.push(current->links[i]);
	}

	return false;
}

int main(int argc, char** argv) {
	string filePath = "input.txt";

	if(argc > 1)
		filePath = argv[1];

	ifstream in(filePath);
	ofstream out("out.txt");

	size_t T;
	in>>T;

	for(size_t i = 0; i < T; i++) {
		size_t N;
		in>>N;

		node** nodes = new node*[N];
		for(size_t j = 0; j < N; j++) {
			nodes[j] = new node();
			nodes[j]->idx = j;
		}

		for(size_t j = 0; j < N; j++) {
			size_t M;
			in>>M;

			nodes[j]->links = new node*[M];
			nodes[j]->m = M;
			
			for(size_t k = 0; k < M; k++) {
				size_t temp;
				in>>temp;
				temp--;

				nodes[j]->links[k] = nodes[temp];
			}
		}

		bool diamondInheritance = false;
		for(size_t j = 0; j < N; j++) {
			diamondInheritance = diamondInheritance || findDiamondInheritance(nodes, N, j);
			if(diamondInheritance)
				break;
		}

		out<<"Case #"<<(i+1)<<": "<<(diamondInheritance ? " Yes" : " No")<<endl;
	}

	out.close();
	in.close();
	
	return 0;
}