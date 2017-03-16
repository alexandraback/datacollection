#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define A first
#define B second

int X[2000001], N[2000001];

int sort(int X)
{
	char s[100];
	itoa(X, s, 10);
	int i, j, k=strlen(s), temp, res=X;
	for (i=0; i<k; ++i)
	{
		if (s[i]!='0')
		{
			temp = 0;
			for (j=0; j<k; ++j)
				temp = temp*10+s[(i+j)%k]-'0';
			if (temp < res)
				res = temp;
		}
	}
	return res;
}

int main()
{
	long long i, j, A, B, T;
	cin >> T;
	for (i=0; i<=2000000; ++i)
		X[i] = sort(i);
	for (int t=1; t<=T; ++t)
	{
		cin >> A >> B;
		for (i=A; i<=B; ++i)
			N[X[i]] = 0;
		j = 0;
		for (i=A; i<=B; ++i)
			j+= N[X[i]]++;
		cout << "Case #" << t << ": " << j << endl;
	}
	return 0;
}
