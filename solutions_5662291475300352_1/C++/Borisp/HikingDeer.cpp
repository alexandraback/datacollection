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
#define epsilon 0.000000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

struct hiker
{
	int startingPosition;
	int speed;
	double momentOfZero;
};

const bool printTest = false;
const int testNum = 26;
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
		cin >>n ;
		if (printTest && testCounter == testNum) cerr << n << endl;
		vector<hiker> hikers;
		int h, d, m;
		for (int i = 0; i < n; i++)
		{
			cin >> d >> h >> m;
			if (printTest && testCounter == testNum) cerr << d << " " << h << " " << m << endl;

			
			for (int j = 0; j < h; j++)
			{
				hiker h1;
				h1.speed = m + j;
				h1.startingPosition = d;
				h1.momentOfZero = (360.0 - (double)d) / (360.0 / (double) h1.speed);
				hikers.push_back(h1);
			}
			
		}
		int minm = hikers.size();
		for (int i = 0; i < hikers.size(); i++)
		{
			double passingMoment  = hikers[i].momentOfZero + epsilon;

			int tmp = 0;
			for (int j = 0; j < hikers.size() && tmp < minm; j++)
			{
				if (hikers[j].momentOfZero > passingMoment)
					tmp++;
				else {
					tmp += (int)(floor((passingMoment - hikers[j].momentOfZero) / hikers[j].speed + epsilon) + epsilon);
				}
			}
			minm = min (minm, tmp);
		}
		cout << minm << endl;
	}
	return 0;
}
