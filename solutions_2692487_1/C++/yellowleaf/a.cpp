#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <queue>
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
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	istringstream iss(buf);
	int A, N;
	iss >> A >> N;
	vector<int> other;
	ifs.getline(buf, BUFSIZE);
	istringstream iss2(buf);
	for (int i = 0; i < N; i++)
	{
		int s;
		iss2 >> s;
		other.push_back(s);
	}

	sort(other.begin(), other.end());
	int penaty = 0;
	int minPenaty = INT_MAX;

	long long curSize = A;

	for (int i = 0; i < N; )
	{
		if (other[i] < curSize)
		{
			curSize += other[i];
			i++;
			minPenaty = min(minPenaty, N - i + penaty);
		}
		else
		{
			minPenaty = min(minPenaty, N - i + penaty);
			curSize = 2 * curSize - 1;
			penaty++;
			if (penaty >= minPenaty)
			{
				break;
			}
		}
	}

	return penaty;
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
