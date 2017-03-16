#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int stepMap[1000005];

int rDig(int a)
{
	int res = 0;
	while(a)
	{
		res *= 10;
		res += a % 10;
		a /= 10;
	}
	return res;
}

int main()
{
	int ncase;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> ncase;

	memset(stepMap, 0, sizeof(stepMap));
	stepMap[1] = 1;
	
	for(int i = 1;i < 1000001;i++)
	{
		if (i + 1 < 1000001 && (stepMap[i + 1] == 0 || stepMap[i + 1] > stepMap[i] + 1))
			stepMap[i + 1] = stepMap[i] + 1;
		
		int rN = rDig(i);
		if (stepMap[rN] == 0 || stepMap[rN] > stepMap[i] + 1)
			stepMap[rN] = stepMap[i] + 1;
	
		rN = rDig(rN);
		if (stepMap[rN] == 0 || stepMap[rN] > stepMap[i] + 1)
			stepMap[rN] = stepMap[i] + 1;

	}

	for(int icase = 0;icase < ncase;icase++)
	{
		int n;
		cin >> n;
		
		cout << "Case #" << icase + 1 << ": " << stepMap[n] << endl;
	}

	return 0;
}
