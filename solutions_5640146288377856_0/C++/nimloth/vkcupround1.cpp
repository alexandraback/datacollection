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

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	//cout.setf(ios::fixed);
	//cout.precision(9);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int r, c, w;
        cin >> r >> c >> w;
        int d = c / w;
        int ans;
        if (c % w == 0) {
            ans = d * r + w - 1;
        }
        else {
            ans = d * r + w;
        }
        cout << "Case #" << t + 1 << ": " << ans << "\n";
    }
    return 0;
}
/*
6 20
10 50 100 500 1000 5000
8
*/
