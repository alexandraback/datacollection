#include<bits/stdc++.h>
#include <unistd.h>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 5000006

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int dp[MAXX], n, rr[MAXX];

int rev(int no){
	int ans = 0, nn = no;
	vector<int> vv;
	while(no > 0){
		int dig = no%10;
		vv.PB(dig);
		no/=10;
	}
	int b = 1;
	int sz = vv.size();
	for(int i = sz-1;i>=0;i--){
		ans += (vv[i]*b);
		b = b * 10;
	}
	return ans;
}

int solve(int idx){
	//LOG(idx);
	if(idx == n) return 0;
	if(dp[idx] != -1) return dp[idx];
	
	int noo = rr[idx];
	int v1 = n, v2 = n;
	if(idx <= n) v1 = solve(idx+1) + 1;
	if(noo > idx && noo <= n) v2 = solve(noo) + 1;
	dp[idx] = min(v1, v2);
	return min(v1, v2);
}
void pre(){
	for(int i = 0;i<=1000006;i++){
		rr[i] = rev(i);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	pre();
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cin >> n;
		for(int i = 0;i<MAXX;i++) dp[i] = -1;
		cout << "Case #" << casee << ": " ;
		cout << solve(1)+1 << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
return 0;	
}

