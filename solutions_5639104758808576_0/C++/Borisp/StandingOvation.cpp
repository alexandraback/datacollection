#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int n;
		cin >> n;
		string str;
		cin >> str;
		int toAdd = 0;
		int current = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (current < i && str[i] != '0')
			{
				toAdd += i - current;
				current += i - current;
			} 
			current += str[i] - '0';
		}
		cout << toAdd << endl;
	}
	return 0;
}
