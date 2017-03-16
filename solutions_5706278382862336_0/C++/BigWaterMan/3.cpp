#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<time.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int z = 0; z < T; ++z)
	{
		printf("Case #%d: ", z + 1);
		int sum = 0;
		long long a, b;
		char ch;
		cin >> a >>ch>> b;
		int count;
		count = 0;
		int pos;
		pos = 45;
		while (count <= 40 && a != 0)
		{
			count++;
			a = a * 2;
			if (a >= b)
			{
				a = a - b;
				if (pos>count)pos = count;
			}
			
		}
		if (count >= 40)cout << "impossible" << endl;
		else
		cout << pos << endl;

		
	}
}