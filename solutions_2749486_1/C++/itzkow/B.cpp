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


ifstream fin ("C:\\CodeJam\\Round1C\\B\\B-large.in");
ofstream fout ("C:\\CodeJam\\Round1C\\B\\B-large.out");

int testCase = 0;


bool isPossible(int X,int Y, int k,bool print)
{
	//if (k > (abs(X)+abs(Y))/2)
	//	return true;
	if (k == 0)
	{
		if (X==0 && Y ==0)
			return true;
		return false;
	}


	bool can = false;
	if (abs(X)>abs(Y)) {
		if (X>0) {
			if (isPossible(X-k,Y,k-1,print)) {
				if (print)
					fout<<"E";
				return true;
			}
		}
		if (X<0) {
			if (isPossible(X+k,Y,k-1,print)) {
				if (print)
					fout<<"W";
				return true;
			}
		}
	} else {
		if (Y>0) {
			if (isPossible(X,Y-k,k-1,print)) {
				if (print)
					fout<<"N";
				return true;
			}
		}
		if (Y<0) {
			if (isPossible(X,Y+k,k-1,print)) {
				if (print)
					fout<<"S";
				return true;
			}
		}
	}
	return false;


	

}

void Solve()
{
	int X,Y;
	int k = 0;

	fin>>X>>Y;
	bool pos = false;
	for (k = 1; k < 10*(abs(X) + abs(Y)); k++) {
		if (isPossible(X,Y,k,false)) {
			pos = true;
			break;
		}
	}
	if (!pos )
		cout<<"Weird"<<endl;
	

	
	fout << "Case #" << testCase << ": ";
	isPossible(X,Y,k,true);
	fout<<endl;
	

}

/*
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
*/




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



