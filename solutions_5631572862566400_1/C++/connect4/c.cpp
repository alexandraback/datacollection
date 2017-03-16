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


int main(int argc, char** argv)
{

string fName = argv[1];
fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;


for(int h=0; h<tests; h++)
{
	int N;

	In >> N;

	vector<int> nextKid(N+1, 0);

	for(int i=1; i<=N; i++)
		In >> nextKid[i];

	vector<int> pairedEnds(N+1, 0);
	vector<int> pairedDepth(N+1, 0);

	for(int i=1; i <= N; i++)
		if(nextKid[nextKid[i]]==i)
			pairedEnds[i] = pairedEnds[nextKid[i]] = 1;
	int ret = 0;

	for(int i=1; i<=N; i++)
	{
		if(pairedEnds[i])
			continue;
		int depth = 0;
		vector<bool> visited(N+1, false);
		int cur = i;
		do
		{
			visited[cur] = true;
			depth++;
			cur = nextKid[cur];
		}while(!visited[cur] && !pairedEnds[cur]);
		if(cur==i)
			ret = max(ret, depth);
		else if(pairedEnds[cur])
			pairedDepth[cur] = max(pairedDepth[cur], depth);
	}

	int depthCheck = 0;
	for(int i=1; i<=N; i++)
		depthCheck += pairedDepth[i] + pairedEnds[i];
	ret = max(ret, depthCheck);
	Out << "Case #" << h+1 << ": " << ret << endl;


}

In.close();

Out.close();

return 0;

}
 
