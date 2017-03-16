#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <assert.h>
#include <math.h>
using namespace std;

const string file = "file";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f; 
const int MODN = 666013;
const double EPS = 0.0000001;

//#define ONLINE_JUDGE

int N, M;
string Sol;
vector<string> zips;
vector<vector<int> > G;



struct State
{
	int vizited;
	vector<bool> viz;
	stack<int> posses;
	string cSol;
};

vector<int> X;

void bkt(State state)
{
	if(state.vizited == N)
	{
		if(state.cSol < Sol || Sol == "")
		{
			Sol = state.cSol;
		}
	}
	else
	{
		while(state.posses.empty() == false)
		{
			int pos = state.posses.top();
			
			for(vector<int>::iterator itr = G[pos].begin();
				itr != G[pos].end();
				itr++)
			{
				if(state.viz[*itr] == false)
				{
					string prevCsol = state.cSol;

					state.viz[*itr] = true;
					state.vizited ++;
					state.cSol.append(zips[*itr]);
					state.posses.push(*itr);

					bkt(state);

					state.posses.pop();
					state.viz[*itr] = false;
					state.vizited --;
					state.cSol = prevCsol;
				}
			}
			state.posses.pop();
		}
	}
}

int main()
{
#ifdef ONLINE_JUDGE
	ostream &fout = cout;
	istream &fin = cin;
#else
	fstream fin(infile.c_str(), ios::in | ios::binary);
	fstream fout(outfile.c_str(), ios::out);
#endif	
	

	int T;
	fin >> T;
	for(int t = 1; t <= T; t++)
	{
	
	
		fin >> N >> M;
		Sol = "";
		
		zips.clear();
		zips.resize(N + 1);

		G.clear();
		G.resize(N + 1);

		for(int i = 1; i <= N; i++)
		{
			fin >> zips[i];
		}

		
		
		for(int i = 0; i < M; i++)
		{
			int x, y;
			fin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
	

		for(int i = 1; i <= N; i++)
		{
			State state;
			
			state.cSol.append(zips[i]);
			state.vizited = 1;
			state.viz.resize(N + 1);
			state.viz[i] = true;
			state.posses.push(i);

			bkt(state);
		}

		fout << "Case #" << t <<": ";
		fout << Sol;
		fout << "\n";
		
	}


#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
