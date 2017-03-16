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
		int a, b;
		cin >> a >> b;
		int j;
		int cnt = 0;
		int dec;
		for (int i = a; i <= b; i++)
		{
			j = i;
			dec = 1;
			while(dec <= i)
			{
				dec *= 10;
			}
			dec /= 10;
			do {
				j = (j % dec) * 10 + j / dec;
				if (j > i && j >= a && j <= b)
					cnt++;
			} while(j != i);
		}
		cout << cnt << endl;
	}
	return 0;
}
