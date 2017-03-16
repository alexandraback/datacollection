#include <iostream>
#include <fstream>
#include <list>

//using http://www.shoup.net/ntl/ for handling large numbers
#include <NTL/ZZ.h>
NTL_CLIENT

int main(int argc,char *argv[])
{
	(void) argc;
	(void) argv;
	
	ifstream precomp;
	
	//use a list of pre computed values
	precomp.open("pre-3.out");
	list<ZZ> values;
	
	ZZ last = to_ZZ("40000000000000000000000004000000000000000000000000900000000000000000000000040000000000000000000000004");
	ZZ q;
	ZZ w = to_ZZ(0);
	while(last != w)
	{
		precomp >> q >> w;
		values.push_back(w);
	}
	
	int numTests;
	
	cin >> numTests;
	
	
	
	for(int i = 0;i < numTests;i++)
	{
		ZZ a;
		ZZ b;
		cin >> a >> b;
		
		ZZ result = to_ZZ(0);
		
		for(list<ZZ>::iterator it = values.begin();it != values.end();it++)
		{
			if(*it >= a && *it <= b)
			{
				result++;
			}
		}
		
		
		
		cout << "Case #" << i+1 << ": " << result << endl;
	}
	
	return 0;
}


