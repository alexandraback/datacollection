#include <iostream>
#include <string.h>
#include <string>

#include <stdio.h>

using namespace std;

string a[200];
string b[200];

int count(int s)
{
	int r = 0;
	while (s) {
		r += (s & 1);
		s >>= 1;
	}
	return r;
}

int n;
int yes[100];
bool ok(int s)
{
	for (int i=0; i<n; ++i) {
		yes[i] = s & 1;
		s >>= 1;
	}
	for (int i=0; i<n; ++i) {
		if (!yes[i])
			continue;
		bool yesa = false;
		bool yesb = false;
		for (int j=0; j<n; ++j) {
			if (yes[j]) continue;
			if (a[j] == a[i]) yesa = true;
			if (b[j] == b[i]) yesb = true;
			if (yesa && yesb)
				break;
		}
		if (yesa && yesb) {
		} else {
			return false;
		}
	}
	return true;
}

int best;

void solve(int no)
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i] >> b[i];
	best = 0;
	for (int s=1; s<(1<<n); ++s) {
		if (count(s) <= best)
			continue;
		if (ok(s)) {
			best = count(s);
		}
	}
	printf("Case #%d: %d\n", no, best);
}

int main()
{
	int T;
	cin >> T;
	for (int i=0; i<T; ++i)
		solve(i+1);
	return 0;
}
