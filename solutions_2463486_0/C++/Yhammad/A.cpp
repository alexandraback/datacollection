#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<string.h>
#include<utility>
#include<stdlib.h>
#include<cstdio>
using namespace std;
bool isPal(int number)
{
	if (number < 10)
		return true;
	string tmp = "";
	while(number > 0)
	{
		tmp += (number%10);
		number /= 10;
	}
	for (int i = 0; i < tmp.size() - i - 1; ++ i)
	{
		if (tmp[i] != tmp[tmp.size() - i - 1])
			return false;
	}
	return true;
}
bool isFairSquare(int number)
{
	int sq = sqrt(number*1.0);
	if(number != sq*sq)
		return false;
	if (isPal(number) && isPal(sq))
		return true;
	return false;
}
int main()
{
	ifstream in ("C-small-attempt0.in");
	ofstream out ("output.txt");
	int t, a, b;
	in >> t;
	for (int z = 1; z <= t; ++ z)
	{
		in >> a >> b;
		int cnt = 0;
		for (int i = a; i <= b; ++ i)
		{
			if (isFairSquare(i))
				cnt ++;
		}
		out << "Case #" << z << ": " << cnt << endl;
	}
	return 0;
}