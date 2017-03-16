#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

string map[4];
void solve(){
	int n=4;
	bool dot=false;
	FOR(i,n)
	FOR(j,n){
		bool wx=true;
		bool wy=true;

		if(i == 0){
			FOR(k,n){
				wx=wx && (map[k][j] == 'X' || map[k][j] == 'T');
				wy=wy && (map[k][j] == 'O' || map[k][j] == 'T');	
			}
			if(wx){ cout<<"X won\n"; return; }
			if(wy){ cout<<"O won\n"; return; }
		}
		if(j == 0){ 
			wx=true;
			wy=true;
			FOR(k,n){
				wx=wx && (map[i][k] == 'X' || map[i][k] == 'T');
				wy=wy && (map[i][k] == 'O' || map[i][k] == 'T');	
			}
			if(wx){ cout<<"X won\n"; return; }
			if(wy){ cout<<"O won\n"; return; }

			wx=true;
			wy=true;
			FOR(k,n){
				wx=wx && (map[k][k] == 'X' || map[k][k] == 'T');
				wy=wy && (map[k][k] == 'O' || map[k][k] == 'T');	
			}

			if(wx){ cout<<"X won\n"; return; }
			if(wy){ cout<<"O won\n"; return; }
		}	
		if(j == n - 1){
			wx=true;
			wy=true;
			for(int k=n - 1;k>=0;k--){
				wx=wx && (map[n - k - 1][k] == 'X' || map[n - k - 1][k] == 'T');
				wy=wy && (map[n - k - 1][k] == 'O' || map[n - k - 1][k] == 'T');	
			}
			if(wx){ cout<<"X won\n"; return; }
			if(wy){ cout<<"O won\n"; return; }
		}
		
	}
	FOR(i,n) FOR(j,n) if(map[i][j]=='.'){ cout<<"Game has not completed\n"; return; }
	
	cout<<"Draw\n";
}
int main(){
	int t;
	cin>>t;
	FOR(tt,t){
		FOR(i,4) cin>>map[i];
		cout<<"Case #"<<tt + 1<<": "; 
		solve();
	}
	return 0;
}
