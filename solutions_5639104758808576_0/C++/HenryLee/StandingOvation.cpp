#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(void)
{
	int t;

	cin >> t;

	for (int i=1; i<=t; i++)
	{
		int smax;
		int invited;
		int seated;
		string slist;
		vector <int> vlist;

		cin >> smax;

		cin >> slist;

		for (int j=0; j<slist.length(); j++)
		{
			int si;

			si = slist[j] - '0';
			vlist.push_back(si);
		}

		invited = 0;
		seated = 0;

		for (int j=0; j<vlist.size(); j++)
		{
			if (seated < j)
			{
				invited += j-seated;
				seated = j;
			}

			seated += vlist[j];
		}

		printf("Case #%d: %d\n", i, invited);
	}
}
