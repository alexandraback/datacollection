#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

bool is(char k)
{
	if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u')
		return false;
	return true;
}

bool f[1000010];

int main()
{
	//ifstream infile("test.in");
	//ifstream infile("A-small-attempt0.in");
	//ifstream infile("A-small-attempt1.in");
	ifstream infile("A-large.in");
	ofstream outfile("A.out", ios::out);
	int T;
	infile >> T; 
	int testcase;
	for (testcase = 1;testcase <= T;testcase++)
	{
		memset(f, 0, sizeof(f));
		string s;
		int n;
		infile >> s >> n;
		//set<p> l;
		int i;
		int j, k;
		int len = s.size();
		int cnt1 = 0;
		int cnt2 = 0;
		for (i = 0;i < len;i++)
		{
			if (is(s[i]))
			{
				cnt1++;
			}
			if (i == len-1 || !is(s[i+1]))
			{
				if (cnt1 >= n)
				{
					for (j = i;j >= i - cnt1 + 1;j--)
						f[j] = true;
				}
				cnt1 = 0;
			}
		}

		int l = 0;
		int r = 0;
		int m = 0;
		bool flag = true;
		if (f[0])
			flag = false;
		__int64 sum = 0;

		for (i = 0;i < len;i++)
		{
			if (!f[i])
			{
				m++;
				if (m == len)
				{
					sum -= (1 + len - n + 1)*(len - n + 1)/2;
					break;
				}
				if (i == len-1 || f[i+1])
				{
					if (flag || i == len-1)
						sum -= m*(m+1)/2;
					else
						sum -= (1+m+n-1)*(m+n-1)/2;
					flag = false;
					m = 0;
				}
			}
		}
		sum += (1 + len - n + 1)*(len - n + 1)/2;
		outfile << "Case #" << testcase << ": ";
		outfile << sum;
		outfile << endl;
	}
	return 0;
}