#include <iostream>
#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

string a[1020][2];
int ans1,ans2;
string s1,s2;
int now,n;
vector<int> v1,v2;
map<string,int> g;

const int MAXN=2010;
int fx[MAXN],fy[MAXN],gx[MAXN],gy[MAXN],tx[MAXN],ty[MAXN];

struct Hungary {
    bool vis[MAXN];
    vector<int> G[MAXN];
    int L, R, match[MAXN];
    void init(int L, int R) {
        this->L = L; this->R = R;
        for (int i = 0; i < L; ++ i) G[i].clear();
    }
    void addedge(int a, int b) { // left: a, right: b
        G[a].push_back(b); //G[b].push_back(a);
    }
    bool aug(int u) {
        vis[u] = true;
        for (int i = 0, v; i < (int)G[u].size(); ++ i) {
            if (vis[v = G[u][i]]) continue; vis[v] = true;
            if (match[v] < 0 || aug(match[v])) {
                match[v] = u; //match[u] = v;
                return true;
            }
        }
        return false;
    }
    int max_matching() {
        int ret = 0;
        memset(match, -1, sizeof(match));
        for (int i = 0; i < L; ++ i) {
            //if (match[i] != -1) continue;
            memset(vis, 0, sizeof(vis));
            if (aug(i)) ++ ret;
        }
        return ret;
    }
	/*
    vector<int> solve(int arr[]) {
        max_matching();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < L; ++ i) {
            if (match[i] == -1) dfs(i);
        }
        vector<int> ret;
        // Minimum vertex cover
        ret.clear();
        for (int i = 0; i < L; ++ i) 
            if (!vis[i]) ret.push_back(i);
        for (int i = L; i < L + R; ++ i)
            if (vis[i]) ret.push_back(i);
        return ret;
        // Maximum independent set
        ret.clear();
        for (int i = 0; i < L; ++ i) 
            if (vis[i]) ret.push_back(i);
        for (int i = L; i < L + R; ++ i)
            if (!vis[i]) ret.push_back(i);
        return ret;
    }
	*/
};



int main(){
	int T;
	cin >> T;
	for (int ti=1;ti<=T;ti++){
		cin >> n;
		g.clear();
		int tot=0;
		memset(fx,0,sizeof(fx));
		memset(fy,0,sizeof(fy));
		memset(gx,0,sizeof(gx));
		memset(gy,0,sizeof(gy));
		memset(tx,0,sizeof(tx));
		memset(ty,0,sizeof(ty));

		for (int i=0;i<n;i++){
			cin >> a[i][0]>>a[i][1];
			if (g.find(a[i][0])==g.end()){
				g[a[i][0]]=tot++;
			}
			if (g.find(a[i][1])==g.end()){
				g[a[i][1]]=tot++;
			}
			fx[g[a[i][0]]]++;
			fy[g[a[i][1]]]++;
		}
		/*
		if (ti==8){
			for (int i=0;i<n;i++)
				cout<< a[i][0]<<"  "<<a[i][1]<<endl;
			break;
		}
		*/
		int ans=n;
		Hungary hh;
		hh.init(tot,tot);
		for (int i=0;i<n;i++){
			int x=g[a[i][0]];
			int y=g[a[i][1]];
						
			if (fx[x]==1 || fy[y]==1){
				gx[x]=1;
				gy[y]=1;
				ans--;
			}
			
		}
		
		for (int i=0;i<n;i++){
			int x=g[a[i][0]];
			int y=g[a[i][1]];
			if (fx[x]==1 || fy[y]==1){
				continue;
			}
			if (gx[x]==0 && gy[y]==0){
				hh.addedge(x,tot+y);
			}
		}
		/*
		int cnt1=0,cnt2=0;
		for (int i=0;i<MAXN;i++){
			if (tx[i]>0) cnt1++;
			if (ty[i]>0) cnt2++;
		}
		*/
		//cout << ans<<endl;
		int ret=hh.max_matching();
		cout << "Case #" <<ti <<": ";
		cout << ans-ret;
		cout<<endl;
		//if (ti==8){cout<<ans-ret<<endl;break;}
		//break;
	}
	return 0;
}
