#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

ifstream fin("in");
ofstream fout("out");

const int MAXN = 1001;
int adj[MAXN][MAXN];
int nadj[MAXN];
bool visited[MAXN];

int N;

void unvisit() {
	for(int i=0; i<N; i++)
		visited[i] = false;
}

bool diamondRec(int i) {
	if(visited[i])
		return true;
	visited[i] = true;
	bool b = false;
	for(int j=0; j<nadj[i]; j++)
		b = b | diamondRec(adj[i][j]);
	return b;
}

bool findDiamond(int i) {
	bool b = false;
	unvisit();
	return diamondRec(i);
}


int main() {
	int T; fin>>T;
	for(int t=1; t<=T; t++) {
		fin>>N;
		for(int i=0; i<N; i++) {
			fin>>nadj[i];
			for(int j=0; j<nadj[i]; j++) {
				fin>>adj[i][j];
				adj[i][j]--;
			}
		}

		bool diamond = false;
		for(int i=0; i<N; i++) {
			diamond = diamond | findDiamond(i);
		}
		fout << "Case #" << t << ": ";
		fout << (diamond?"Yes":"No") << endl;
	}

	return 0;
}

