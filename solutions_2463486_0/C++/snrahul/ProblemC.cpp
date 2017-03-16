#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <map>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

bool checkPali(string temp)
{
	long n = temp.length()/2;
	for(long i = 0; i < n; i++)
	{
		if (temp[i]!=temp[temp.length()-i-1])
			return false;
	}
	return true;
}

int main()
{
	int n;
	ifstream in("C-small-attempt0.in");
	ofstream out("output.out");
	in >> n;
	for(int cases = 1; cases <= n; cases++)
	{
		long a, b;
		in >> a >> b;
		long countme=0;
		for(long i = a; i <= b; i++)
		{
			long temp1=i, temp2;
			stringstream s , s1;
			s << temp1;
			bool check;
			check = checkPali(s.str());
			if (check)
			{
				double val = sqrt(i);
				if (fmod(val, 1) < 1e-15)
				{
					temp2 = sqrt(i);
					s1 << temp2;
					check = checkPali(s1.str());
				}
				else
					check = false;
			}
			if (check)
				countme++;
		}
		out << "Case #" << cases << ": " << countme << endl;
	}
	system("pause");
	return 0;
}