#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

bool iscons(char c)
{
	return !(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}


int main()
{
	freopen("input.in","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc=  1; tc<=TC; ++tc)
	{
		int X,Y;
		cin >> X >> Y;
		string A = "";
		if(X > 0)
			for(int i = 0; i < X; ++i)
				A += "WE";
		else
			for(int i = 0; i < -X; ++i)
				A += "EW";
		
		if(Y > 0)
			for(int i = 0; i < Y; ++i)
				A += "SN";
		else
			for(int i = 0; i < -Y; ++i)
				A += "NS";
		cout <<"Case #"<<tc<<": "<< A << endl;
	}
}
