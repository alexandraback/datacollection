#include "p3.h"
#include <iostream>
#include <fstream>
using namespace std;

p3::p3(void)
{
}


p3::~p3(void)
{
}

int cnt[3000000];

void p3::solve()
{
	ifstream fin("C-large.in");
	ofstream fout("C-large.out");
	int t; fin>>t;
	int mask = 0;
	for ( int tests=1; tests<=t; ++tests )
	{
		int a, b;
		fin >> a >> b;
		int p=0, t=a;
		int bases2=1;
		while (t) ++p, t=t/10, bases2=bases2*10;
		bases2/=10;
		int res=0;		
		for ( int i=a; i<=b; ++i )
		{
			++mask;
			for ( int s=1, base=10, base2=bases2; s<p; ++s, base*=10, base2/=10 )
			{
				int tmp = i/base + base2*(i%base);
				//cerr << i << " " << tmp << endl;
				
				if ( a<=tmp && tmp<=b && i<tmp && cnt[tmp]<mask)
				{
					cnt[tmp]=mask;
					//cerr << i << " " << tmp << endl;
					++res;
				}
			}
		}
		fout << "Case #" << tests << ": " << res << endl;
	}
}