#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi; 
typedef vector<string> vs;

#define PB push_back
const long double PI = 3.1415926535897932384626433832795;
char graph[1000][1000];
int N;
char gmark[1000], lmark[1000];

string solve(int node)
{
	 lmark[node] = 1;
	 gmark[node] = 1;
	 for (int i = 0; i < N; ++i) {
		 if (graph[node][i] == 1) {
			 if (lmark[i] == 1) return "Yes";
			 lmark[i] = 1;
			 gmark[i] = 1;
			 if (solve(i) == "Yes") return "Yes";
		 }
	 }
	 return "No";
}

int done()
{
	for (int i = 0; i < N; ++i) {
		if (gmark[i] == 0) return i;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int num_tc;
	string res;
	ifstream myfile;
	myfile.open(argv[1]);
	myfile >> num_tc;
	
	for (int i=0; i<num_tc; ++i) {
		myfile >> N;
		memset (graph, 0, sizeof(graph));
		memset (gmark, 0, sizeof(gmark));
		for (int l=0; l<N; ++l) {
			int num, tmp;
			myfile >> num;
			for (int l2=0; l2<num; ++l2) {
				myfile >> tmp;
				graph[l][tmp-1] = 1;
			}
		}
		int pos = 0;
		res = "No";
		while ((pos = done()) != -1 && res != "Yes") {
			memset (lmark, 0, sizeof(lmark));
			res = solve(pos);
		}
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
	myfile.close();
	return 0;
}
