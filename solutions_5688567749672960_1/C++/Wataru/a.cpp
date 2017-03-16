#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


long long n;

int dist[10000010];

void Load()
{
	cin >> n;
}


long long rev(long long x) 
{
	long long ans = 0;
	while (x > 0) {
		ans *= 10;
		ans += x % 10;
		x /= 10;
	}
	return ans;
}


long long pow10[16];

long long F(long long x)
{
//	cerr << "F " << x << "\n";
	if (x < 10) return x;
	long long l, r;
	int len;
	long long p = 1;
	len = 0;
	while (p <= x) {
		p *= 10;
		len++;
	}
//	cerr << "len = " << len << "\n";
	l = x / pow10[(len+1)/2];
	r = x % pow10[(len+1)/2];
//	cerr << l << ' ' << r << "\n";
	long long cur = 0;
	if (l > pow10[len/2-1] && r > 0) {
		cur = r - 1;
//		cerr << "red to " << x-cur << " and invert\n";
		return F(rev(x - cur)) + 1 + cur;
	} else {
		cur = r+1;
//		cerr << "red to " << x-cur << "\n";
		return F(x-cur) + cur;
	}

}

void Solve()
{
	//	cout << dist[n] << "\n";
	long long ans = F(n);
	cout << ans << "\n";
	if (n < 10000000) {
		if (ans != dist[n]) {
			cerr << "BOTVA: " << n << "\n";
		}
	}
}


int q[10000010];
int hd, tl;


void Gen()
{
	memset(dist, -1, sizeof(dist));
	hd = 0;
	tl = 1;
	dist[1] = 1;
	q[0] = 1;
	while (hd < tl) {
		int i = q[hd++];
		int j;
		j = rev(i);
		if (i+1 < 10000000 && dist[i+1] == -1) {
			q[tl++] = i+1;
			dist[i+1] = dist[i]+1;
		}
		if (j < 10000000 && dist[j] == -1) {
			q[tl++] = j;
			dist[j] = dist[i]+1;
		}
	}

	pow10[0] = 1;
	for (int i = 1; i < 16; i++)
		pow10[i] = 10*pow10[i-1];

/*	for (int i = 2; i <= 1000000; i++) {
		if (dist[i] != dist[i-1] + 1)
			cerr << i << "\t" << dist[i] << "\t" << i - dist[i] << "\n";
	}*/


}

int main()
{
	Gen();
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
