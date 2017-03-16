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

string num[10] = {
    "ZERO", // z
    "ONE", // o 3
    "TWO", // w
    "THREE", // h 3
    "FOUR", // u
    "FIVE", // v 4
    "SIX", // x
    "SEVEN", // s 2
    "EIGHT", // g
    "NINE" // n 5
};

/*_____________________________________________________________________________________*/

// check debug, read 2 times (until full!)
// think --> idea? --> really works?

int main() {
    //*
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    //*/
    int T;
    cin >> T;
    For1 (tc, T) {
        //cerr << "--> " << tc << " / " << T << endl;
        string str;
        cin >> str;
        int cnter[300] = { 0 };
        For (i, str.length()) {
            cnter[str[i]]++;
        }
        int ans[10] = { 0 };

        while (cnter['Z'] > 0) { For(i, num[0].length()) cnter[num[0][i]]--; ans[0]++; }
        while (cnter['W'] > 0) { For(i, num[2].length()) cnter[num[2][i]]--; ans[2]++; }
        while (cnter['U'] > 0) { For(i, num[4].length()) cnter[num[4][i]]--; ans[4]++; }
        while (cnter['X'] > 0) { For(i, num[6].length()) cnter[num[6][i]]--; ans[6]++; }
        while (cnter['G'] > 0) { For(i, num[8].length()) cnter[num[8][i]]--; ans[8]++; }
        while (cnter['S'] > 0) { For(i, num[7].length()) cnter[num[7][i]]--; ans[7]++; }
        while (cnter['O'] > 0) { For(i, num[1].length()) cnter[num[1][i]]--; ans[1]++; }
        while (cnter['H'] > 0) { For(i, num[3].length()) cnter[num[3][i]]--; ans[3]++; }
        while (cnter['V'] > 0) { For(i, num[5].length()) cnter[num[5][i]]--; ans[5]++; }
        while (cnter['N'] > 0) { For(i, num[9].length()) cnter[num[9][i]]--; ans[9]++; }

        cout << "Case #" << tc << ": ";
        For (i, 10) {
            while(ans[i] > 0) { cout << i; ans[i]--; }
        }

        cout << endl;
    }

    return 0;
}
/*

*/
