#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))

using namespace std;

const int MaxN = 1000000;

int d[MaxN+1];
vector<int> p;

bool isCon(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return false; else return true;
}

int Find(int x) {
	int l = 0, r = p.size()-1;
	while (l < r-1) {
		int mid = (l+r)/2;
		if (p[mid] >= x) r = mid; else l = mid;
	}
	if (p[l] >= x) return p[l]; else return p[r];
}

int main () {
	int T;
	scanf ("%d\n", &T);
	for (int tests = 0; tests < T; tests++) {
		printf ("Case #%d: ", tests+1);
		long long result = 0;
		string s;
		int n;
		cin >> s >> n;
		
		int l = s.length();
		d[l] = 0;
		for (int i = l-1; i >= 0; i--) 
			if (isCon(s[i])) d[i] = d[i+1]+1; else d[i] = 0;
		p.clear();
		for (int i = 0; i < l; i++) if (d[i] >= n) p.push_back(i);
		if (p.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < l; i++) {
			if (p[p.size()-1] < i) continue;
			int q = Find(i);
			//cout << i << " " << q << endl;
			//if (l-q-n+1 > 0) 
				result += (long long) (l-q-n+1);
		}
		cout << result << endl;
	}
}

