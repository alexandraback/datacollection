#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>

using namespace std;
#define PI 3.14159265358979323846264338327950288
#define fill_(x,v) memset(x,v,sizeof(x))
#define for_(i,a,b) for (__typeof(b) i=(a); i<(b); i++)
#define min(x,y) (((x)>(y)) ? (y) :(x))
#define max(x,y) (((y)>(x)) ? (y) :(x))

ifstream fin("c:\\1B\\A-small-attempt0.in");
ofstream fout("c:\\1B\\A.out");

int run()
{
	vector<double> J;
	int N;
	fin >> N;
	double sum = 0;
	for ( int i = 0; i < N; i++)
	{
		double tmp;
		fin >> tmp;
		J.push_back(tmp);
		sum += tmp;
	}
	
	for ( int i = 0; i < N; i++ )
	{
		double l = 0;
		double r = sum;
		while ( r-l > 0.0000001)
		{
			//cout<<l<<' '<<r<<endl;
			double m = ( l + r ) / 2;
			double tmp = J[i] + m;
			double ts = sum - m;
			bool nt = false;
			for ( int p = 0; p < N; p++ )
			if ( p != i )
			{
				if ( tmp > J[p] ) ts -= tmp - J[p];
				if ( ts < 0 )
				{
					
					nt = true;
					break;
				}
			}
			if ( nt ) r = m;
			else
			l = m;
		}
		fout << fixed;
		fout<<setprecision(10)<<l/sum*100<<' ';	
	}
	fout<<endl;
	return 0;
}
int main() {
  
	int N;
	fin>> N;
	
	for( int n = 1; n <= N; n++)
	{
		fout<<"Case #"<<n<<": ";
		
		int ret = run();
		//printf("Case #%d: %d\n", n, ret);
		//cout<<"Case #"<<n<<": "<endl;
		//fout << fixed;
		//fout<<"Case #"<<n<<": "<<setprecision(10)<<ret<<endl;
   }
   return 0;
}