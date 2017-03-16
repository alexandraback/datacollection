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

const int maxn = 200 + 10;
const int t = 10000000;
const int maxp = 100*t;
const double err = 0.000001;

int n , X;
int s[maxn],res[maxn];

bool check(int a,int b,int index) {

    int rest = b , u , v , mid , r;
    double x1 , x2;
    for(int i=0; i<n; i++) if (i != index) {
            u = 0; v = rest; r = -1;
            while (u<=v) {
                mid = (u+v)/2;
                x1 = s[index] + X*((double)a / maxp);
                x2 = s[i] + X*((double)mid / maxp);

                if (x1<x2) {
                    r = mid;
                    v = mid - 1;
                } else {
                    u = mid+1;
                }
            }

            if ( r == -1) return true;
            else {
                rest = rest - r;
            }
    }

    return false;
}

int main() {

    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aout.txt","w",stdout);

    int stest = 0;
    cin >> stest;

    int a , b , mid , rest;
    double x1 , x2;

    for(int test=0; test<stest; test++) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> s[i];
        }

        X = 0;
        for(int i=0; i<n; i++) X += s[i];

        for(int i=0; i<n; i++) {
            a = 0;
            b = maxp;

            while (a<=b) {
                mid = (a+b)/2;
                rest =  maxp - mid;

                if (check(mid,rest,i)) {
                    res[i] = mid;
                    b = mid - 1;
                } else {
                    a = mid + 1;
                }
            }
        }


        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(6);
        cout << "Case #" << test+1 << ": ";
        double dt = (double)t;
        for(int i=0; i<n; i++) {
            cout << (1.0*res[i])/dt << " ";
        }

        cout << endl;
    }

    return 0;
}
