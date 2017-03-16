#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
//#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,j,k) for(int i=j;i<(int)(k);++i)
#define foreach(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 99999999;
const double EPS = 1e-9;

string map[4];
int T;
int dx[4]={1,1,1,0},dy[4]={-1,0,1,1};
bool f=false;

bool serch(int t,int y,int x)
{
	//cout << "xy "<< y << " " << x <<endl;
	rep(i,4){
		char yx = map[y][x];
		int yy=y+dy[i],xx=x+dx[i];
		int cnt=0;
		rep(j,3){
			//cout << i << " "<< yy << " " << xx << endl;
			if(yy<0||yy>=4||xx<0||xx>=4) break;
			if(yx=='T'&&map[yy][xx]!='.') yx=map[yy][xx];
			if(!(map[yy][xx]==yx||map[yy][xx]=='T')) break;
			cnt++;
			yy+=dy[i],xx+=dx[i];
		}

		if(cnt==3){
			printf("Case #%d: %c %s\n",t+1,yx,"won");
			return true;
		}
	}
	
	return false;
}

int main()
{
	cin >> T;
	rep(t,T){
		rep(i,4) cin >> map[i];
		f=false;
		rep(i,4)rep(j,4)if(!f){
			if(map[i][j]!='.') f=serch(t,i,j);
		}

		bool b=false;
		if(!f)rep(i,4)rep(j,4)if(map[i][j]=='.') b=true;
		if(!f&&b) printf("Case #%d: %s\n",t+1,"Game has not completed");
		if(!f&&!b) printf("Case #%d: %s\n",t+1,"Draw");
	}
	return 0;
}
