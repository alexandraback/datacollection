// Round1c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

int fun()
{
	int S,F;
	char c;
	cin >> S;
	cin >> c;
	cin >> F;
	int s = S, f = F;
	while (s != 0)
	{
		int tmp = s;
		s = f % s;
		f = tmp;
	}
	S = S / f;
	F = F / f;

	if ((F & (F - 1)) != 0)
		return -1;
	else
	{
		
		double r1 = log(F) / log(2);
		double r2 = log(S) / log(2);
		int re = (int)r1 - (int)r2;
		return re;
	}
		
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int result = fun();
		if (result >= 0)
			cout << "Case #" << i << ": " << result << endl;
		else
			cout << "Case #" << i << ": impossible" << endl;
	}


	system("pause");
	return 0;
}

