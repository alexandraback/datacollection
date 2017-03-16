
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

vector<__int64> num;
char str[100];
int main()
{
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);			
	int tests;
	scanf("%d", &tests);
	for (__int64 i = 1; i <= 10000000; i++)
	{
		sprintf(str, "%I64d", i);
		int sl = strlen(str);
		int bad = false;
		for (int k = 0; k < sl; k++)
			if (str[k] != str[sl-1-k])
				bad = true;
		if (bad)
			continue;
		sprintf(str, "%I64d", i*i);
		sl = strlen(str);
		bad = false;
		for (int k = 0; k < sl; k++)
			if (str[k] != str[sl-1-k])
				bad = true;
		if (bad)
			continue;
		num.push_back(i*i);
		//printf("%I64d  %I64d\n", i*i, i);
	}
	for (int test = 1; test <= tests; test++)
	{

		__int64 a, b;
		scanf("%I64d%I64d", &a, &b);
		int cnt = 0;
		for (int i = 0; i < num.size(); i++)
			if (a <= num[i]  && num[i] <= b)
				cnt++;

		


			printf("Case #%d: %d\n",test, cnt);
		
	}
		
	return 0;			
}     
