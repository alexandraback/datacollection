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


int n;

int dist[10000010];

void Load()
{
	cin >> n;
}

void Solve()
{
	cout << dist[n] << "\n";
}


int q[10000010];
int hd, tl;


int rev(int x) 
{
	int ans = 0;
	while (x > 0) {
		ans *= 10;
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

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
