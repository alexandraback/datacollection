#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;


char ass(string a, string b)
{
	for (int i = 0; i < a.size(); ++i)
	{
		if ( b[i] != '?' &&
			a[i] != b[i])
			return false;
	}

	return true;
}

int main(int __an, char **__ag)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	while (Case--)	
	{
		string a , b;
		cin >> a >> b;

		printf("Case #%d: " , ++cases);

	
		int n = a.size();
		int N = pow((double)10,n);
		int diff = INT_MAX;
		string aa, bb;
		for (int i = 0; i < N; ++i)
		{
			stringstream aaa;
			aaa << setfill('0') << setw(n) << i;
			if( !ass(aaa.str() , a) ) continue;

			for (int j = 0; j < N; ++j)
			{
				stringstream bbb;
				bbb  << setfill('0') << setw(n) << j;
				if( !ass(bbb.str() , b) ) continue;

				if ( diff > abs(i-j))
				{
					diff = abs(i-j);
					aa = aaa.str();
					bb = bbb.str();
				}
			}
		}
		

		cout << aa << " " << bb << endl;
	}

	return 0;
}

