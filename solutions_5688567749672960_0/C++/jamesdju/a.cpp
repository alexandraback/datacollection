#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF	(int)1e9
#define EPS 1e-9
#define what_is(x) cerr << #x << " is " << x << endl;

int dir[8][2] = {{1,1},{1,0},{1,-1},{0,-1},   // NE,E,SE,S
			    {-1,-1},{-1,0},{-1,1},{0,1}}; // SW,W,NW,N

int dir2[4][2] = {{1,0}, {0,-1}, {-1, 0}, {0,1}};

int n;

int rev(int x){
	int r = 0;
	while(x != 0){
		r = r*10;
		r += x%10;
		x /= 10;
	}
	return r;
}

int memo[1000010];

int main(){
	memset(memo, -1, sizeof memo);
	memo[0] = 1;
	for(int i = 1; i <= 20; i++){
		memo[i] = i;
	}

	for(int i = 1; i <= 1000000; i++){
		if(memo[i] == -1) memo[i] = memo[i-1] + 1;
		else memo[i] = min(memo[i], memo[i-1] + 1);

		int x = rev(i);
		if(memo[x] == -1) memo[x] = memo[i] + 1;
		else memo[x] = min(memo[x], memo[i] + 1);
	}

	int tc, casenum = 1;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		printf("Case #%d: %d\n", casenum++, memo[n]);
	}
}