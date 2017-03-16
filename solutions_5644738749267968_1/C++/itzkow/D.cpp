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


ifstream fin ("C:\\CodeJam\\2014\\Qualifications\\D\\D-large.in");
ofstream fout ("C:\\CodeJam\\2014\\Qualifications\\D\\D-large.out");

int testCase = 0;

double NAOMI[1000];
double KEN[1000];


void Solve()
{
	int i,j,k;
	int N;

	fin>>N;
	
	for (i = 0; i < N; i++)
		fin>>NAOMI[i];
	for (i = 0; i < N; i++)
		fin>>KEN[i];
	
	std::sort(NAOMI, NAOMI + N, std::less<double>());
	std::sort(KEN, KEN + N, std::less<double>());

	int naomiWarScore = 0;
	int naomiDeceitfulWarScore = 0;

	int kenBiggestIndex = N-1;

	naomiWarScore = N;

	for (i = N-1; i >= 0; i--) {
		if (NAOMI[i] < KEN[kenBiggestIndex]) {
			naomiWarScore--;
			kenBiggestIndex--;
		}
	}

	int kenLowestIndex = 0;
	naomiDeceitfulWarScore = 0;

	
	for (i = 0; i < N; i++) {
		if (NAOMI[i] > KEN[kenLowestIndex]) {
			naomiDeceitfulWarScore++;
			kenLowestIndex++;
		}
	}



	fout << "Case #" << testCase << ": "<<naomiDeceitfulWarScore<<" "<<naomiWarScore<<endl;

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



