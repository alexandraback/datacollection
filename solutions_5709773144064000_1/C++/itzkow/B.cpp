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


ifstream fin ("C:\\CodeJam\\2014\\Qualifications\\B\\B-large.in");
ofstream fout ("C:\\CodeJam\\2014\\Qualifications\\B\\B-large.out");

int testCase = 0;


void Solve()
{
	int i,j,k;
	double C,F,X;

	fin>>C>>F>>X;
	
	double bestSolution;
	double nextSolution;
	double secondsPassed = 0;
	double currentF = 2;

	bestSolution = X / currentF;

	while(secondsPassed < bestSolution)
	{
		secondsPassed += C / currentF;
		currentF += F;
		nextSolution = secondsPassed + (X / currentF);
		if (bestSolution > nextSolution)
			bestSolution = nextSolution;

	}




	fout << "Case #" << testCase << ": "<<bestSolution<<endl;

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



