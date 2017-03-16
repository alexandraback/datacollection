#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int cases;
	cin >> cases;

	for(int i=1; i<=cases; i++)
	{
		string retval;

		string input;
		cin >> input;


		while(input.find("Z") != string::npos)
		{
			retval += "0";
			input.erase(input.begin() + input.find("Z"));
			input.erase(input.begin() + input.find("E"));
			input.erase(input.begin() + input.find("R"));
			input.erase(input.begin() + input.find("O"));
		}
		while(input.find("X") != string::npos)
		{
			retval += "6";
			input.erase(input.begin() + input.find("S"));
			input.erase(input.begin() + input.find("I"));
			input.erase(input.begin() + input.find("X"));
		}
		while(input.find("W") != string::npos)
		{
			retval += "2";
			input.erase(input.begin() + input.find("T"));
			input.erase(input.begin() + input.find("W"));
			input.erase(input.begin() + input.find("O"));
		}
		while(input.find("U") != string::npos)
		{
			retval += "4";
			input.erase(input.begin() + input.find("F"));
			input.erase(input.begin() + input.find("O"));
			input.erase(input.begin() + input.find("U"));
			input.erase(input.begin() + input.find("R"));
		}
		while(input.find("G") != string::npos)
		{
			retval += "8";
			input.erase(input.begin() + input.find("E"));
			input.erase(input.begin() + input.find("I"));
			input.erase(input.begin() + input.find("G"));
			input.erase(input.begin() + input.find("H"));
			input.erase(input.begin() + input.find("T"));
		}
		while(input.find("S") != string::npos)
		{
			retval += "7";
			input.erase(input.begin() + input.find("S"));
			input.erase(input.begin() + input.find("E"));
			input.erase(input.begin() + input.find("V"));
			input.erase(input.begin() + input.find("E"));
			input.erase(input.begin() + input.find("N"));
		}
		while(input.find("V") != string::npos)
		{
			retval += "5";
			input.erase(input.begin() + input.find("F"));
			input.erase(input.begin() + input.find("I"));
			input.erase(input.begin() + input.find("V"));
			input.erase(input.begin() + input.find("E"));
		}
		while(input.find("I") != string::npos)
		{
			retval += "9";
			input.erase(input.begin() + input.find("N"));
			input.erase(input.begin() + input.find("I"));
			input.erase(input.begin() + input.find("N"));
			input.erase(input.begin() + input.find("E"));
		}
		while(input.find("H") != string::npos)
		{
			retval += "3";
			input.erase(input.begin() + input.find("T"));
			input.erase(input.begin() + input.find("H"));
			input.erase(input.begin() + input.find("R"));
			input.erase(input.begin() + input.find("E"));
			input.erase(input.begin() + input.find("E"));
		}
		while(input.find("N") != string::npos)
		{
			retval += "1";
			input.erase(input.begin() + input.find("O"));
			input.erase(input.begin() + input.find("N"));
			input.erase(input.begin() + input.find("E"));
		}


		sort(retval.begin(), retval.end());
		cout << "Case #" << i << ": " << retval << endl;
	}

	return 0;
}
