#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
using namespace std;


int main() {
    freopen("in.txt","r",stdin);
    freopen("tmp.txt","w",stdout);
	int t = 0, r, c, m;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >>r>>c>>m;
		cout << "Case #";
		cout << i + 1;
		cout << ":\n";
		if (m >= r*c)
		{
			cout << "Impossible" << endl;
			continue;
		}

		int d = (m%c == 0)? 0 : 1;
		if ( m +  m/c + d >= r*c)
		{
			cout << "Impossible" << endl;
			continue;
		}
		for (int j=0; j<r; j++)
		{
			for (int k=0; k<c; k++)
			{
				if (m!=0)
				{
					cout<<"*";
					m--;
				}
				else
				{
					if (k+1 == c && j+1 == r)
						cout <<"c";
					else
						cout<<".";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
