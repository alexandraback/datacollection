#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm>
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <complex>
#include <sstream> 
#include <numeric>
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <regex>
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		string s;
		cin >> s;
		while (s.size() && s.back() == '+')
			s.pop_back();
		s = regex_replace(s, regex("[+]+"), string("+"));
		s = regex_replace(s, regex("[-]+"), string("-"));
		printf("Case #%d: %d\n", test, s.size());
	}
}