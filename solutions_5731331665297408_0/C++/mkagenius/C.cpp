#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

#define INF 1000000000;

string zips[8];
int N, M, g[8][8];

string hold_ans;

int f(int x, string s, bool ret[][8], bool vis[]){
//	cout << "s = " << s << endl;
	int cnt = 0;
	for(int i = 0; i < N; i++){
//		cout << " " << vis[i] ;
		cnt+=vis[i];
	}
	if(cnt == N){
		hold_ans = min(hold_ans, s);
		return 0;
	}

	// graph
	for(int i = 0; i < N; i++){
		if(!vis[i]){
			if(g[x][i]){
				ret[i][x]=1;
				vis[i] = 1;		
				f(i, s+zips[i],ret, vis);
				ret[i][x]=0;
				vis[i] = 0;
			}
			
		}
	}

	// take return flight
	for(int i = 0; i < N; i++){
		if(ret[x][i]){
			ret[x][i] = 0;
			f(i, s, ret, vis);
			ret[x][i] = 1;
		}
	}
	
	return 0;
}		

int main(){
	freopen("in.txt", "r", stdin);
	int T; cin>>T;
	for(int tc=1; tc<=T; tc++){
		cin >>N>>M;
		string ans = "";
		string s = "99999";
		for(int i = 0; i < N; i++){
			cin >> zips[i];
			ans += s;
			for(int j = 0; j < N; j++){
				g[i][j] = 0;
			}		
		}
		
		for(int i = 0; i < M; i++){
			int x, y; cin>>x>>y;x--;y--;
			g[x][y] = g[y][x] = 1;
		}
		bool ret[8][8];
		string tt = ans;
		for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) ret[i][j] = 0;		
		for(int i = 0; i < N; i++){
			hold_ans = tt;
			bool vis[8];
			memset(vis, 0, sizeof vis);
			vis[i] = 1;
			f(i, zips[i], ret, vis);
			ans = min(hold_ans, ans);
		}
		cout << "Case #"<<tc<<": " << ans<<endl;
	}
	return 0;
}
