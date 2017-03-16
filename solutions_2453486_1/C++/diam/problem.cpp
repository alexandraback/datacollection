
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
#include <unordered_map>


using namespace std;


int a[500][500];
int usedi[500];
int usedj[500];
char str[50];
string s[5];
int main()
{
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);			
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		gets(str);
		for (int i = 0 ;i < 4; i++)
		{
			gets(str);
			s[i] = str;			
		}
		//gets(str);
		int state = -1;
		for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (s[i][j] == '.')
						state = -2;
		for (int p = 0; p <2 ; p++)
		{
			char c;
			if (p == 0)
				c = 'X';
			else
				c = 'O';
			for (int i = 0; i < 4; i++)
			{
				bool bad = false;
				for (int j = 0; j < 4; j++)
					if (!(s[i][j] == c  || s[i][j] == 'T'))
						bad = true;
				if (bad == false)
					state = p;

			}

			for (int j = 0; j < 4; j++)
			{
				bool bad = false;
				for (int i = 0; i < 4; i++)
					if (!(s[i][j] == c  || s[i][j] == 'T'))
						bad = true;
				if (bad == false)
					state = p;

			}

			
			{
				bool bad = false;
				for (int j = 0; j < 4; j++)
					if (!(s[j][j] == c  || s[j][j] == 'T'))
						bad = true;
				if (bad == false)
					state = p;

			}

			{
				bool bad = false;
				for (int j = 0; j < 4; j++)
					if (!(s[j][3-j] == c  || s[j][3-j] == 'T'))
						bad = true;
				if (bad == false)
					state = p;

			}


		}
		if (state == 0)
			printf("Case #%d: X won\n",test);
		if (state == 1)
			printf("Case #%d: O won\n",test);
		if (state == -2)
			printf("Case #%d: Game has not completed\n",test);
		if (state == -1)
			printf("Case #%d: Draw\n",test);


	}
		
	return 0;			
}     
