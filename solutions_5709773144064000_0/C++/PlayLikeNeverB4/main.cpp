#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

int T;
double C, F, X;

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
	cin >> T;
	for(int t = 1; t <= T; t++) {
        cin >> C >> F >> X;
        
        double last = X / 2;
        double crt = X / 2;
        double extra = 0.0;
        double vmin = crt;
        double rate = 2.0;
        do {
            last = crt;
            extra += C / rate;
            rate += F;
            crt = extra + X / rate;
            vmin = min(crt, vmin);
        }
        while(crt < last);
        
        cout << "Case #" << t << ": ";
        cout << fixed << setprecision(7) << vmin << '\n';
	}
	
	return 0;
}
