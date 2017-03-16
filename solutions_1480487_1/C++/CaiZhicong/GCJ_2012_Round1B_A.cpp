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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;

const double PI = acos(-1.0);
#define FOR(a,b) for(int i = a; i< b; ++i)
#define SORT(a,b) sort(a.begin(),a.end(),b)
#define MEMS(a,b) memset(a,b,sizeof(a))
template<class T>
inline T gcd(T a , T b) { if(a == 0 || b == 0 || a == b) return max(a,b); return a>b?gcd(a%b,b) : gcd(a,b%a);}
string intToStr(int n) { char p[15];sprintf(p,"%d",n);return string(p);}
int strToInt(string s) { istringstream sin(s); int r; sin >> r; return r;} 

bool chk(double v, vector<int> s, int in,int sum)
{
	double rv = 1.0 - v;
	double score = s[in] + sum*v;
	double nd = 0.0;
	for(int i = 0; i< s.size(); ++i)
	{
		if(i != in)
		{
			if(s[i] <= score+(10e-11))
			{
				double p = score-s[i];
				nd += p/sum;
			}
		}
	}
	if(nd <= rv-10e-11) return false;
	else return true;
}

int main()
{
	int T, A, B;
	cin >> T;
	for(int t = 1; t<= T; ++t)
	{
		int N,si,sum = 0;
		cin >> N;
		vector<int> s;
		bool zero = false;
		for(int i = 0; i< N; ++i)
		{
			cin >> si;
			sum += si;
			//if(si == 0) zero = true;
			s.push_back(si);
		}
		cout << "Case #" << t << ": ";
		int au = 200;
		if(zero)
		{
			for(int i = 0; i< N; ++i)
			{
				if(s[i] != 0) cout << "0.000000 ";
				else cout << "100.000000 ";
			}
			cout << endl;
		}
		else{
			for(int i = 0; i< N; ++i)
			{
				double min = 0, max = 1.0, mid = 0;
				while(min<max)
				{
					mid = (min+max)/2;
					if(chk(mid,s,i,sum))
					{
						max = mid-10e-10;
					}
					else
					{
						min = mid+10e-10;
					}
				}
				printf("%.6lf ",100*mid);
				//cout << mid*100 << " ";
				
			}
			cout << endl;
		}
	}
	return 0;
}
