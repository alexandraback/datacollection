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



int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        int x,r,c;
        cin >> x >> r >> c;
        int res;
        if (x==1) res=0;

        if (x==2) res = (r*c)%2;

        if (x==3) {
            int s=r*c;
            res = (int)(!(s==9 || s==12 || s==6));
        }

        if (x==4) {
            int s=r*c;
            res = (int)(!(s==16 || s==12));

        }
        cout << "Case #" << t+1 << ": ";
        cout << COND(res,"RICHARD","GABRIEL") << endl;
    }

}
