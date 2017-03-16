#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define TRvii(c,it) for (vii::iterator it =(c).begin(); it!=(c).end(); it++)
#define pi 3.14159265359

// cout << "Case #" << z << ": " <<    << endl;
vector<int> colour(1002);
vector<vii> Adj(1002);
vector<int> dist(1002);
vector <vii> AdjT(1002);
vector<int> dist2(1002);
vector<int> dist3(1002);
int count;
int source;
void dfs (int u){
	colour[u] = 1;
	TRvii(Adj[u],v)
		if (((colour[v->first] == 0)&&(colour[(Adj[v->first][0]).first]==0)||((colour[v->first] == 0)&&(Adj[v->first][0].first==source)))) {
			dist[v->first] = dist[u]+1;
			dfs(v->first);
		}
		
	colour[u] = 2;
}

void dfs2 (int u){
	colour[u] = 1;
	TRvii(AdjT[u],v)
		if (colour[v->first] == 0){
			dist2[v->first] = dist2[u]+1;
			dfs2(v->first);
		}
		
	colour[u] = 2;
}


void dfs3 (int u){
	colour[u] = 1;
	TRvii(AdjT[u],v)
		if (colour[v->first] == 0){
			dist3[v->first] = dist3[u]+1;
			dfs3(v->first);
		}
		
	colour[u] = 2;
}
int main () {
	FILE* ifile = freopen("C-small-attempt0 (1).in", "r", stdin);
	FILE* ofile = freopen ("ofile.txt", "w", stdout);
	int t;
	cin >> t;
	for (int z=1; z<=t; z++){
		int n;
		cin >> n;
		for (int i=1; i<=n; i++){
			Adj[i].clear();
			AdjT[i].clear();
		}
		for (int i=1; i<=n; i++){
		int v;
		cin >> v;
		Adj[i].push_back(make_pair(v,1));
		AdjT[v].push_back(make_pair(i,1));
		}
		int globallargest=0;
		for (int s=1; s<=n; s++){
			source = s;
		for (int i=0; i<=1000; i++){
				colour[i] = 0;
				dist[i] = 0;
				dist2[i]=0;
				dist3[i]=0;
		}
		dfs(s);
		int localmax = 0;
		int mindex;
		for (int i=1; i<=n; i++){
			if (dist[i] > localmax){
				localmax= dist[i];
				mindex = i;
			}
		}
		int check =1;
		if (Adj[mindex][0].first == source){
			check = 0;
		}
		dfs2(s);
		dfs3(mindex);
		int local2max=0;
		int local3max=0;
		for (int i=1; i<=n; i++){
			if (dist2[i]>local2max){
				local2max = dist2[i];
			}
			if (dist3[i]>local3max){
				local3max = dist3[i];
			}
		}
		if (!check){
			local2max = 0;
			local3max =0;
		}
		if (local2max+local3max+localmax+1 > globallargest){
			globallargest = local2max+local3max+localmax+1;
		}
		}
		cout << "Case #" << z << ": " << globallargest   << endl;
		}	
		
	
return 0;}
