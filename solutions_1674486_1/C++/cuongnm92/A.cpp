#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <locale>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
#include <complex>
#include <valarray>

#define rep(i, n) for (int i = 0; i < n; ++ i)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ll long long
#define cmplxd complex <long double>
#define pi 3.14159265358979323846264338327950288


using namespace std;
const int maxn = 1001 + 10;

int stest;
int n;
string res;
int m[maxn];
bool c[maxn];
int v[maxn][maxn];

bool visit(int x) {
    c[x] = false;
    for(int i=1; i<=m[x]; i++) {
        if ( c[v[x][i]] ) {
            visit(v[x][i]);
        } else {
            res = "Yes";
        }
    }
}

int main() {

    freopen("A-large.in","r",stdin);
    freopen("A-large-out.txt","w",stdout);


    cin >> stest;
    for(int test = 0; test < stest; test++) {
        cin >> n;

        for(int i=1; i<=n; i++) {
            cin >> m[i];
            //cout << m[i] << endl;
            for(int j=1; j<=m[i]; j++) {
                cin >> v[i][j];
            }
        }

        res = "No";
        for(int i=1; i<=n; i++) {

            for(int j=1; j<=n; j++) c[j] = true;
            visit(i);
            if (res == "Yes") break;

        }

        cout << "Case #" << test+1 << ": " << res << endl;
    }

    return 0;
}
