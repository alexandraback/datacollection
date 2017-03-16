#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <set>

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define FORC(it,cont) for(__typeof(cont.begin()) it=(cont).begin(); it!=(cont).end();++(it))
#define VI vector<int>
#define VS vector<string>

using namespace std;

int getmask(long long n)
	{
	int mask = 0;
	if (n == 0) return 1;
	while( n )
		{
		mask |= (1 << (n%10));
		n/=10;
		}
	return mask;
	}

int main()
	{
	int T,N;
	ifstream fcin("in.txt",ios::in);
	FILE* fout;
	fout = fopen("out.txt","w");
	fcin >> T;
	FOR(tc,0,T)
		{
		int res = 0;
		fcin >> N;
		
		if (N==0)
			{
			fprintf(fout,"Case #%d: INSOMNIA\n",tc+1);
			continue;
			}
		
		int mask = 0;
		
		long long n = N;
		for(;;n+=N)
			{
			int nmask = getmask(n);
			mask |= nmask;
			if ( mask == (1 << 10) -1 )
				break;
			}
		
		fprintf(fout,"Case #%d: %lld\n",tc+1,n);
		}
	fcin.close();
	return 0;
	}
