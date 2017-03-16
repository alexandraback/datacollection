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
#define maxh 3000

using namespace std;

vector< VI > x;
int heights[maxh];

int main()
	{
	int T,N;
	ifstream fcin("in.txt",ios::in);
	FILE* fout;
	fout = fopen("out.txt","w");
	fcin >> T;
	FOR(tc,0,T)
		{
		fcin >> N;
		x.resize(0);
		x.resize(2*N-1);
		FOR(i,0,maxh) heights[i] = 0; 
		FOR(i,0,2*N-1)
			{
			x[i].resize(N);
			FOR(j,0,N)
				{
				fcin >> x[i][j];
				++heights[x[i][j]];
				}
			}
		VI stack;
		FOR(i,0,maxh)
			if( heights[i]%2 == 1 )
				stack.push_back(i);
		
		fprintf(fout,"Case #%d:",tc+1);
		FOR(i,0,N)
			fprintf(fout," %d",stack[i]);
		fprintf(fout,"\n");
		}
	fcin.close();
	return 0;
	}
