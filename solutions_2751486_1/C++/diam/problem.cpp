
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


char str[2000000];
int f [2000000];
int main()
{
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);			
	int tests;
	scanf("%d\n", &tests);
	for (int test = 1; test <= tests; test++)
	{
		
		int n;
		scanf("%s%d\n", &str, & n);
		//printf("%s", str);
		long long anw = 0;
		string s = str;
		long long le = 0;
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (!(s[i] == 'a' ||s[i] == 'e' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == 'i'))
				le = le+1;
			else
				le = 0;

			if (n <= le)
				f[i] = i-n+1+1;
			else
				f[i] = f[i-1];
			anw += f[i];

		}
		
		printf("Case #%d: %I64d\n",test, anw );		

	}
		
	return 0;			
}     
