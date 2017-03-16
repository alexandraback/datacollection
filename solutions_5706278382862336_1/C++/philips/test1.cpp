// test1.cpp : ¶¨Òå¿ØÖÆÌ¨Ó¦ÓÃ³ÌÐòµÄÈë¿Úµã¡£
//

//#include "stdafx.h"
#if 1
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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;
vector<string> splitStr(string line)
{
	istringstream iss(line);
		vector<string> tokens;
		copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
		  back_inserter<vector<string> >(tokens));
	return tokens;
}
string combineStr(vector<string> &s)
{
	string t;
	for (int i = 0; i < s.size(); i ++)
		t = t + s[i];
	return t;
}
bool compare(vector<string>& s, vector<string>& d)
{
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i ++)
		if (s[i] != d[i])
			return false;
	return true;
}

int main(int argc, char * argv[])
{
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);
	int nCaseNum;
	cin >> nCaseNum;
	char buf[1000];
	for (int i = 0; i < nCaseNum; i ++)
	{
			long long int a, b;
			char ck;

			cin >> a >> ck >> b;
			long long int m , n,c;
			m =a ; n = b;
			while (b != 0)
			{
				c = a%b;a=b; b=c;
			}
			m /=a;
			n /=a;
			if (m/n == 1)
			{
				cout << "Case #" << i +1 << ": " << "1";
				break;
			}
			if (n & (n-1))
				cout << "Case #" << i +1 << ": " << "impossible";
			else{
				int cn = 0;
				while (m < n)
				{
					cn ++;
					n = n /2;
				}
				cout << "Case #" << i +1 << ": " << cn;
			}
			
			cout << endl;
	
	
	}

	return 1;
}
#endif