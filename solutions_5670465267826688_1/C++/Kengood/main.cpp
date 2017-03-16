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


string mainS;
int table[8][8];
char tt[256];
char calOneV(char s, char c)
{
	char t = table[tt[c]][abs(s)];
	if (s<0)
		t*=-1;
	s = t;
	return -s;
}

char calOne(char s, char c)
{
	char t = table[abs(s)][tt[c]];
	if (s<0)
		t*=-1;
	s = t;
	return s;
}

char cal(long long  start, long long  end)
{
	char s = tt[mainS[start++]];
	
	for (start; start < end; ++start)
	{		
		s = calOne(s,mainS[start]);
	}
	return s;
}


int main()
{	
	tt['i'] = 2;
	tt['j'] = 3;
	tt['k'] = 4;

	table[1][1] = 1; table[1][2] =  2; table[1][3] = 3; table[1][4] = 4;
	table[2][1] = 2; table[2][2] = -1; table[2][3] = 4; table[2][4] = -3;
	table[3][1] = 3; table[3][2] = -4; table[3][3] = -1; table[3][4] = 2;
	table[4][1] = 4; table[4][2] =  3; table[4][3] = -2; table[4][4] = -1;



	int Case, cases = 0;
	scanf("%d" , &Case);

	while (Case--)
	{
		long long  L , X;
		string in;
		cin >> L >> X >> in;
		mainS.clear();
		if(X > 999999)
			goto noway;
		for (long long  i = 0; i < X; ++i)
			mainS += in;

		char ans = 0;
		char ii = tt[ mainS[0] ];

		for (long long int i = 0 ; !ans&&i < mainS.size()-2; ++i)
		{
			if (ii == 2)
			{
				char jj = tt[ mainS[i+1] ];
				char kk = -67;
				for (long long  j = i+1 ; !ans&&j < mainS.size()-1; ++j)
				{
					if ( jj == 3 )
					{
						if ( kk == -67)
							kk = cal(j+1, mainS.size());
						if (kk == 4)
							ans = 1;
					}

					jj = calOne(jj,mainS[j+1]);

					if ( kk != -67)
						kk = calOneV(kk,mainS[j+1]);
				}
			}

			ii = calOne(ii,mainS[i+1]);

		}
		
		noway:;
		printf("Case #%d: %s\n" , ++cases, ans? "YES":"NO");
		
	}

	return 0;
}

