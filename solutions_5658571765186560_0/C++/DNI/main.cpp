#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;



#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

bool Win(int nOmino, int m, int n)
{
	if(m > n) swap(m,n);
	if(nOmino==1)
	{
		return true;
	}
	if(nOmino == 2)
	{
		if(m==1 && n==1)
			return false;
		if(m==1 && n==3)
			return false;
		if(m==3 && n==3)
			return false;
		return true;
	}
	if(nOmino == 3)
	{
		if(m==2 && n==3)
			return true;
		if(m==3 && n==3)
			return true;
		if(m==3 && n==4)
			return true;
		return false;
	}
	if(nOmino == 4)
	{
		if(m==3 && n==4)
			return true;
		if(m==4 && n==4)
			return true;
		return false;
	}
}

int main()
{

	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);

	long long  t;
	cin >> t;
	for(long long tt = 0; tt < t; tt++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		string sRes = "RICHARD";
		if(Win(a,b,c))
		{
			sRes = "GABRIEL";
		}

		printf("Case #%lld: %s\n", tt+1, sRes.c_str());
		
	}


	return 0;
}