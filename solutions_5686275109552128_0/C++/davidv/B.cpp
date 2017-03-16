#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int divrup(int a, int b)
{
	return (a+b-1)/b;
}

void doCase()
{
	int D;
	
	cin >> D;
	
	vector<int> P(D);
	
	for (int i=0; i<D; i++)
		cin >> P[i];
	
	int maxTime = 10000;
	
	for (int stack=1; stack<1000; stack++)
	{
		int special = 0;
		for (int i=0; i<D; i++)
		{
			special += divrup(max(P[i]-stack, 0), stack);
		}
		if (stack+special < maxTime)
			maxTime = stack+special;
	}
	
	cout << maxTime << endl;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		cout << "Case #" << i+1 << ": ";
		doCase();
	}
	
	return 0;
}
