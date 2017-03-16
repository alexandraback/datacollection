#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define MAX 1000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> dp;

int revnum(int n) {
    stringstream ss;
    ss << n;
    string s = ss.str();
    reverse(s.begin(), s.end());
    int ans;
    istringstream (s) >> ans;
    return ans;
}

int cnt(int n) {
    if (n==1) {
        dp[1] = 1;
        return 1;
    }

    if (dp[n] >= 0) {
        return dp[n];
    }

    int ans = 1+cnt(n-1);
    if ((revnum(revnum(n)) == n) && (revnum(n) < n)) {
        if (cnt(revnum(n)) < cnt(n-1)) {
            ans = 1 + cnt(revnum(n));
        }
    }

    dp[n] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ifstream fin ("counter.in");
    ofstream fout ("counter.out");

    int t;
    fin >> t;

    //cout << revnum(1457);

    dp.resize(1000001);
    for (int i = 0; i <= 1000000; i++) {
        dp[i] = -1;
    }

    int tmp;
    for (int i = 0; i <= MAX; i++) {
        if (i%100000 == 0) {
            cout << i << endl;
        }
        tmp = cnt(i);
    }

    //int tmp;
    for (int test = 0; test < t; test++) {
        fin >> tmp;
        fout << "Case #" << (test+1) << ": " << cnt(tmp) << "\n";
        //cout << revnum(tmp) << endl;
    }

    return 0;
}
