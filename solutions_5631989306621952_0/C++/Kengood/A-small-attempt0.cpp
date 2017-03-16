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




int main(int aN, char **aG)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	while (Case--)	
	{

		string in;
		cin >> in;		

		printf("Case #%d: " , ++cases );

		string out;
		out.push_back(in[0]);
		for (int i = 1 ; i < in.size(); ++i)
		{
			if ( out[0] > in[i])
				out.push_back( in[i]);
			else
				out.insert( out.begin(), in[i]);
		}
		cout << out << endl;


	}

	return 0;
}

