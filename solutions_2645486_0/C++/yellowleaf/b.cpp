#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;
//#define DEBUG

const int BUFSIZE = 2 * 1024 * 1024;

int  processOneCase(ifstream &ifs)
{
	int E, R, N;
	vector<int> val;
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	istringstream iss(buf);
	iss >> E >> R >> N;

	ifs.getline(buf, BUFSIZE);
	istringstream iss2(buf);
	for (int i = 0; i < N; i++)
	{
		int v;
		iss2 >>v;
	    val.push_back(v);
	}	

	vector<vector<int> > matrix(N+1, vector<int>(E+1, 0));
	for (int i=0; i < N; i++)
	{
		for (int j = 0; j < E +1; j++)
		{
			int engy = min(E, j+R);
			for (int spend = 0; spend <= engy; spend++)
				matrix[i+1][engy-spend] = max(matrix[i+1][engy-spend], matrix[i][j]+val[i]*spend);
		}
	}

	return *max_element(matrix[N].begin(), matrix[N].end());
}

int main(int argc, char *argv[])
{
	ifstream ifs(argv[1]);
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	int lines = atoi(buf);

	for (int i = 0; i < lines; i++)
	{   
		int result = processOneCase(ifs); 
		cout << "Case #" << (i+1) << ": " << result  << endl;
	}   
	return 0;
}
