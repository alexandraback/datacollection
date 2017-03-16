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


ifstream fin ("C:\\CodeJam\\2015\\Qualifications\\C\\C-small-attempt0.in");
ofstream fout ("C:\\CodeJam\\2015\\Qualifications\\C\\C-small-attempt0.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/


int MUL(int x, int y)
{
	if (x<0)
		return -MUL(-x,y);
	if (y<0)
		return -MUL(x,-y);
	if(x==1)
		return y;
	if (y==1)
		return x;
	if (x==2)
	{
		if(y==2)
			return -1;
		if(y==3)
			return 4;
		if(y==4)
			return -3;
	}
	if (x==3)
	{
		if(y==2)
			return -4;
		if(y==3)
			return -1;
		if(y==4)
			return 2;
	}
	if (x==4)
	{
		if(y==2)
			return 3;
		if(y==3)
			return -2;
		if(y==4)
			return -1;
	}
	cout<<"ERROR";
	return 0;
}

char D[10001];
char DD[10*10001];

void Solve()
{

	int L;
	LL X;
	int mul;
	int i;

	fin>>L>>X;
	fin>>D;

	
	mul = 1;
	for (i = 0; i < L; i++)
	{
		int num = D[i]-'i'+2;
		mul = MUL(mul, num);
	}
	if (X == 1)
	{
		if (mul != -1)
		{
			fout << "Case #" << testCase << ": "<<"NO"<<endl;
			return;
		}
	}
	if (X > 1)
	{
		if (mul == 1)
		{
			fout << "Case #" << testCase << ": "<<"NO"<<endl;
			return;
		}
		else if (mul == -1)
		{
			if (X % 2 == 0)
			{
				fout << "Case #" << testCase << ": "<<"NO"<<endl;
				return;
			}
		}
		else
		{
			if ((X-2) % 4 != 0)
			{
				fout << "Case #" << testCase << ": "<<"NO"<<endl;
				return;
			}
		}


	}




	int DDL = L*min(X,(LL)10);
	
	for (i = 0; i < DDL; i++)
	{
		DD[i]=D[i%L];
	}

	
	bool found = false;
	mul = 1;
	for (i = 0; i < DDL; i++)
	{
		int num = DD[i]-'i'+2;
		mul = MUL(mul, num);
		if (mul == 2)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		fout << "Case #" << testCase << ": "<<"NO"<<endl;
		return;
	}
	found = false;
	i++;
	mul=1;
	while(i < DDL)
	{
		int num = DD[i]-'i'+2;
		mul = MUL(mul, num);
		if (mul == 3)
		{
			found = true;
			break;
		}
		i++;
	}
	if (!found)
	{
		fout << "Case #" << testCase << ": "<<"NO"<<endl;
		return;
	}
	fout << "Case #" << testCase << ": "<<"YES"<<endl;
	return;





}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();
		if (testCase == 1+TestCases/20) {
			cout<<"5%"<<endl;
		} else if (testCase == 1+TestCases/4) {
			cout<<"25%"<<endl;
		} else if (testCase == 1+2*TestCases/4) {
			cout<<"50%"<<endl;
		} else if (testCase == 1+3*TestCases/4) {
			cout<<"75%"<<endl;
		}

	}

	cout<<"100%"<<endl;
	cout<<"finished"<<endl;
	getchar();

}



