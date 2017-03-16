#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define abs(X) ((X)<0?-(X):(X))
#define rst(X) memset(X,0,sizeof(X))
#define pb push_back
#define mp make_pair
#define sz(X) ((int)X.size())
#define ff first
#define ss second

int A, N;
vi V;
int foo(int s){
	int moves = N-s-1, a = A;
	for (int i = 0; i <= s && moves < N; i++){
		if (a>V[i])
			a+=V[i];
		else {
			moves++;
			a+=a-1;
			i--;
		}
	}
	return moves;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		scanf("%d%d", &A, &N);
		V.resize(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &V[i]);
		sort(V.begin(), V.end());
		int ans = N;
		for (int i = 0; i < N; i++)
			ans = min(ans, foo(i));
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
