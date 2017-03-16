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
#include <map>
#include <climits>
#include <cassert>

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

#define maxn 51
using namespace std;
typedef long long ll;

int RIGHT = 2;
int DOWN = 1;
int NO_SOL = -1;

int next[maxn][maxn][maxn][maxn * maxn];
int f(int y,int x,int xt,int rem){
	// corner conditions
	if(y == 0) return ((rem == 0 && x == xt) ? 1 : 0);
	if(y == 1 && x < xt) return 0;
	if(x > xt) return 0;
	
	if(next[y][x][xt][rem] != -1) return next[y][x][xt][rem];
	int to = 0;
	if(rem - y >= 0 && f(y,x + 1,xt,rem - y) > 0)
		to = RIGHT;
	if(x > 1 && f(y - 1,x,xt,rem) > 0) to = DOWN;
	next[y][x][xt][rem] = to;
	return next[y][x][xt][rem];
}
char mm[maxn][maxn],out[maxn][maxn];

// corner cases
void solve(){
	int r,c,m,rem;
	
	cin>>r>>c>>m;
	rem = r * c - m;
	
	// corner case
	if(rem == 1){
		FOR(i,r)
			FOR(j,c)
				out[i][j] = '*';
		out[0][0] = 'c';
		FOR(i,r){
			FOR(j,c) cout<<out[i][j];
			cout<<"\n";
		}
		return;
	}
	else if(r == 1){
		cout<<"c";
		FORR(i,1,rem) cout<<".";
		FORR(i,rem,c) cout<<"*";
		cout<<"\n";
		return;
	}
	else if(c == 1){
		cout<<"c\n";
		FORR(i,1,rem) cout<<".\n";
		FORR(i,rem,r) cout<<"*\n";
		return;
	}
	FORR(yt,1,r + 1){
		if(yt < r && yt == 1) continue;
		FORR(xt,1,c + 1){
			if(xt < c && xt == 1) continue;
			if(f(yt,0,xt,rem)){
			int y = yt;
			int x = 0;
			int tmp = rem;
			FOR(i,r + 1)
				FOR(j,c + 1) mm[i][j] = '0';
			while(y != 0 || x != xt || tmp != 0){
				mm[y][x] = '1';
				if(next[y][x][xt][tmp] == RIGHT){
					tmp -= y;
					x++;
				}
				else if(next[y][x][xt][tmp] == DOWN)
					y--;
				}
				mm[y][x] = '1';
				
				// output matrix
				FOR(i,r)
					FOR(j,c)
						out[i][j] = '*';
				FOR(j,xt){
					FOR(i,r){
						if(mm[i][j] == '1') break; 
						else out[i][j] = '.';
					}
				}
				out[0][0] = 'c';
				FOR(i,r){
					FOR(j,c){
						cout<<out[i][j];
					}
					cout<<"\n";
				}
				return;
			}	
		}
	}
	cout<<"Impossible\n";
}
int main(){
	int t;
	cin>>t;
	
	memset(next,-1,sizeof next);
	FORR(tt,1,t + 1){
		cout<<"Case #"<<tt<<":\n";
		solve();
	}
	
	return 0;
}
