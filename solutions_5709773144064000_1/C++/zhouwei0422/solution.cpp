#include <algorithm>  
#include <bitset>  
#include <cctype>  
#include <cmath>  
#include <complex>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <fstream>
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>   
using namespace std;

ifstream ifile;
ofstream ofile;

int T;
string c, f, x;
double C, F, X;

void solve(int cases)
{
	double cookies = 0;
	double adds = 2;
	double res = X/adds;
	double t = 0;

	while(true)
	{
		if((t+C/adds-res)>1e-9)break;
		else 
		{
			t+=C/adds;
			adds+=F;
			if((t+X/adds-res)>1e-9)break;
			else res = t+X/adds;
		}
	}
	ofile<<"Case #"<<cases+1<<": "<<setprecision(15)<<res<<endl;
}

int main(void)
{
	ifile.open("input.txt");
	ofile.open("output.txt");
	
	ifile>>T;
	for(int cases = 0; cases < T; cases++)
	{
		ifile>>c>>f>>x;
		C= strtod(c.c_str(),NULL);
		F= strtod(f.c_str(),NULL);
		X= strtod(x.c_str(),NULL);
		solve(cases);
	}

	ifile.close();
	ofile.close();
	return 0;
}