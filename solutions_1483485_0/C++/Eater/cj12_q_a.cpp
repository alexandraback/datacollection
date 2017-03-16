#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N;
char trans[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	ifstream fin ("cj12_q_a.in");
	ofstream fout ("cj12_q_a.out");
	fin >> N;
	fin.ignore(1);
	for (int n = 1; n <= N; n++) {
		char g[101];
		fin.getline(g, 101);
		for (int c = 0; g[c] != NULL; c++) {
			if (g[c] == ' ') { continue; }
			g[c] = trans[g[c] - 97];
		}
		fout << "Case #" << n << ": " << g << endl;
	}
	return 0;
}
