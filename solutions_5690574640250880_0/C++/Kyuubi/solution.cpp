#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007
#define SWAP(a,b) {a=(a)^(b);b = (a)^(b);a= (a)^(b);}

int R = 5;
int C = 5;
int M = 12;
using namespace std;
inline long long minOf(long long x, long long y){return (x<y?x:y);}
inline long long maxOf(long long x, long long y){return (x>y?x:y);}
inline long long mabs(long long x){return (x<0?-x:x);}

typedef pair<int, int> Pair;

int cc = 0;
bool reached[25 +1];
vector<int>bit;

Pair mapToP(int i){
	Pair ret;
	ret.first = i/C;
	i = i%C;
	ret.second = i;
	return ret;
}


int mapToI(Pair p){
	int ret = (p.first*C) + p.second;
	return  ret;
}

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

bool hasBomb(Pair c, int i){
	int nx,ny;
	nx = c.first + dx[i];
	ny = c.second + dy[i];
	if(nx <0 || nx >=R || ny <0 || ny >= C)
		return false;
	if(bit[mapToI(Pair(nx,ny))] == 0)
		return true;
	return false;
}

bool reachable(Pair c, int i){
	int nx,ny;
	nx = c.first + dx[i];
	ny = c.second + dy[i];
	if(nx <0 || nx >=R || ny <0 || ny >= C)
		return false;
	if(reached[mapToI(Pair(nx,ny))])
		return false;
	return true;
}

Pair nextLoc(Pair c, int i){
	int nx,ny;
	nx = c.first + dx[i];
	ny = c.second + dy[i];
	return Pair(nx,ny);
}

bool cSet;
int cx,cy;

void bfs(Pair cur){
	reached[mapToI(cur)] = true;
	cc++;
	for(int i = 0;i<8;i++)
		if(hasBomb(cur,i))
			return;
	
	for(int i = 0;i<8;i++)
		if(reachable(cur,i))
			bfs(nextLoc(cur,i));
}
bool isValid(vector<int> &v){
	Pair pp;
	for(int i = 0;i<v.size();i++){
		if(v[i] == 1){
			cc = 0;
			pp = mapToP(i);
			cx = pp.first;
			cy = pp.second;
			memset(reached, false, sizeof(reached));
			cSet = false;
			bfs(mapToP(i));
			if(cc == (R*C)-M)
				return true;
		}
	}
	return false;
}

vector< int > dp[6][6][30];
bool pres[6][6][30];
Pair centers[6][6][30];
bool done[6][6][30];

bool getAnsFor(int r, int c, int m){
	bit.clear();
	R = r;
	C = c;
	M = m;
	for(int i = 0;i<M;i++)
		bit.push_back(0);
	for(int i = 0;i<(R*C)-M;i++)
		bit.push_back(1);
	do{
		if(isValid(bit)){
			bit[mapToI(Pair(cx,cy))] = 'c';
			dp[r][c][m] = bit;
			pres[r][c][m] = true;
			return true;
		}
	}while(next_permutation(bit.begin(), bit.end()));
	return false;
}

void print(int r, int c, int m){
	int ii =0;
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			if(dp[r][c][m][ii] == 0)
				cout << "*";
			else if(dp[r][c][m][ii] == 1)
				cout << ".";
			else
				cout << "c";
			ii++;
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t,r[250],c[250],m[250];
	cin >> t;
	Pair pp;
	for(int tt = 1; tt <=t ;tt++){
		cin >> r[tt] >> c[tt] >> m[tt];
		if(done[r[tt]][c[tt]][m[tt]])
			continue;
		getAnsFor(r[tt], c[tt], m[tt]);
	}
	
	for(int tt = 1; tt<=t; tt++){
		cout << "Case #" << tt << ":" << endl;
		if(pres[r[tt]][c[tt]][m[tt]])
			print(r[tt],c[tt],m[tt]);
		else
			cout << "Impossible" << endl;
	}
	
	return 0;
}






