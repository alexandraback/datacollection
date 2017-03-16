#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i < (b); i++)
#define foreach(it, c) for(__typeof (c).begin() it = (c).begin(); it != (c).end(); ++it)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sqr(x) ((x) * (x))
#define clr(m, c) memset((m), (c), sizeof (m))
#define DBG(x) cout << #x << " = " << x << endl
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

template<class T> T abs(T x) { return x > 0 ? x : -x; }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int R, N, M, K;
int A[100];
int prod[100];

bool fin;

void go(int i){
	if(fin) return;
	if(i == N and !fin){
		
	//	cout << fin << endl;
		int h;
		for(h = 0; h < K; h++){
			int aux = prod[h];
			for(int k = 0; k < N; k++){
				if(aux % A[k] == 0) aux /= A[k];
			}
			if(aux != 1) break;
		}
		if(h == K){
			fin = true;
			for(int h = 0; h < N; h++)
				cout << A[h];
			cout << endl;
			return;
		//	cout << "YESSSSSSSSSSSS" << endl;
	//		cout << fin << endl;
		}
		return;
	}
	if(i == N) return;
	for(int j = 2; j <= M; j++){
		A[i] = j;
		go(i + 1);
	}
	return;
}
int main(){
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){
		cin >> R >> N >> M >> K;
		cout << "Case #" << t << ": " << endl;
		for(int i = 0; i < R; i++){
			//int prod[K];
			for(int j = 0; j < K; j++) cin >> prod[j];
			fin = false;
			go(0);
		}
	//	fin = false;
	//	go(0);
	}
	return 0;
}

