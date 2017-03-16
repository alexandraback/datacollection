#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>

typedef long long ll;
typedef double dub;

using namespace std;

bool isc(char c)
{
	return c != 'a' && c != 'e' && c!= 'i' && c!= 'o' && c!= 'u';
}

void runTest()
{
	string name;
	int n;
	cin >> name >> n;
	
	int result = 0;
	int numEnd = 0;
	int row = 0;
	int lastStart = -1;
	
	for(int i = 0;i < name.size();i++)
	{
		if(isc(name.at(i)))
		{
			row++;
		}
		else {
			row = 0;
		}
		if(row >= n)
		{
			numEnd += i - lastStart - n + 1;
			
			lastStart = i - n + 1;
		}
		result += numEnd;
	}
	cout << result << endl;
}


int main(int argc, const char * argv[])
{
	(void) argc;
	(void) argv;
	int numTests;
	cin >> numTests;
	srand(time(NULL));
	
	for(int i =0;i < numTests;i++)
	{
		cout << "Case #" << i + 1 << ": ";
		runTest();
	}
}
