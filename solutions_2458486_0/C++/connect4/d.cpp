#include <string.h>       
#include <vector>       
#include <set>       
#include <map>       
#include <algorithm>       
#include <math.h>       
#include <sstream>       
#include <ctype.h>       
#include <queue>       
#include <stack>       
#include <iostream> 
#include <gmp.h>	// if GMP is not allowed, I apologize
#include <fstream>
using namespace std;

int N, K;

int table[2000000];

vector<int> keys;
vector<int> doors;
vector<vector<int> > treasure;

vector<int> ret;
int doit(int mask, int cur=0)
{
	if(cur==N)
		return 1;

	if(table[mask])
		return 0;

	table[mask] = 1;

	for(int i=0; i<N; i++)
		if(((1<<i) & mask)==0)
			if(keys[doors[i]])
			{
				keys[doors[i]]--;
				for(int j=0; j<treasure[i].size(); j++)
					keys[treasure[i][j]]++;
				ret[cur] = i+1;
				if(doit(mask | (1<<i), cur+1) )
					return 1;

				keys[doors[i]]++;
				for(int j=0; j<treasure[i].size(); j++)
					keys[treasure[i][j]]--;
			}
	return 0;
}

int main(int argc, char** argv)
{


string fName = argv[1];
fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;

for(int h=0; h<tests; h++)
{
	In >> K >> N;
	keys = vector<int>(201, 0);
	doors = vector<int>(N, 0);
	ret = vector<int>(N, -1);
	memset(table, 0, sizeof(table));
	treasure = vector<vector<int> >(N, vector<int>(0));
	for(int i=0; i<K; i++)
	{
		int t;
		In >> t;
		keys[t]++;
	}

	for(int i=0; i<N; i++)
	{
		In >> doors[i];
		int t1, t2;
		In >> t1;
		for(int j=0; j<t1; j++)
		{
			In >> t2;
			treasure[i].push_back(t2);
		}
	}

	doit(0);
	string s;
	if(ret[N-1]==-1)
		s = "IMPOSSIBLE";
	else
	{
		stringstream s1;
		for(int i=0; i<ret.size(); i++)
			s1 << ret[i] << (i+1==ret.size() ? "" : " ");
		s = s1.str();
	}
	Out << "Case #" << h+1 << ": " << s << endl;

}

In.close();

Out.close();

return 0;

}
 
