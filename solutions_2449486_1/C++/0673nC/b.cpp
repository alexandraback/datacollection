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

int T,N,M;
int map[105][105],map_[105][105];
int n[105],m[105];

int main()
{
	cin >> T;
	rep(t,T){
		cin >> N >> M;
		memset(n,0,sizeof(n));
		memset(m,0,sizeof(m));
		memset(map,0,sizeof(map));
		memset(map_,0,sizeof(map_));
		rep(i,N)rep(j,M){
			cin >> map[i][j];
			n[i]=max(n[i],map[i][j]);
			m[j]=max(m[j],map[i][j]);
			map_[i][j]=100;
		}

		rep(i,N)rep(j,M){
			map_[i][j] = min(map_[i][j],min(n[i],m[j]));
		}

		bool f=true;
		rep(i,N)rep(j,M)if(map[i][j]!=map_[i][j]) f=false;
		printf("Case #%d: %s\n",t+1,f?"YES":"NO");
		//rep(i,N)rep(j,M)printf("%d%c",map_[i][j],j!=M-1?' ':'\n');
	}
	return 0;
}
