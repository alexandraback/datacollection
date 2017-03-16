#include <iostream>
#include <sstream>
#include <climits>
#include <cstddef>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;


int T;

int main()
{
	cin>>T;

	for (int CASE = 1; CASE <= T; CASE++)
	{
		int X,Y;
		cin>>X>>Y;

		cout<<"Case #"<<CASE<<": ";
		for (int i = 0; i < abs(X); i++)
		{
			if (X>0) cout<<"WE";
			else if (X<0) cout<<"EW";
		}
		for (int i = 0; i <abs(Y); i++)
		{
			if (Y>0) cout<<"SN";
			else if (Y<0) cout<<"NS";
		}
		cout<<endl;
	}

	return 0;
}