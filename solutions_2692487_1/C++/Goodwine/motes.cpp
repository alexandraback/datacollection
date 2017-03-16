/*
 * motes.cpp
 *
 *  Created on: May 4, 2013
 *      Author: Goodwine
 */

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int play(int m[], int n, int a, int i) {
	for(;i<n && a > m[i];i++) {
		a += m[i];
	}
	if(i == n)
		return 0;
	int remove = n-i;
	if(a == 1)
		return remove;
	int t = 0;
	while(a <= m[i]) {
		a += (a-1);
		t++;
	}
	t += play(m,n,a,i);
	return remove > t ? t : remove;
}

int solve() {
	int m[105];
	int a, n;
	cin >> a >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m[i];
	}
	sort(m,m+n);
	return play(m,n,a, 0);
}

int main(int argc, char **argv) {
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": " << solve() << endl;
	}
}
