#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <utility>
#include <set>
#include <map>
#include <cctype>

#define FOR(i,n) for(long long int i=0; i<n; i++)
#define MP(a,b) make_pair(a,b)
#define PB(x) push_back(x)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())

#define COND(p,t,f) ((p)?(t):(f))

#define PI 3.14159265

using namespace std;
typedef long long int lint;
typedef unsigned long long int ulint;


lint reverse(lint N) {
    lint res = 0;
    while (N) {
        res = 10*res + N%10;
        N/=10;
    }
    return res;
}


int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        lint N;
        cin >> N;
        vector <lint> b(N+2,0);
        b[1] = 1;
        FOR(i,N+1) {
            if (i<2) continue;
            b[i] = b[i-1]+1;
            lint r = reverse(i);
            if (i%10 && r<i && b[r]<b[i-1]) b[i]=b[r]+1;
            //cerr << "i " << i << " b[i] " << b[i] << endl;
        }

        cout << "Case #" << t+1 << ": " << b[N] << endl;
    }

}
