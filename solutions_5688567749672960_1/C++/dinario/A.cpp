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

#define N 1100008

LL d[N];
//int t2[N]; //int t1[N];

LL rev(LL a){
	LL cur = 0;
	for (; a > 0;){
		cur = cur * 10 + a % 10;
		a /= 10;
	}
	re cur;
}
LL digits(LL a){
	LL cur = 0;
	for (; a > 0;){
		cur++;
		a /= 10;
	}
	re cur;
}
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
//
//void solve(int t)
//{
//	int n;
//	cin >> n;
//	
//	for (int i = 0; i <= n; ++i){ d[i] = N; t2[i] = 0;
//	//t1[i] = 0;
//	}
//	d[1] = 1;
//	for (int i = 1; i < n; ++i){
//		int rv = rev(i);
//
//		if (d[i] + 1 < d[rv]){
//			d[rv] = d[i] + 1;
//			//t1[rv] = t1[i];
//			t2[rv] = i;// t2[i] + 1;
//		}
//		if (d[i] + 1 < d[i + 1]) {
//			d[i+1] = d[i] + 1;
//			//t1[i + 1] = t1[i] + 1;
//			t2[i + 1] = t2[i];
//		}		
//	}
//	for (int i = 1; i < n; ++i)if (t2[i] != t2[i - 1]){
//		//cout << t2[i] << endl;
//	}
//	for (int i = n; i>0;){
//		cout << t2[i] << endl;
//		i = t2[i];
//	}
//
//	cout << "Case #" << t + 1 << ": " << d[n] << endl;
//	//OK();
//}

void prep(int n)
{
	for (int i = 0; i <= n; ++i)
		d[i] = N;
	d[1] = 1;
	for (int i = 1; i < n; ++i){
		int rv = rev(i);

		if (rv <=n && d[i] + 1 < d[rv])
			d[rv] = d[i] + 1;
		if (d[i] + 1 < d[i + 1]) 
			d[i + 1] = d[i] + 1;
	}
}

LL cnt(LL n)
{
	if (n <= 1000000)re d[n];

	LL d1 = digits(n), dd1 = d1 / 2;

	//n -= 1;
	LL left = n, r10 = 1, sum = 0; for (LL i = 0; i < dd1; ++i){
		r10 *= 10;
		sum += left % 10;
		left /= 10;
	}
	if (sum == 0)left -= 1;

	LL nxt = left * r10 + 1, rv = rev(nxt);
	
	/*if (rv == nxt)
		rv -= 1;*/

	if (rv != nxt)
		re (n - nxt) + 1 + cnt(rv);

	re (n - nxt) + 1 + cnt(rv - 1);
}

void solve2(int t)
{
	LL n;
	cin >> n;

	LL res = 0;
	if (n < 1000000)res = d[n];
	else res = cnt(n);
	cout << "Case #" << t + 1 << ": " << res << endl;
}

int main() {
	freopen("A-large.in", "rt", stdin);
	//freopen("A.in", "rt", stdin);
	freopen("A2.out", "wt", stdout);
	
	prep(N);

	//for (int i = 200; i < 1019000; ++i){
	//	int lk = cnt(i);
	//	if (lk != d[i]){
	//		cout << "d";
	//	}
	//}
	cin >> T;
	for (int t = 0; t < T; ++t){
		solve2(t);
	}
	re 0;
}