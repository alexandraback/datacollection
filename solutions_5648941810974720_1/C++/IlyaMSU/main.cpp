#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 100;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;

vector<string> dig = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

void f(int d, vector<int>& a) {
    for (int i = 0; i < dig[d].size(); ++i)
        a[dig[d][i] - 'A']--;
}

string solve() {
    string s;
    cin >> s;
    vector<int> a(26, 0);
    for (int i = 0; i < s.size(); ++i)
        ++a[s[i] - 'A'];
    vector<int> res(10, 0);
    while (a['Z' - 'A']) {
        ++res[0];
        f(0, a);
    }
    while (a['W' - 'A']) {
        ++res[2];
        f(2, a);
    }
    while (a['U' - 'A']) {
        ++res[4];
        f(4, a);
    }
    while (a['X' - 'A']) {
        ++res[6];
        f(6, a);
    }
    while (a['G' - 'A']) {
        ++res[8];
        f(8, a);
    }
    while (a['F' - 'A']) {
        ++res[5];
        f(5, a);
    }
    while (a['O' - 'A']) {
        ++res[1];
        f(1, a);
    }
    while (a['H' - 'A']) {
        ++res[3];
        f(3, a);
    }
    while (a['S' - 'A']) {
        ++res[7];
        f(7, a);
    }
    while (a['N' - 'A']) {
        ++res[9];
        f(9, a);
    }
    string ans = "";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < res[i]; ++j) {
            ans += i + '0';
        }
    }
    return ans;
    
}



int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
        std::cerr << i << endl;
	}
	return 0;
}
