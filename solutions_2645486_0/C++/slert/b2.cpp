#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int v[10010];
struct ed{
	ed(){}
	ed(int _i,int _c, int _w){i = _i; c = _c; w = _w;}
	int i,c,w;
};

int t;

vector<ed> adj[30000];
int vis[30000];
int cx;
int flow(int i, int f, long long &c){
	if(vis[i])return 0;
	vis[i] = 1;
	if(i == t){
		if(c>=cx)return f;
	}
	else{
		for(vector<ed>::iterator k = adj[i].begin(); k != adj[i].end(); k++){
			c+=k->w;
			int s = flow(k->i, min(f,k->c), c);
			if(s>0){
				adj[k->i].push_back(ed(i,s,-k->w));
				if(k->c == s)adj[i].erase(k);
				else k->c-=s;
				// cout << i << ",";
				return s;
			}
			c-=k->w;
		}
	}
	vis[i] = 0;
	return 0;
}

int main(){
	// freopen("test.in","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++){
		int e,r,n;
		scanf("%d%d%d", &e, &r, &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}
		t = n+n+1;

		for(int i = 0; i < n; i++){
			if(i==0)
				adj[0].push_back(ed(i+1,e,0));
			else
				adj[0].push_back(ed(i+1,r,0));
			adj[i+1].push_back(ed(n+i+1,e,0));
			adj[n+i+1].push_back(ed(t,e,v[i]));
			if(i+1<n)
				adj[n+i+1].push_back(ed(i+2,e,0));
		}
		long long sum = 0;
		for(cx = 1000; cx>0; cx--){
			while(true){
				for(int i = 0; i <= t; i++)vis[i] = 0;
				long long c = 0;
				int s = flow(0,e,c);
				if(s>0)sum += s*c;
				else break;
				// cout << "==" << s << ',' << c << endl;
			}
		}
		for(int i = 0; i <= t; i++)
			adj[i].clear();
		cout << "Case #" << ti << ": " << sum << endl;
	}
	return 0;
}