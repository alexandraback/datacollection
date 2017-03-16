/*
ID: zhangxu17
PROG: test
LANG: C++                 
*/
#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <queue>
#include <stack>
#include <string> 
#include <string.h> 
#include <fstream> 
#include <map> 
#include <iomanip> 
#include <cstdio> 
#include <cstdlib>
#include <cmath>
#include <deque>
#include <list>
#include <set>

using namespace std; 

const int MAX = 0x7FFFFFFF; 
const int MIN = 0x80000000;

long long gcd(long long p, long long q) ; 
bool check(long long n) ; 

int main()
{
	ifstream fin("A-small-attempt0.in") ; 
	ofstream fout("result.out") ; 
	int testcase ; 
	fin >> testcase ; 
	long long p, q, sum = 1, res ;
	char c ; 
	long long value[64] ; 
	for(int i = 0; i < 41; i++)
	{
		value[i] = sum ;
		sum *= 2 ; 
	}
	for(int t = 1; t <= testcase; t++)
	{
		res = MAX ; 
		fin >> p >> c >> q ; 
		long long num = gcd(p, q) ; 
		p = p / num ; 
		q = q / num ; 
		if(check(q))
		{
			for(int i = 1; i < 41; i++)
			{
				long long r = q / value[i] ; 
				if(r <= p)
				{
					res = i ; 
					break ; 
				}
			}
		}
		if(res == MAX)
			fout << "Case #" << t << ": " << "impossible" << endl ;
		else
			fout << "Case #" << t << ": " << res << endl ;
	}
	fin.close() ;
	fout.close() ; 
	return 0 ; 
}

bool check(long long n)
{
	while(n != 1)
	{
		if(n % 2 == 1)
			return false ; 
		n = n / 2 ; 
	}
	return true ; 
}

long long gcd(long long p, long long q)
{
	long long temp ; 
	temp = p%q ; 
	while(temp != 0)
	{
		p = q;
		q = temp ; 
		temp = p%q ; 
	}
	return q ; 
}