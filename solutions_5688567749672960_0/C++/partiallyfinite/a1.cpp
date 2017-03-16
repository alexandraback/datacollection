#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int v[2000001], t, n;
queue<int> q;

int r (int i)
{
	int a = 0;
	while (i) a *= 10, a += i % 10, i /= 10;
	return a;
}

int main ()
{
	fill(v, v + 2000001, 1e9);
	v[1] = 1;
	q.push(1);
	while (q.size()) {
		int i = q.front(); q.pop();
		if (i + 1 <= 2e6 && v[i+1] > v[i] + 1) v[i+1] = v[i] + 1, q.push(i + 1);
		if (r(i) <= 2e6 && v[r(i)] > v[i] + 1) v[r(i)] = v[i] + 1, q.push(r(i));
	}
	cin >> t;
	for (int i = 0; i ++< t;) cin >> n, cout << "Case #" << i << ": " << v[n] << '\n';
}

