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


ifstream fin("c.in");
ofstream fout("c.out");

int T;


int main()
{
	
	fin>>T;
	int N;
	
	for(int c=1;c<=T;c++)
	{
		fin>>N;
		vector<int> num;
		for(int i=0;i<N;i++)
		{
			int tmp;
			fin>>tmp;
			num.push_back(tmp);
		}

		map<int,int> mp;
		int good = false;
		int a;
		int b;
		for(int i=1;i<(1<<20);i++)
		{
			int s = 0;
			for(int j=0;j<20;j++)
			{
				if(i & (1<<j))
					s += num[j];
			}
			if(mp.find(s) != mp.end())
			{
				good = true;
				a = i;
				b = mp[s];
				break;
			}
			else
			{
				mp[s] = i;
			}

		}

		
	
		cout<<"Case #"<<c<<":"<<endl;
		fout<<"Case #"<<c<<":"<<endl;

		if(!good)
		{
			cout<<"Impossible"<<endl;
			fout<<"Impossible"<<endl;
		}
		else
		{
			int c = a&b;
			a = a-c;
			b = b-c;
			vector<int> A;
			vector<int> B;
			for(int i=0;i<20;i++)
			{
				if(a & (1<<i))
					A.push_back(num[i]);
				if(b & (1<<i))
					B.push_back(num[i]);
			}
			for(int i=0;i<(int)A.size()-1;i++)
			{
				cout<<A[i]<<" ";
				fout<<A[i]<<" ";

			}
			cout<<A[(int)A.size()-1]<<endl;
			fout<<A[(int)A.size()-1]<<endl;

			for(int i=0;i<(int)B.size()-1;i++)
			{
				cout<<B[i]<<" ";
				fout<<B[i]<<" ";

			}
			cout<<B[(int)B.size()-1]<<endl;
			fout<<B[(int)B.size()-1]<<endl;

		}
		
	}
	return 0;
}
