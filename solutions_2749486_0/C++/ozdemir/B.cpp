/* Ömer Özdemir */

#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include<fstream>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream myStream;
ofstream outfile;
int T,X,Y;
string p1x="WE";
string n1x="EW";
string p1y="SN";
string n1y="NS";
int main()
{
	outfile.open("B-small-output1.in");
	myStream.open("B-small-attempt1.in");

	if(myStream.is_open())
	{
		myStream >> T ;
		for(int i=1;i<=T;i++)
		{
			string ans="";
			myStream >> X >> Y ;
			if(X>0)
			{
				for(int i=1;i<=X;i++)
				{
					ans+=p1x;
				}
			}
			else
			{
				for(int i=1;i<=abs(X);i++)
				{
					ans+=n1x;
				}
			}
		
			if(Y>0)
			{
				for(int i=1;i<=Y;i++)
				{
					ans+=p1y;
				}
			}
			else
			{
				for(int i=1;i<=abs(Y);i++)
				{
					ans+=n1y;
				}
			}
			outfile<<"Case #"<<i<<": "<<ans<<endl;
		}
	}
	return 0;
}
