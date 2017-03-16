#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "set"
#include "map"
#include "queue"
#include "vector"
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)
#define repp(i,a,b) for(int i=a; i<a+b; ++i)
#define sz size()
#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
int K,n;
struct YF{
	int a,b,c;
	int ab, ac, bc;
	void setabc(int _a, int _b, int _c, int A, int B, int C){
		a = _a, b = _b, c = _c;
		ab = a * B + b;
		ac = a * C + c;
		bc = b * C + c;		
	}
}yf[1005];
int ans[1005];
int b[1005], sab[200], sbc[200], sac[200], all;
int best;
void dfs(int u){
	if(all + n - u < best) return;
	if(u==n){
		if(all > best){
			best = all;
			rep(i,n) ans[i] = b[i];
		}
		return;
	}
	if(sab[yf[u].ab] < K && sac[yf[u].ac] < K && sbc[yf[u].bc] < K){
		sab[yf[u].ab]++;
		sac[yf[u].ac]++;
		sbc[yf[u].bc]++;
		b[u] = 1;
		all++;
		dfs(u+1);
		all--;
		b[u] = 0;
		sab[yf[u].ab]--;
		sac[yf[u].ac]--;
		sbc[yf[u].bc]--;
	}
	dfs(u+1);
}

void run(){
	int A,B,C;
	cin >> A >> B >> C >> K;
	n = 0;
	rep(i,A)rep(j,B)rep(k,C){
		yf[n].setabc(i,j,k,A,B,C);
		++n;
	}
	memset(b, 0, sizeof b);
	memset(sab, 0, sizeof sab);
	memset(sac, 0, sizeof sac);
	memset(sbc, 0, sizeof sbc);
	best = all = 0;
	dfs(0);
	printf("%d\n", best);
	rep(i,n) if(ans[i]){
		printf("%d %d %d\n", yf[i].a + 1, yf[i].b + 1, yf[i].c + 1);
	}
}

int main(int argc, char const *argv[])
{
	int cas;
	cin >> cas;
	rep(ca,cas){
		printf("Case #%d: ", ca+1);
		run();
	}
	return 0;
}