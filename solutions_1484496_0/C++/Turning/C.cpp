#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>

using namespace std;
#define PI 3.14159265358979323846264338327950288
#define fill_(x,v) memset(x,v,sizeof(x))
#define for_(i,a,b) for (__typeof(b) i=(a); i<(b); i++)
#define min(x,y) (((x)>(y)) ? (y) :(x))
#define max(x,y) (((y)>(x)) ? (y) :(x))

ifstream fin("c:\\1B\\C-small-attempt0.in");
ofstream fout("c:\\1B\\C.out");

void output(vector<int>& d, int i )
{
		int t = i;
		int p = 0;
		while ( t )
		{
			if ( t % 2 == 1 ) fout<<d[p]<<' ';
			t /= 2;
			p++;
		}
		fout<<endl;
	
}
void run()
{
	int N;
	fin >> N;
	vector<int> d;
	for ( int i = 0; i < N; i++)
	{
		int tmp;
		fin >> tmp;
		d.push_back(tmp);
		
	}
	
	vector<pair<int, int> > sum;
	for ( int i = 0; i < (1<<N); i++)
	{
		int t = i;
		int p = 0;
		int s = 0;
		while ( t )
		{
			if ( t % 2 == 1 ) s += d[p];
			t /= 2;
			p++;
		}
		sum.push_back(make_pair(s,i));
	}
	
	sort(sum.begin(), sum.end());
	for ( int i = 0; i < sum.size() - 1; i++)
	if ( sum[i].first == sum[i+1].first &&
		 (sum[i].second & sum[i+1].second) == 0 )
	{
		output(d,sum[i].second);
		output(d,sum[i+1].second);
		break;
	}
}
int main() {
  
	int N;
	fin>> N;
	for( int n = 1; n <= N; n++)
	{
		//printf("Case #%d: %d\n", n, ret);
		fout<<"Case #"<<n<<": "<<endl;
		 run();
		
		//fout << fixed;
		//fout<<"Case #"<<n<<": "<<setprecision(10)<<ret<<endl;
   }
   return 0;
}