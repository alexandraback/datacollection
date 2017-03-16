// In the Name of Allah
// AD13

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/

int cp, jp;
string ans1, ans2;
string coders, jammers;

void f (int ci, int ji) {
    if (ci >= coders.length() && ji >= jammers.length()) {
        int x = atoi(coders.c_str()), y = atoi(jammers.c_str());
        bool doIt = (cp == -1);
        if (!doIt && abs(cp - jp) >  abs(x - y)) doIt = true;
        if (!doIt && abs(cp - jp) == abs(x - y) && x < cp) doIt = true;
        if (!doIt && abs(cp - jp) == abs(x - y) && x == cp && y < jp) doIt = true;
        if (doIt) { cp = x; jp = y; ans1 = coders; ans2 = jammers; }
        return;
    }

    bool doC = (ci < coders.length() && coders[ci] == '?');
    bool doJ = (ji < jammers.length() && jammers[ji] == '?');

    if (!doC && !doJ) {
        f(ci + 1, ji + 1);
        return;
    }

    for (char ch = '0'; ch <= '9'; ch++) {
        if (doC) {
            coders[ci] = ch;
            f(ci + 1, ji);
        }
        else {
            jammers[ji] = ch;
            f(ci, ji + 1);
        }
    }
    if (doC) coders[ci] = '?';
    else jammers[ji] = '?';
}


/*_____________________________________________________________________________________*/

// check debug, read 2 times (until full!)
// think --> idea? --> really works?

int main() {
    //*
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    //*/
    int T;
    cin >> T;
    For1 (tc, T) {
        //cerr << "--> " << tc << " / " << T << endl;

        cin >> coders >> jammers;
        cp = jp = -1;
        f (0, 0);

        cout << "Case #" << tc << ": " << ans1 << ' ' << ans2;
        cout << endl;
    }

    return 0;
}
/*

*/
