#define _cRT_SEcURE_NO_DEPREcATE
//#define long long long long

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <deque>
#include <math.h>
#include <time.h>

using namespace std;

FILE * in, * out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

int ri() { int a; fscanf(in, "%d", &a ); return a; }
double rf() 
{ 
	double a; 
	fscanf(in, "%lf", &a ); 
	return a; 
}

char * sbuf = 0; 
string rstr() 
{
	//fscanf(in, "%lf", sbuf); 
	if(sbuf == 0)
		sbuf = new char [(1<<20)+1];

	char c;
	char * b = sbuf;
	while(c = fgetc(in))
	{
		if(c == '\r' || c == '\n' || c == -1) 
		{
			if(b - sbuf > 0)
				break;
			continue;
		}
		*b++=c;
	}
	*b = 0;
	return sbuf; 
}
long long rll() { long long a; fscanf(in, "%lld", &a ); return a; }

long long readbi(int l)
{
	long long res = 0;
	int count = 0;
	int c;
	while( (c = fgetc(in)) && l != 0)
	{
		if(c == '1' || c == '0') 
		{
			res *= 2;
			if(c == '1') res |= 1;
			l--;
		}
	}
	return res;
}

int countdown(int x, int cf, vector<vector<int>> & edges)
{
	int res = 1;
	for(int i = 0; i<edges[x].size(); i++)
	{
		if(edges[x][i] == cf) continue;
		res += countdown(edges[x][i], x, edges);
	}
	return res;
}

int trynode(int x, int cf, vector<vector<int>> & edges)
{
	if(edges[x].size() == 1) return 0;
	if(edges[x].size() == 2) 
	{
		if(edges[x][0] == cf)
			return countdown(edges[x][1],x,edges);
		else
			return countdown(edges[x][0],x,edges);
	}
	
	int res = 1000000;
	for(int i = 0; i<edges[x].size(); i++)
	{
		if(edges[x][i] == cf) continue;
		for(int j = i+1; j<edges[x].size(); j++)
		{
			if(edges[x][j] == cf) continue;
			int cur = trynode(edges[x][i],x,edges)+trynode(edges[x][j],x,edges);
			for(int k = 0; k<edges[x].size(); k++)
			{
				if(edges[x][k] == cf) continue;
				if(k != i && k!=j)
					cur += countdown(edges[x][k],x,edges);
			}
			if(cur < res) res = cur;
		}
	}
	return res;
}

bool isWised(vector<int> & st, vector<vector<int>> & fl, vector<int> & zip)
{
	vector<int> v(zip.size());
	for(int k = 0; k<st.size(); k++)
		v[st[k]] = 1;

	for(int k = 0; k<zip.size(); k++)
	for(int i = 0; i<zip.size(); i++)
	{
		bool bFound = false;
		for(int j = 0; j<fl[i].size() && !bFound; j++)
			bFound = (v[fl[i][j]] == 1);
		if(!bFound) continue;
		v[i] = 1;
	}
	for(int i = 0; i<zip.size(); i++)
		if(v[i] == 0 && zip[i] != 0) return false;

	return true;
}

bool updateminzip(int f, vector<vector<int>> & fl, vector<int> & zip, int & ind, int & minz, vector<int> & path)
{
	vector<vector<int>> v(zip.size());

	v[f].push_back(f);
	bool result = false;
	for(int k = 0; k<zip.size(); k++)
	for(int i = 0; i<zip.size(); i++)
	{
		int js = -1;
		if(v[i].size() != 0) continue;

		for(int j = 0; j<fl[i].size(); j++)
		{
			if(v[fl[i][j]].size() != 0)
			{
				if(js == -1 || v[js].size() > v[fl[i][j]].size())
				{
					js = fl[i][j];
					if(js != -1 && zip[i] < minz && zip[i] != 0)
						printf("ubm\n");
				}
			}
		}
		if(js == -1) continue;

		if(zip[i] == 0)
		{
			if(v[i].size() == 0)
			{
				v[i] = v[js];
				v[i].push_back(i);
			}
		}
		else
		{
			if(zip[i] < minz) 
			{
				path = v[js];
				path.push_back(i);

				minz = zip[i];
				ind = i;
				result = true;
			}
		}
	}
	return result;
}


int main(int argc, char * argv[])
{
	in	= fopen("1.in","rt");
	out	= fopen("out.txt","wt");

	int numcases = ri();
	for(int ca = 1; ca<=numcases; ca++)
	{
		int n = ri();
		int m = ri();

		vector<int> zip(n);
		for(int i = 0; i<n; i++)
			zip[i] = ri();
		
		vector<vector<int>> fl(n);
		for(int i = 0; i<m; i++)
		{
			int f = ri();
			int t = ri();
			fl[f-1].push_back(t-1);
			fl[t-1].push_back(f-1);
		}
		
		int minz = 100000;
		int ind = 0;
		for(int i = 0; i<n; i++)
		{
			if(zip[i] < minz)
			{
				minz = zip[i];
				ind = i;
			}
		}
		fprintf(out,"Case #%d: %d", ca, minz);
		zip[ind] = 0;

		bool bDone = false;
		vector<int> stack;
		stack.push_back(ind);
		int count = 1;
		while(count < n)
		{
			int minz = 777777;
			int ind = 0;
			int sti = 0;
			vector<int> path;
			for(int i = stack.size()-1; i>=0; i--)
			{
				vector<int> cs = stack;
				cs.resize(i+1);
				if(!isWised(cs,fl,zip)) break;
				if(updateminzip(stack[i],fl,zip,ind,minz,path))
					sti = i;
			}
			stack.resize(sti+1);
			for(int i = 1; i<path.size(); i++)
			{
				stack.push_back(path[i]);
				for(int j = 0; j<fl[path[i-1]].size(); j++)
					if(fl[path[i-1]][j] == path[i]) 
						fl[path[i-1]].erase(fl[path[i-1]].begin()+j);
				for(int j = 0; j<fl[path[i]].size(); j++)
					if(fl[path[i]][j] == path[i-1]) 
						fl[path[i]].erase(fl[path[i]].begin()+j);
			}
			zip[ind] = 0;
			fprintf(out,"%d",minz);
			count++;
		}
		fprintf(out,"\n",minz);
	}
	return 0;
}

