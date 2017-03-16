#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>
#include <limits>
#include <eigen3/Eigen/Dense>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,m,n) for (int i=m; i<int(n); i++)
#define ForR(i,m,n) for (int i=int(n)-1; i>=m; i--)

#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const LL INF = numeric_limits<LL>::max();
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0
#define LIM 1000

ifstream input;
ofstream output;
int numTest;
int test;

string vowellist = "aeiou";

bool vowel(char c){
	For(i,0,vowellist.length())
			if(vowellist[i]==c)
				return true;
	return false;
}

long long nValue(string s, long long n, long long c){
	long long len = s.length();
	long long cnt = 0;

	long long p = -1;
	long long result = 0;
	For(i, c, len){
		if(!vowel(s[i])){
			if(p == -1)
				p = i;
			if(i == len-1){
				long long d = i -p;
				if(d<n-1){
					p =-1;
				}
				else{
					result = (len-p-n)*(len-p-n+1)/2+(len-p-n+1)*(p-c+1);
					break;
				}
			}
		}
		else if(p!=-1){
			long long d = i -p;
			if(d<n){
				p =-1;
			}
			else{
				result= nValue(s, n, i-n+1) + (i-p-n)*(i-p-n+1)/2+(i-p-n)*(p-c) +(i-n-c+1)*(len-i+1);
				break;
			}
		}
	}

	return result;
}

int main(int argc, char**argv)
{
	clock_t start = clock();
	input.open(argc>1 ? argv[1]: "a1.in");
	output.open(argc>2 ? argv[2]: "a1.out");

	input >> numTest;
	//numTest = 1;
	For(test,1,numTest+1){
		string str;
		long long n;
		long long L;

		input >> str >> n;
		long long result = nValue(str,n, 0);

		output << "Case #" << test <<": ";
		output << result << endl;
	}

	cout << "Time: " << (clock()-(double)start)/(double)CLOCKS_PER_SEC << endl;

	return 0;

}
