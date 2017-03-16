#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

int n,m;
vector<int> cs,visited;
char edge[60][60];

void go(int start,const vector<int> &r,int &ri) {
	//printf("dfs start=%d ri=%d r.size()=%d\n",start,ri,r.size());
	//rep(i,n) cout << r[i] << " "; cout << endl;
	ri++;
	
	//printf("o\n");
	if(ri>=r.size()) return;
	
	//printf("o\n");
	
	visited[start] = 1;
	
	for(;;) {
		int min_i = -1;
		if(ri>=r.size()) return;
		if(edge[start][r[ri]]==1 && visited[r[ri]]==0) {
			min_i = r[ri];
		}
		if(min_i<0) break;
		go(min_i,r,ri);
	}
}

void runCase()
{
	
	scanf("%d %d",&n,&m);
	cs.assign(n,0);
	
	rep(i,n) scanf("%d",&cs[i]);
	rep(i,n) rep(j,n) edge[i][j] = 0;
	rep(i,m) {
		int x,y; scanf("%d %d",&x,&y);
		x--; y--; edge[x][y] = 1; edge[y][x] = 1;
	}
	
	vector<int> res,t(n);
	rep(i,n) t[i] = i;
	for(;;) {
		visited.assign(n,0);
		int ti = 0;
		go(t[0],t,ti);
		//printf("ti = %d\n",ti);
		if( ti==n ) {
			if(res.size()==0) res = t; 
			else {
				bool f = false;
				rep(j,n) {
					if(cs[t[j]] > cs[res[j]]) {f = false;break;}
					else if(cs[t[j]] < cs[res[j]]) {f = true;break;}
				}
				if(f) res = t;
			}
		}
		if(!next_permutation(t.begin(),t.end())) break;
	}
	rep(i,n) printf("%d",cs[res[i]]); printf("\n");
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
