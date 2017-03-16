#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

#define sqr(a) (a) * (a)

using namespace std;

string s, t;
int T, i, tt;


int main()  {

    #ifndef ONLINE_JUDGE
    freopen("a.in", "r" , stdin);
    freopen("a.out", "w", stdout);
    #endif

    cin >> T;
	for (tt = 1; tt <= T; tt++) {
		cin >> s;
		t = s[0];
		for (i = 1; i < s.length(); i++)
			if (s[i] >= t[0])
				t = s[i] + t;
			else
				t += s[i];

		printf("Case #%d: ", tt);
		cout << t << endl;

	}

          
    return 0;
}