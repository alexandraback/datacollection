#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
#include <queue>
using namespace std;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define in(x,s) (s.find(x)!=s.end())

typedef long long int64;
typedef vector<int> VI;
typedef vector<string> VS;

const double eps = 1E-12;
const double pi=acos(-1.0); 


ifstream fin("a.in");
ofstream fout("a.out");

int T;
int A,B;
int main()
{
	
	fin>>T;
	
	
	for(int c=1;c<=T;c++)
	{
		fin>>A>>B;
		double res = (double)(B+2);

		double good = 1.0;
		double tmp;
		for(int i=0;i<A;i++)
		{
			fin>>tmp;
			good *= tmp;
			double r = (A-i-1)+(B-i)+ (1.0-good)*(1+B);
			res = min(r,res);



		}


		fout.setf(ios::fixed,ios::floatfield);	 


	
		cout<<"Case #"<<c<<": "<<res<<endl;
		fout<<"Case #"<<c<<": "<<setprecision(7)<<res<<endl;
		
	}
	return 0;
}
