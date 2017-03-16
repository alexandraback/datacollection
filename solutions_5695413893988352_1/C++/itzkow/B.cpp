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
#include <iomanip>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define FOR(i,s,e) for (int i = s; i <= e; i++)
#define FORR(i,e,s) for (int i = e; i >= s; i--)
#define ZERO(ARR) memset(ARR,0,sizeof(ARR));


ifstream fin ("B-large.in");
ofstream fout ("B-large.out");

int testCase = 0;

/*

who are you stop looking i dont like you

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

char C[20];
char J[20];

LL BJ;
LL BC;
int N;

LL pow(int k)
{
	LL s = 1;
	FOR(i, 0, k-1)
		s*=10;
	return s;
}

void best(LL CC, LL JJ)
{
	if (abs(JJ-CC) < abs(BJ-BC))
	{
		BJ=JJ;
		BC=CC;
	}
	else if (abs(JJ-CC) == abs(BJ-BC))
	{
		if (CC < BC || (CC == BC && JJ<BJ))
		{
			BJ=JJ;
			BC=CC;
		}
	}
}

LL num(char c,int i)
{
	return (c-'0')*pow(N-1-i);
}

void Solve()
{

	fin>>C;
	fin>>J;

	N=strlen(J);
	
	BJ=0;
	BC=9999999999999999999;
	
	LL CN = 0;
	LL JN = 0;
	LL CNT = 0;
	LL JNT = 0;
	FOR(i,0,N-1)
	{
		if (C[i] == '?' && J[i] == '?')
		{
			CNT = CN;
			JNT = JN;
			CNT += num('1',i);
			JNT += num('0',i);
			FOR(j,i+1,N-1)
			{
				if (C[j] == '?')
					CNT += num('0',j);
				else
					CNT += num(C[j],j);

				if (J[j] == '?')
					JNT += num('9',j);
				else
					JNT += num(J[j],j);
			}
			best(CNT,JNT);


			
			CNT = CN;
			JNT = JN;
			CNT += num('0',i);
			JNT += num('1',i);
			FOR(j,i+1,N-1)
			{
				if (C[j] == '?')
					CNT += num('9',j);
				else
					CNT += num(C[j],j);

				if (J[j] == '?')
					JNT += num('0',j);
				else
					JNT += num(J[j],j);
			}
			best(CNT,JNT);
			C[i]='0';
			J[i]='0';
		}
		else if (C[i] == '?' && J[i] != '?')
		{
			if (J[i] > '0')
			{
				CNT = CN;
				JNT = JN;
				CNT += num(J[i]-1,i);
				JNT += num(J[i],i);
				FOR(j,i+1,N-1)
				{
					if (C[j] == '?')
						CNT += num('9',j);
					else
						CNT += num(C[j],j);

					if (J[j] == '?')
						JNT += num('0',j);
					else
						JNT += num(J[j],j);
				}
				best(CNT,JNT);
			}
			if (J[i] < '9')
			{
				CNT = CN;
				JNT = JN;
				CNT += num(J[i]+1,i);
				JNT += num(J[i],i);
				FOR(j,i+1,N-1)
				{
					if (C[j] == '?')
						CNT += num('0',j);
					else
						CNT += num(C[j],j);

					if (J[j] == '?')
						JNT += num('9',j);
					else
						JNT += num(J[j],j);
				}
				best(CNT,JNT);
			}
			C[i] = J[i];			
		}
		else if (C[i] != '?' && J[i] == '?')
		{
			if (C[i] > '0')
			{
				CNT = CN;
				JNT = JN;
				CNT += num(C[i],i);
				JNT += num(C[i]-1,i);
				FOR(j,i+1,N-1)
				{
					if (C[j] == '?')
						CNT += num('0',j);
					else
						CNT += num(C[j],j);

					if (J[j] == '?')
						JNT += num('9',j);
					else
						JNT += num(J[j],j);
				}
				best(CNT,JNT);
			}
			if (C[i] < '9')
			{
				CNT = CN;
				JNT = JN;
				CNT += num(C[i],i);
				JNT += num(C[i]+1,i);
				FOR(j,i+1,N-1)
				{
					if (C[j] == '?')
						CNT += num('9',j);
					else
						CNT += num(C[j],j);

					if (J[j] == '?')
						JNT += num('0',j);
					else
						JNT += num(J[j],j);
				}
				best(CNT,JNT);
			}
			J[i] = C[i];			
		}
		else if (C[i] < J[i])
		{
			CNT = CN;
			JNT = JN;
			FOR(j,i,N-1)
			{
				if (C[j] == '?')
					CNT += num('9',j);
				else
					CNT += num(C[j],j);

				if (J[j] == '?')
					JNT += num('0',j);
				else
					JNT += num(J[j],j);
			}
			best(CNT,JNT);
			break;
		}
		else if (C[i] > J[i])
		{
			CNT = CN;
			JNT = JN;
			FOR(j,i,N-1)
			{
				if (C[j] == '?')
					CNT += num('0',j);
				else
					CNT += num(C[j],j);

				if (J[j] == '?')
					JNT += num('9',j);
				else
					JNT += num(J[j],j);
			}
			best(CNT,JNT);
			break;
		}
		CN += num(C[i],i);
		JN += num(J[i],i);
	}

	CN=JN=0;
	FOR(i,0,N-1)
	{
		if (C[i] == '?')
			CN += num('0',i);
		else
			CN += num(C[i],i);

		if (J[i] == '?')
			JN += num('0',i);
		else
			JN += num(J[i],i);
	}
	best(CN,JN);


	
	fout << "Case #" << testCase << ": ";
	fout<<setfill('0')<<setw(N)<<BC;
	fout<<" ";
	fout<<setfill('0')<<setw(N)<<BJ;
	fout<<endl;

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



