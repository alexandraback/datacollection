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
		int K,C,S;
		fcin >> K >> C >> S;
		
		vector< long long > sol;
		if ( S*C >= K ) res = 1;
		if (res == 1)
		{
		//cout << "tc " << tc << endl;
		VI x;
		int m = (K+C-1)/C;
		FOR(i,0,m*C) x.push_back(i);
		FOR(i,0,x.size()) if (x[i] >= K) x[i] = K-1;
		
		FOR(i,0,m)
			{
			//cout << i << endl;
			long long pos = 0;
			long long fac = 1;
			for( int j = i*C + C-1; j >= i*C; --j)
				{
				pos += fac*x[j];
				fac*= K;
				//cout << pos << " " << fac << endl;
				}
			sol.push_back(pos+1);
			}
		}
		if (res == 0 ) 
			fprintf(fout,"Case #%d: IMPOSSIBLE\n",tc+1);
		else
			{
			fprintf(fout,"Case #%d:",tc+1);
			FOR(i,0,sol.size())
				fprintf(fout," %lld",sol[i]);
			fprintf(fout,"\n");
			}
		}
	fcin.close();
	return 0;
	}
