#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 30;

int tc;
long long f[size + 10][8];
long long a, b, c;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> a >> b >> c;

    	for (int i = 0; i <= size; i++)
    		for (int j = 0; j < 8; j++)
    			f[i][j] = 0;
//    	for (int i = 0; i < 8; i++)
//    		f[0][i] = 1;
		f[0][7] = 1;
    	for (int i = 0; i < size; i++) {
    		for (int j = 0; j < 8; j++) {
    			int l1 = ((a >> i) & 1) | (j & 1);
    			int l2 = ((b >> i) & 1) | ((j >> 1) & 1);
    			int l3 = ((c >> i) & 1) | ((j >> 2) & 1);
    			for (int p1 = 0; p1 <= l1; p1++)
    				for (int p2 = 0; p2 <= l2; p2++)
    					for (int p3 = 0; p3 <= l3; p3++) {
    						if ((p1 & p2) == p3)
	    						f[i + 1][j] += f[i][j | (l1 ^ p1) | ((l2 ^ p2) << 1) | ((l3 ^ p3) << 2)];
    					}
    		}
    	}

    	cout << "Case #" << tnum + 1 << ": " << f[size][0] << endl;
    }

    return 0;
}