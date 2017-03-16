#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

string filename = "B-small-attempt1";

int main() {
	int t, c;
	string line;
	ifstream fin((filename + ".in").c_str());
	FILE *fout = fopen((filename + ".out").c_str(), "w");
	getline(fin, line);
	printf("%s", line.c_str());
	t = atoi(line.c_str());
	c = 0;
	while (c++ < t) {
		int count = 0;
		getline(fin, line);
		int end = line.length();
		while (end-- > 0)
			if (line[end] == '-') {
				count = 1;
				break;
			}
		for (int i = 0; i < end; i++) {
			if (line[i] != line[i + 1])
				count++;
		}
		fprintf(fout, "Case #%d: %d\n", c, count);
	}
	fin.close();
	fclose(fout);
	exit(0);
}