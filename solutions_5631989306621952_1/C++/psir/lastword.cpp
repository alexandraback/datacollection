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
		string s;
		fcin >> s;
		N = s.size();
		
		string sol;
		sol += s[0];
		FOR(i,1,N)
			if( sol[0] <= s[i])
				sol = s[i] + sol;
			else
				sol += s[i];
		
		fprintf(fout,"Case #%d: %s\n",tc+1,sol.c_str());
		}
	fcin.close();
	return 0;
	}
