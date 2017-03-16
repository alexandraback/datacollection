#include <iostream>
#include <string>
//#include <Cmath>
#include <algorithm>
//#include <sstream>
#include <fstream>
//#include <vector>

using namespace std;

int main()
{
	ofstream output;
	output.open ("output03.in");
	
	int T, X, Y;
	string ans;
	
	cin >> T;
	
	for (int i=0; i< T; ++i)
	{
		cin >> X >> Y;
		
		int Xc=0, Yc=0;
		ans="";
		while (Xc!=X)
		{
			if (Xc<X)
			{
				ans +="WE";
				++Xc;
			}
			else
			{
				ans +="EW";
				--Xc;
			}
		}
		while (Yc!=Y)
		{
			if (Yc<Y)
			{
				ans +="SN";
				++Yc;
			}
			else
			{
				ans +="NS";
				--Yc;
			}
		}
		output << "Case #"<<i+1<<": "<<ans<< endl;
	}
	output.close();
	return 0;
}