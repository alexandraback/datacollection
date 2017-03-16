#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <sstream>
#include <map>
#include <limits>

using namespace std;

int main()
{
	int diff[26] = {'y'-'a', 'h'-'b', 'e'-'c', 's'-'d','o'-'e','c'-'f', 'v'-'g', 'x'-'h', 'd'-'i', 'u'-'j', 'i'-'k', 'g'-'l', 'l'-'m', 'b'-'n', 'k'-'o', 'r'-'p', 'z'-'q', 't'-'r', 'n'-'s', 'w'-'t', 'j'-'u', 'p'-'v', 'f'-'w', 'm'-'x', 'a'-'y', 'q'-'z'};
	int T;
	string str;
	stringstream ss;
	getline(cin, str);
	ss<<str;
	ss>>T;
	for(int t=1; t<=T; t++)
	{
		getline(cin, str);
		for(int i=0; i<str.length(); i++)
		{
			if(str[i] >= 'a' && str[i] <= 'z')
			{
				int j = str[i] - 'a';
				str[i] = str[i] + diff[j];
			}
		}
		cout<<"Case #"<<t<<": "<<str<<endl;
	}
	
	return 0;
}