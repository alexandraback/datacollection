/**
* @author Gareve
*/
#define DEBUGs
#ifndef NDEBUG	
	#define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
	#define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <set>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;

int n;
vector<vector<int> > g;
vector<int> ind,indd;
bool diamond;

vector<set<int> > st;

int dfs(int x){
	int y,expe;
	foreach(it,g[x]){
		y = *it;
		
		expe = st[y].size() + st[x].size();
		foreach(tt,st[x])
			st[y].insert(*tt);
		if(expe != st[y].size()){
			//DBG(y);
			//DBG(st[y].size());
			//DBG(expe);
			diamond = true;
		}

		ind[y]--;
		if(ind[y] == 0)
			dfs(y);
	}
}
void buildind(int x){
	foreach(it,g[x]){
		ind[*it]++;
		if(ind[*it] == 1)
			buildind(*it);
	}
}
bool resuelva(){
	scanf("%d",&n);
	g.clear();
	g.resize(n+1);
	ind.clear();
	ind.resize(n+1,0);

	indd.clear();
	indd.resize(n+1,0);	

	int nn;
	int x,y;
	for(int i=1;i<=n;i++)
		indd[i] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&nn);
		x = i;
		for(int j=1;j<=nn;j++){
			scanf("%d",&y);
			g[y].push_back(x);
			indd[x]++;
		}		
	}
	for(int i=1;i<=n;i++){
		//if(indd[i] > 0)continue;

		for(int j=1;j<=n;j++)ind[j] = 0;
		buildind(i);
		diamond = false;
		st.clear();
		st.resize(n+1);
		st[i].insert(i);			
		dfs(i);
		if(diamond)
			return true;		
	}

	return false;
}
int main(){
	int nc;
	scanf("%d",&nc);
	for(int i=1;i<=nc;i++){
		printf("Case #%d: ",i);
		if(resuelva())
			printf("Yes\n");
		else
			printf("No\n");
	}
}