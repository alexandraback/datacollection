#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "A-large.in"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

int n;
vector < vector<int> > g;
vector<char> cl;
/*
bool dfs (int v,int prev) {
	cl[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
    if (prev==to)
      continue;
		if (cl[to] == 0 ) {
			//p[to] = v;
			if (dfs (to,v))  
        return true;
		}
		else if (cl[to] == 1) {
			return true;
		}
	}
	cl[v] = 2;
	return false;
}*/
bool dfs (int v,int prev) {
	cl[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (cl[to] == 0 ) {
			if (dfs (to,v))  
        return true;
		}
		else if (cl[to] == 1) {
			return true;
		}
	}
	//cl[v] = 2;
	return false;
}


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
    g.clear();
    cin>>n;
    g.resize(n,vector<int>());
    cl.clear();
    cl.resize(n,0);
    rp(i,n) {
      int m; cin>>m;
      int x,y; 
      x=i;
      rp(j,m) { 
        cin>>y;--y;
        g[i].pb(y);
        //g[y].pb(x);
      }
    }
    bool flag=false;
	  for (int i=0; i<n; ++i) {
      cl.clear();
      cl.resize(n,0);
		  if (dfs (i,-10)) {
        flag=true;
			  break;
      }
    }
    if (!flag)
		  printf("Case #%d: No\n",tst);
    else
      printf("Case #%d: Yes\n",tst);
		//printf("Case #%d: ",tst);
	}
	
	return 0;
}