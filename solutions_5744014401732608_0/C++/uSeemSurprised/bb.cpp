#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

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

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int n, mat[100][100], mr[100], ans[100][100];
LL B, M, tot;
bool fd;

void countt(int curr){
	if(tot > M) return;
	if(curr == B-1){
		tot++;
		return;
	}
	mr[curr] = 1;
	for(int i = 0;i < B;i++){
		if(mr[i] == 0 && mat[curr][i] == 1){
			countt(i);
		}else if(mr[i] == 1 && mat[curr][i] == 1){
			tot += 5000;
		}
	}
	mr[curr] = 0;
}

void solve(int idx){
	if(fd == true) return;
	int idx1 = idx/B;
	int idx2 = idx % B;
	if(idx == (B*B)){
		tot = 0;
		countt(0);
		if(tot == M){
			fd = true;
			for(int i = 0;i < B;i++) for(int j = 0;j < B;j++) ans[i][j] = mat[i][j];
		}
		return;
	}
	if(idx1 == idx2 || idx1 == (B-1)){
		solve(idx+1);
	}else{
		solve(idx+1);
		mat[idx1][idx2] = 1;
		solve(idx+1);
		mat[idx1][idx2] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cout << "Case #" << casee << ": " ;
		cin >> B >> M;
		for(int i = 0;i < B;i++) for(int j = 0;j < B;j++) mat[i][j] = 0, ans[i][j] = 0;
		for(int i = 0;i < B;i++) mr[i] = 0;
		tot = 0;
		fd = false;
		solve(0);
		if(fd == true){
			cout << "POSSIBLE" << endl;
			for(int i = 0;i < B;i++){ for(int j = 0;j < B;j++) cout << ans[i][j]; cout << endl;}
		}else{
			cout << "IMPOSSIBLE" << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}

