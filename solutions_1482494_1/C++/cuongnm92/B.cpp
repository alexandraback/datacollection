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

int n,res,step,num;
int a[maxn],b[maxn],ok[maxn];

int main() {

    freopen("B-large.in","r",stdin);
    freopen("B-large.txt","w",stdout);

    int test,stest,start;
    cin >> stest;
    for(int test=0; test<stest; test++) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i] >> b[i];
            ok[i] = 0;
        }

        start = 0; res = 0 , step = 0;
        int num , s;
        for(int i=0; i<2*n; i++) {
            if (res == n) break;

            num = -1 , s = 0;

            for(int j=0; j<n; j++) if ( start>=b[j] && ok[j] <2 ) {
                num = j;
                s = 2;
            }

            if (num == -1) {
                for(int j=0; j<n; j++) if ( start>=a[j] && ok[j] == 0 ) {
                    if ( (num==-1) || (num>=0 && b[num] < b[j])) {
                        num = j;
                        s = 1;
                    }
                }
            }


            if (num == -1) {
                break;
            } else {
                step++;
                if (ok[num] == 1) start-=1;
                ok[num] = s;
                start += s;
                if ( s==2 ) res++;
            }
        }

        cout << "Case #" << test+1 << ": ";
        if (res < n) {
            cout << "Too Bad" << endl;
        } else {
            cout << step << endl;
        }
    }

    return 0;
}
