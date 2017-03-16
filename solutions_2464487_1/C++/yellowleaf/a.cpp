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

long long  processOneCase(ifstream &ifs)
{
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	istringstream iss(buf);
	long long r, t;
	iss >> r >> t;

	long long max_t = (long long) (3 * 1000000);
	max_t *= 1000000;
	max_t *= 1000000;
	long long low = 0, high = min((long long)INT_MAX, max_t/r);

	while(low <= high)
	{
		long long mid = (low+high)/2;
		long long area = (2*r + 2*mid -1) * mid;
		if (area == t)
		{
			return mid;
		}
		else if (area < t && area >= 0)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return high;

}

int main(int argc, char *argv[])
{
	ifstream ifs(argv[1]);
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	int lines = atoi(buf);

	for (int i = 0; i < lines; i++)
	{   
		long long result = processOneCase(ifs); 
		cout << "Case #" << (i+1) << ": " << result  << endl;
	}   
	return 0;
}
