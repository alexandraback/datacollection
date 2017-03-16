#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <mutex> 
#include <bitset>
#include <set>
#include <string>
#include <thread>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL long long
#define EPS 0.00000000001
#define MOD 1000000000
#define INF 2000000000
#define TT 102
std::mutex mtx;
int T, nmtx = 0;
#define OK(); for(;;){mtx.lock();nmtx++;mtx.unlock();break;}
#pragma comment(linker, "/stack:102400000")
#define N 1000008
typedef struct{ LL a;; }tres;
tres res[TT];
int d[N];

int rev(int a){
	int cur = 0;
	for (; a > 0;){
		cur = cur * 10 + a % 10;
		a /= 10;
	}
	re cur;
}
//int digits(int a){
//	int cur = 0;
//	for (; a > 0;){
//		cur++;
//		a /= 10;
//	}
//	re cur;
//}
//
//int go(int a){
//	if (d[a] < 0)re 0;
//	if (d[a] > 0)re d[a] - 1;
//	d[a] = -1;
//	if (a <= 10)re a;
//	int t1 = go(a - 1);
//
//	int rv = rev(a), dv = digits(rv), dme = digits(a);
//	int t2 = N; if (rv < a&&dme <= dv && rv!=a-1) t2 = go(rv);
//
//	t1 = 1 + min(t1, t2);
//	d[a] = 1 + t1;
//	re t1;
//}

void solve(int t)
{
	int n;
	cin >> n;
	
	for (int i = 0; i <= n; ++i)d[i] = N;
	d[1] = 1;
	for (int i = 1; i < n; ++i){
		int rv = rev(i);
		d[rv] = min(d[rv], d[i] + 1);
		d[i+1] = min(d[i+1], d[i] + 1);
	}

	cout << "Case #" << t + 1 << ": " << d[n] << endl;
	//OK();
}

int main() {
	freopen("A-small-attempt1.in", "rt", stdin);
	//freopen("A.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
	
	cin >> T;
	for (int t = 0; t < T; ++t){
		//thread * ñThread = new thread(std::bind(&solve, t));
		solve(t);
	}
	//for (; nmtx < T;){ this_thread::sleep_for(std::chrono::milliseconds(50)); }

	/*for (int t = 0; t < T; ++t){
		cout << "Case #" << t + 1 << ": " <<res[t].a;
		cout << endl;
	}*/
	re 0;
}