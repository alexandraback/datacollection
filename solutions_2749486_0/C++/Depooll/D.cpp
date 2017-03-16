#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string.h>
#pragma comment(linker, "/STACK:10000000") 
#define md 1000000007

using namespace std;

int test,t,i,n,x,y;
int main()
{
	ifstream f("input.txt");
	ofstream g("output.txt");
	
	f>>t;

	for (test = 1; test<=t;test++)
	{
		f>>x>>y;
		g<<"Case #"<<test<<": ";
		for (i=1;i<=abs(x);i++)
		{
			if (x>0) g<<"WE";
			else g<<"EW";	
		}
		for (i=1;i<=abs(y);i++)
		{
			if (y>0) g<<"SN";
			else g<<"NS";	
		}
		g<<endl;
	}
}
