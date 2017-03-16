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

const int I = 2;
const int J = 3;
const int K = 4;

map <char, int> mm = {{'1',1},{'i',I},{'j',J},{'k',K}};

int m[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I,-1, K,-J},
    {0, J,-K,-1, I},
    {0, K, J,-I,-1},
};

int mul(int x, int y) {
    return COND(x*y>0,1,-1)*m[abs(x)][abs(y)];
}


int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        lint L,X;
        cin >> L >> X;
        string s;
        cin >> s;
        vector<lint> a;
        FOR(i,X) {
            FOR(j,s.size()) {
                a.PB(mm[s[j]]);
            }
        }

        int curr=1;
        int p1=0;
        while (p1<a.size() && curr != I) {
            curr = mul(curr,a[p1++]);
        }
        curr = 1;
        while (p1<a.size() && curr != J) {
            curr = mul(curr,a[p1++]);
        }
        curr = 1;
        while (p1<a.size()) {
            curr = mul(curr,a[p1++]);
        }

        cout << "Case #" << t+1 << ": ";
        cout << COND(curr==K,"YES","NO") << endl;
    }

}
