#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
#include <stack>
#include <list>
#include <cstring>
#include <fstream>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define REP(i,e) for (int i = 0; i < int(e); ++i)
#define MAX(a,b) ((a) > (b) ? (a):(b))
#define MIN(a,b) ((a) < (b) ? (a):(b))
#define SQR(a) ((a)*(a))

const char probname = 'A';
const bool largeset = false;
const char* suffix = "-attempt0";


int visited[1000];

bool dfs(const vector < vector <int> >& g, int i) {
	visited[i]++;
	if (visited[i] >= 2) return true;

	REP(j, g[i].size())	if (dfs(g, g[i][j])) return true;

	return false;
}


int main() {
	char buffer[1234];
	sprintf(buffer, "%c-%s%s.in", probname, largeset ? "large" : "small", suffix);
	ifstream fin(buffer);
	sprintf(buffer, "%c-%s%s.out", probname, largeset ? "large" : "small", suffix);
	ofstream fout(buffer);

	int testCases;
	fin >> testCases;

	int n, s, p;
	REP(testCase, testCases) {



		fin >> n;
		vector < vector <int> > graph(n);
		REP(i, n) {
			int m;
			fin >> m;
			REP(j, m) {
				int v;
				fin >> v;
				graph[i].push_back(v - 1);
			}
		}

		bool found = false;
		REP(i, n) {
			memset(visited, 0, sizeof(visited));
			found = dfs(graph, i);
			if (found) break;
		}



		fout << "Case #" << testCase + 1 << ": " << (found ? "Yes":"No") << endl;
	}

	fin.close();
	fout.close();
}
