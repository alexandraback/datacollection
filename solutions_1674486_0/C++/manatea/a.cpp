#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
using namespace std;

vector<int> parent[1000];
map<string, int> paths;
void walk(int start, int current);

int main() {
	FILE* fp = fopen("A-small-attempt0.in.txt", "r");
	char inputbuf[4096];
	fgets(inputbuf, sizeof(inputbuf), fp);
	int nCases = atoi(inputbuf);

	for (int caseNo = 1; caseNo <= nCases; ++caseNo) {
		cout << "Case #" << caseNo << ": ";

		fgets(inputbuf, sizeof(inputbuf), fp);
		int N = atoi(inputbuf);


		for (int i = 1; i <= N; ++i) {
			parent[i].clear();
			fgets(inputbuf, sizeof(inputbuf), fp);
			char* ptr = strtok(inputbuf, " ");
			int Mi = atoi(ptr);

			for (int j = 0; j < Mi; ++j) {
				ptr = strtok(NULL, " ");
				int p = atoi(ptr);
				parent[i].push_back(p);
			}
		}

		paths.clear();
		for (int i = 1; i <= N; ++i) {
			walk(i, i);
		}

		bool found = false;
		map<string,int>::iterator it = paths.begin();
		while (it != paths.end()) {
			//cout << it->first << " " << it->second << endl;
			if (it->second > 1) {
				found = true;
			}
			++it;
		}

		if (found) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	fclose(fp);
	return 0;
}

void walk(int start, int current)
{
	if (parent[current].size() == 0) {
		string pathstr;
		ostringstream stream;
		stream << start << "," << current;
		pathstr = stream.str();
		paths[pathstr]++;
		return;
	}

	vector<int>::iterator it = parent[current].begin();
	while (it != parent[current].end()) {
		int parentNo = *it;
		walk(start, parentNo);
		++it;
	}
	return;
}
