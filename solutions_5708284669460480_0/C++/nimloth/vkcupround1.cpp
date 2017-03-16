#pragma comment(linker, "/STACK:65777216")
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stdio.h>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <ctime>
#include <stdlib.h>

using namespace std;

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long li;
typedef unsigned long long uli;

int z[1000];
string word, letter;
double let[1000];

void z_function (string &s) {
	int n = (int) s.length();
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	cout.setf(ios::fixed);
	cout.precision(9);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int k, l, s;
        cin >> k >> l >> s;
        cin >> letter;
        cin >> word;
        int mx = 0;
        for (int i = 0; i < l; ++i)
            z[i] = 0;
        z_function(word);
        for (int i = 1; i < l; ++i)
            if (z[i] == l - i)
                mx = max(mx, z[i]);
        int c = 1 + (s - l) / (l - mx);
        for (int i = 0; i < 100; ++i)
            let[i] = 0;
        for (int i = 0; i < k; ++i)
            let[letter[i] - 'A'] = let[letter[i] - 'A'] + 1;
        int fl = 0;
        for (int i = 0; i < l; ++i)
            if (let[word[i] - 'A'] == 0) fl = 1;
        if (fl == 1) {
            cout << "Case #" << t + 1 << ": " << 0.0 << "\n";
            continue;
        }
        double C = (double) c;
        double p = 1;
        for (int i = 0; i < l; ++i)
            p = p * (double) (let[word[i] - 'A'] / k);
        p = p * (double) (s - l + 1);
        double ans = C - p;
        //if (ans < 0) ans = 0;
        //cout << C << " " << p << "\n";
        cout << "Case #" << t + 1 << ": " << ans << "\n";
    }
    return 0;
}
/*
6 20
10 50 100 500 1000 5000
8
*/
