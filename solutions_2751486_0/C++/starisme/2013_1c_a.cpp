#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

struct p
{
	int x;
	int y;
}l[100100];

bool is(char k)
{
	if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u')
		return false;
	return true;
}
int main()
{
	//ifstream infile("test.in");
	ifstream infile("A-small-attempt0.in");
	//ifstream infile("A-small-attempt1.in");
	//ifstream infile("A-large.in");
	ofstream outfile("A.out", ios::out);
	int T;
	infile >> T; 
	int testcase;
	for (testcase = 1;testcase <= T;testcase++)
	{
		string s;
		int n;
		infile >> s >> n;
		//set<p> l;
		int i;
		int j, k;
		int len = s.size();
		int e = 0;
		for (i = 0;i < len;i++)
		{
			for (j = i+n-1;j < len;j++)
			{
				int cnt = 0;
				bool flag = false;
				for (k = i;k <= j;k++)
				{
					if (is(s[k]))
					{
						cnt++;
					}
					else
						cnt = 0;
					if (cnt >= n)
					{
						flag = true;
					}
				}
				if (flag)
				{
					p tmp;
					tmp.x = i;
					tmp.y = j;
					flag = true;
					for (k = 0;k < e;k++)
					{
						if (l[i].x == i && l[i].y == j)
						{
							flag = false;
						}
					}
					if (flag)
					{
						l[e].x = i;
						l[e].y = j;
						e++;
					}
				}
			}
		}
		outfile << "Case #" << testcase << ": ";
		outfile << e;
		outfile << endl;
	}
	return 0;
}