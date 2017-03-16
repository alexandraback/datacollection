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

vector<long long> all;
vector<long long> allSquare;

bool isPalin(long long x)
{
	long long x1 = x; 
	long long x2 = 0; 
	while (x1 > 0) 
	{    
		x2 = x2 * 10 + (x1 % 10); 
		x1 = x1 / 10;
	}    

	return (x == x2); 
}

void calculateAll()
{
	for (long long i = 1; i < 10000000; i++)
	{
		if (isPalin(i) && isPalin(i * i))
		{
			all.push_back(i);
			allSquare.push_back(i * i);
		}
	}
#if 0
	for (long i = 0; i < all.size(); i++)
	{
		cout << all[i] << "  ";
		if ( (i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	cout << endl;
	for (long i = 0; i < all.size(); i++)
	{
		cout << allSquare[i] << "  ";
		if ( (i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
#endif
}

int  processOneCase(ifstream &ifs)
{
	long long start, end;
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	istringstream iss(buf);
	iss >> start >> end;

	vector<long long>::iterator lowIt = lower_bound(allSquare.begin(), allSquare.end(), start);
	vector<long long>::iterator highIt = upper_bound(allSquare.begin(), allSquare.end(), end);

	return highIt - lowIt;
}

int main(int argc, char *argv[])
{
	calculateAll();

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
