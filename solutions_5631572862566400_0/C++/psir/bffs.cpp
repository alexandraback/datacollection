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
#define maxN 2000
using namespace std;

vector< VI > adj;
vector< VI > dabl;
int visited[maxN];
int visited2[maxN];
VI cycle;
set<int> S;
			

void extract_cycle(int pos, int last)
	{
	//cout << pos << " " << last << endl;
	cycle.push_back(pos);
	if( pos == last )
		return;
	extract_cycle(visited[pos],last);
	return;
	}

void dfs(int pos)
	{
	//cout << pos << endl; 
	//system("pause");
	FOR(j,0,adj[pos].size())
		{
		int pnew = adj[pos][j];
		if (visited[pos] ==  pnew )
			continue;
		if( visited[pnew] == -5 )
			{
			visited[adj[pos][j]] = pos;
			dfs(adj[pos][j]);
			}	
		else if(cycle.size() == 0)
			{
			extract_cycle(pos,pnew);
			}
		
		}
	//cout << pos << endl; 
	//system("pause");
	
	FOR(j,0,dabl[pos].size())
		{
		int pnew = dabl[pos][j];
		if( visited[pnew]!= -5 && cycle.size() == 0)
			{
			extract_cycle(pos,pnew);
			}
		}

	return;
	}

int dfs2(int pos,int parent)
	{
	int sol = 0;
	FOR(i,0,adj[pos].size())
		{
		int pnew = adj[pos][i];
		if(S.count(pnew) == 0 && pnew != parent )
			sol = max(sol, 1 + dfs2(pnew,pos));
		}
	return sol;
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
	//cout << "test " << tc << endl;
	//	system("pause");
		fcin >> N;
		VI x(N);
		FOR(i,0,N)
			{fcin >> x[i]; --x[i];}
		adj.resize(0);
		adj.resize(N);
		dabl.resize(0);
		dabl.resize(N);
		
		FOR(i,0,N)
			{
			if( x[i] < i && x[x[i]] == i )
				{
				dabl[i].push_back(x[i]);
				dabl[x[i]].push_back(i);
				}
			else
				{
				adj[i].push_back(x[i]);
				adj[x[i]].push_back(i);
				}
			}
		
		FOR(i,0,N)
			{
			visited[i] = -5;
			visited2[i] = -5;
			}
		VI CL;
		VI TS;
		
		FOR(i,0,N)
			if( visited[i] == -5 )
			{
//			cout << "start at " << i << " of " << N << endl;
			cycle.resize(0);
			visited[i] = -1;
			dfs(i);
			int csize = cycle.size();
			if (csize > 2 )
				{
				CL.push_back(csize);
				TS.push_back(csize);
				continue;
				}
			S.clear();
			FOR(j,0,cycle.size())
				S.insert(cycle[j]);
			VI maxdepth(cycle.size());
			FOR(j,0,cycle.size())
				maxdepth[j] = dfs2(cycle[j],cycle[j]);
			sort(maxdepth.begin(),maxdepth.end());
			int depth = maxdepth[csize-1] + maxdepth[csize -2];
			CL.push_back(csize);
			TS.push_back(csize + depth);
			}
		
		int maxC = 0;
		int TS2 = 0;
		FOR(i,0,CL.size())
			{
			maxC = max(maxC,CL[i]);
			if( CL[i] == 2 )
				TS2 += TS[i];
			}
		int res = max(maxC,TS2);
		
		fprintf(fout,"Case #%d: %d\n",tc+1,res);
		}
	fcin.close();
	return 0;
	}
