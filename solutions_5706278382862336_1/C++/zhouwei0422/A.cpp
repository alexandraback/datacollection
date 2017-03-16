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

int T,cases;

long long P, Q;

long long gcd(long long a,long long b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}


void solve()
{
	char c;
	ifile>>P>>c>>Q;
	
	long long g = gcd(P,Q);
	P/=g;
	Q/=g;

	set<long long> s;
	long long d2 = 1;
	s.insert(d2);
	for(int i = 0; i < 50; i++)
	{
		d2*=2;
		s.insert(d2);
	}
	if(s.find(Q)==s.end())
		ofile<<"Case #"<<cases<<": "<<"impossible"<<endl;
	else
	{
		long long res = 0;
		while(Q>P)
		{
			P*=2;
			res++;
		}
		ofile<<"Case #"<<cases<<": "<<res<<endl;
	}


}

int main(void)
{
	ifile.open("input.txt");
	ofile.open("output.txt");

	ifile>>T;
	for(int i = 0; i < T; i++)
	{
		cases=i+1;
		solve();
	}

	ifile.close();
	ofile.close();
	return 0;
}