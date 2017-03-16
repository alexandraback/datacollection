#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
		int b;
		long long m;
		cin >> b >> m;
		if(b == 2)
		{
			if(m == 1)
				cout << "Case #" << casito << ": POSSIBLE" << endl << "01" << endl << "00" << endl;
			else
				cout << "Case #" << casito << ": IMPOSSIBLE" << endl;
			continue;
		}
		vector<long long> vec(b);
		vec[b-1] = 1;
		vec[b-2] = 1;
		for(int i=b-3;i>=1;i--)
			vec[i] = 2*vec[i+1];
		if(2*vec[1] < m)
			cout << "Case #" << casito << ": IMPOSSIBLE" << endl;
		else
		{
			cout << "Case #" << casito << ": POSSIBLE" << endl;
			cout << "0";
			for(int i=1;i<b;i++)
			if(m >= vec[i])
			{
				cout << "1";
				m-=vec[i];
			}
			else
				cout << "0";
			cout << endl;
			for(int i=1;i<b;i++)
			{
				for(int j=0;j<=i;j++)
					cout << "0";
				for(int j=i+1;j<b;j++)
					cout << "1";
				cout << endl;
			}
		}
	}
}