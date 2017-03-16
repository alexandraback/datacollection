#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int tcs, n, m, zips[10], disc[10], id[10], fx[10];
vector<int> adjlist[10];
string best;
char ans[5000];
bool reachable(int a, int b){
	for(int i=0;i<adjlist[a].size();i++){
		if(adjlist[a][i] == b) return true;
	}
	return false;
}
string zip(){
	string ret = "";
	char tmp[10];
	for(int i=0;i<n;i++){
		ret.append(string(itoa(zips[id[i] - 1], tmp, 10)));
	}
	return ret;
}
bool better(string a, string b){
	for(int i=0;i<a.length();i++){
		if(b[i] < a[i]) return true;
		else if(b[i] > a[i]) return false;
	}
	return false;
}
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i%i", &n, &m);
		memset(zips, 0, sizeof zips);
		memset(disc, 0, sizeof disc);
		memset(id, 0, sizeof id);
		memset(adjlist, 0, sizeof adjlist);
		memset(ans, 0, sizeof ans);
		memset(fx, 0, sizeof fx);
		best = string("");
		for(int i=0;i<n;i++){
			scanf("%i", &zips[i]);
			id[i] = i+1;
		}
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%i%i", &a, &b);
			adjlist[a].push_back(b);
			adjlist[b].push_back(a);
		}
		//8!

		do{
			stack<int> vis;
			vis.push(id[0]);
			bool ok = true;
			for(int i=1;i<n;i++){
				while(!reachable(vis.top(), id[i])){
					vis.pop();
					if(vis.empty()) {ok = false; break;}
				}
				vis.push(id[i]);
				if(!ok) break;
			}
			if(!ok) continue;
			string zp = zip();
			if(best.length() == 0) {best = zp; continue;}
			if(better(best, zp)) best = zp;
		}while(next_permutation(id, id + n));
		printf("Case #%i: %s\n", tc, best.c_str());
	}
}