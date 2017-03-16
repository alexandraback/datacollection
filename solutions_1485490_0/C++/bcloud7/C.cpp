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

int N,M;

long long box[108];
long long numb[108];
long long toy[108];
long long numt[108];

long long res[108][108];

long long compute(int i,int j)
{
	if(res[i][j]>=0) return res[i][j];
	long long &r = res[i][j];
	r = 0;
	if(i>=N || j>=M) return r;
	r = max(compute(i+1,j), compute(i,j+1));

	long long rr = 0;


	if(box[i] == toy[j])
	{
		vector<pair<long long, int> > b;
		vector<pair<long long, int> > t;
		for(int p=i; p<N;p++)
		{
			if(box[p] == box[i])
				b.push_back(make_pair(numb[p],p));

		}
		for(int q=j;q<M;q++)
		{
			if(toy[q] == toy[j])
				t.push_back(make_pair(numt[q],q));
		}

		long long sumb = 0;
		for(int p=0;p<(int)b.size();p++)
		{
			sumb += b[p].first;
			long long sumt = 0;
			for(int q=0;q<(int)t.size();q++)
			{
				sumt += t[q].first;
				rr = max(rr, min(sumb,sumt) + compute(b[p].second +1, t[q].second+1));
			}
		}
		r = max(r,rr);

	}
	return r;



}
int main()
{
	int T;
	fin>>T;

	for(int c=1;c<=T;c++)
	{	
		fin>>N>>M;
		for(int i=0;i<N;i++)
		{
			fin>>numb[i]>>box[i];
		}
		for(int i=0;i<M;i++)
			fin>>numt[i]>>toy[i];

		for(int i=0;i<108;i++)
			for(int j=0;j<108;j++)
				res[i][j] = -1;



		long long res = compute(0,0);



		cout<<"Case #"<<c<<": "<<res<<endl;
		fout<<"Case #"<<c<<": "<<res<<endl;
		
	}
	return 0;
}
