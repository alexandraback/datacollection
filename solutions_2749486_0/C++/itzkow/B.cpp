#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
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
typedef long long LL;


ifstream fin ("C:\\CodeJam\\Round1C\\B\\B-small-attempt1.in");
ofstream fout ("C:\\CodeJam\\Round1C\\B\\B-small-attempt1.out");

int testCase = 0;


void Solve()
{
	int X,Y;

	fin>>X>>Y;

	int i;

	fout << "Case #" << testCase << ": ";
	if (X > 0)
	{
		for (i=0;i<X;i++)
			fout<<"WE";
	} else if (X<0) {
		
		for (i=0;i<abs(X);i++)
			fout<<"EW";

	}


	
	if (Y > 0)
	{
		for (i=0;i<Y;i++)
			fout<<"SN";
	} else if (Y<0) {
		
		for (i=0;i<abs(Y);i++)
			fout<<"NS";

	}




	fout << endl;

}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();

	}

	cout<<"finished"<<endl;
	getchar();

}



