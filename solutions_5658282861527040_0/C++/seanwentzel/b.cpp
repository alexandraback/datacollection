#include<fstream>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<iostream>
#include<cassert>
#include<cmath>

#define f(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define x first
#define y second
#define mp make_pair
#define pb push_back


using namespace std;

int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B.out");
	int cases;
	fin>>cases;
	for(int cas=1;cas<=cases;++cas)
	{
		fout<<"Case #"<<cas<<": ";
		int a,b,k;
		fin>>a>>b>>k;
		int res=0;
		f(i,0,a)
		{
			f(j,0,b)
			{
				if((i&j)<k) 
				{++res;
					//cerr<<i<<j<<(i&j);
				}
			}
		}
		fout<<res;

		fout<<'\n';
	}
	return 0;
}
