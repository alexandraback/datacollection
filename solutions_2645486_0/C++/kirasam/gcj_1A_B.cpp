#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;

int dp[1000][1000];
int v[1000];
int e, n, r;

int run(int s, int rm){
	int max, ans, nr;
	max = 0;
	if(s==n-1)
		return dp[s][rm] = rm*v[s];
	if(dp[s][rm]!=-1)
		return dp[s][rm];
	for(int i=0; i<=rm; i++){
		nr = rm-i;
		nr += r;
		if(nr>e)
			nr = e;
		ans = i*v[s] + run(s+1,nr);
		if(max<ans)
			max = ans;
	}
	return dp[s][rm] = max;
}

int main(){
	int ncases;
	scanf("%d",&ncases);
	for(int i=0; i<ncases; i++){
		memset(dp,-1,sizeof dp);
		scanf("%d %d %d", &e, &r, &n);
		for(int j=0; j<n; j++){
			scanf("%d", &v[j]);
		}
		printf("Case #%d: %d\n",i+1,run(0,e));
	}
	return 0;
}
