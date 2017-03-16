//compiled in vc
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
// C++
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;

int cases , Case = 1;
int total = 0;

char tt[128];
int n;
vector<int> input;

char brute(int now, int now2, int idx)
{
	if( now == now2 && now )
	{
		for(int i = 0 ; i < n; ++i)
			if( tt[i] == 1 )
				cout << input[i] << " ";
		puts("");

		for(int i = 0 ; i < n; ++i)
			if( tt[i] == 2 )
				cout << input[i] << " ";
		puts("");
		return 1;
	}
	if( idx == n ) return 0;

	tt[idx] = 1;
	if( brute(now+input[idx], now2 , idx+1) )
	{
		return 1;
	}


	tt[idx] = 2;
	if( brute(now , now2+input[idx], idx+1) )
	{
		return 1;
	}

	tt[idx] = 0;
	if( brute(now , now2, idx+1) )
	{
		return 1;
	}

	return 0;
}

int main()
{	
	scanf("%d" , &cases);

	
	while( cases-- )
	{
		printf("Case #%d: \n" , Case++);   
		
		
		input.clear();
		cin >> n;
		total = 0;
		memset(tt,0,sizeof(tt));
		for(int i = 0 ; i < n; ++i)
		{
			int t;
			cin >>  t;
			input.push_back(t);
		}
		if( !brute(0,0,0) )
			puts("Impossible");
		
	}


	return 0;
}
