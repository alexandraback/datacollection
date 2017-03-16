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

int main()
{
	
	fin>>T;
	int N;
	
	for(int c=1;c<=T;c++)
	{
		fin>>N;
		vector<int> score;
		int sum = 0;
		for(int i=0;i<N;i++)
		{
			int tmp;
			fin>>tmp;
			sum += tmp;
			score.push_back(tmp);
		}
		double high = (sum*2.0)/N;
		double low = 0.0;
		double m;
		while(low<high-eps)
		{
			m = (high+low)/2.0;
			double need = 0.0;

			for(int i=0;i<N;i++)
				if(score[i]<m)
				{
					need += m-score[i];
				}
			if(need > sum+eps)
			{
				high = m;
			}
			else if(need < sum-eps)
			{
				low = m;

			}
			else
				break;
		}





		fout.setf(ios::fixed,ios::floatfield);	 

		
	
		cout<<"Case #"<<c<<":";
		fout<<"Case #"<<c<<":";
		
		for(int i=0;i<N;i++)
		{
			if(m>score[i])
			{

				cout<<" "<<setprecision(7)<<(m-score[i])*100.0/sum;
				fout<<" "<<setprecision(7)<<(m-score[i])*100.0/sum;
			}
			else
			{
				cout<<" 0.000000";
				fout<<" 0.000000";
			}
		}
		cout<<endl;
		fout<<endl;
		
	}
	return 0;
}
