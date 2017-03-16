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
bool isPal(unsigned long long  number)
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
bool isFairSquare(unsigned long long number)
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
	ifstream in ("C-large-1.in");
	ofstream out ("output.txt");
	unsigned long long fairSquare[39] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
	unsigned long long t, a, b;
	in >> t;
	for (unsigned long long z = 1; z <= t; ++ z)
	{
		in >> a >> b;
		unsigned long long cnt = 0;
		for (int i = 0; i < 39; ++ i)
		{
			if (fairSquare[i] > b)
				break;
			if (fairSquare[i] >= a)
				cnt ++;
		}
		out << "Case #" << z << ": " << cnt << endl;
	}
	return 0;
}