#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


set<int> nums;
vector<int64> ans;

void process_num(string s) {
    int num = atoi(s.c_str());
    if (num > 1000*1000*10)
        return;
    nums.insert(num);
}

bool palindrome(int64 n) {
    char buf[20];
    sprintf(buf, "%I64d", n);
    string s = buf;
    forn(i, s.length())
        if (s[i] != s[s.length()-1-i])
            return false;
    return true;
}

void precalc() {
    fore(i,1,10001) {
        char buf[20];
        sprintf(buf, "%d", i);
        string s = buf;
        
        string s2 = s;
        reverse(all(s2));

        process_num(s + s2);
        s2.erase(0, 1);
        process_num(s + s2);
    }

    vector<int> vnums(all(nums));
    for (size_t i = 0; i < vnums.size(); ++i) {
        int64 sq = int64(vnums[i]) * vnums[i];
        if (palindrome(sq))
            ans.push_back(sq);
    }
}


int64 a, b;

void read() {
    cin >> a >> b;
}

void solve() {
    cout << int(upper_bound(all(ans), b) - lower_bound(all(ans), a)) << endl;
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

    precalc();

	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		if (! cin)  throw;
		printf ("Case #%d: ", tt+1);
		solve();
	}
}