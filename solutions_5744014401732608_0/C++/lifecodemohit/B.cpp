/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

int a[55][55];

int main()
{
	int t;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		
		int b;
		long long m, val = 1;
		cin >> b >> m;
		m--;
		cout << "Case #" << t1 << ": ";
		memset(a, 0, sizeof(a));
		for (int i = 1; i < b; i++) {
			a[i][i+1] = 1;
		}
		if (m != 0) {
			if (b-2 >= 1) {
				a[b-2][b] = 1;
				m--;
			}
		}
		if (m != 0) {
			for (int i = b-3; i >= 1; i--) {
				if (m == 0)
					break;
				m--;
				a[i][b] = 1;
				if (m == 0)
					break;
				if (m <= ((val)*(val+1)/2)) {
					long long val1 = val;
					int pos;
					for (int j = i+2; j < b; j++) {
						if (m - val1 >= 0) {
							a[i][j] = 1;
							m = m - val1;
						}
						else {
							pos = j;
							break;
						}
						val1--;
					}
					if (m == 0)
						break;
					for (int j = pos; j < b; j++) {
						if (m == val1) {
							a[i][j] = 1;
							m = 0;
							break;
						}
						val1--;
					}
				}
				else {
					m = m - ((val)*(val+1)/2);
					for (int j = i+2; j < b; j++) {
						a[i][j] = 1;
					}
				}
				val++;
			}
		}
		if (m == 0) {
			cout << "POSSIBLE" << endl;
			for (int i = 1; i <= b; i++) {
				for (int j = 1; j <= b; j++) {
					cout << a[i][j] ;
				}
				cout << endl;
			}
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}