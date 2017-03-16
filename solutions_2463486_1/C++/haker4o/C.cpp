#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

pair<ll, ll> genPalindromeSq(ll a) {
    string n;
    stringstream ss;
    ss<<a;
    ss>>n;
    string nrev = n;
    reverse(nrev.begin(), nrev.end());
    string p1 = n + nrev;
    string p2 = n + nrev.substr(1);
    ll n1, n2;
    sscanf(&p1[0], "%I64d", &n1);
    sscanf(&p2[0], "%I64d", &n2);
    return mp(n2*n2, n1*n1);
}

bool isPalindrome(ll a) {
    stringstream ss;
    ss<<a;
    string num;
    ss>>num;
    string numrev = num;
    reverse(numrev.begin(), numrev.end());
    return num == numrev;
}

int main() {
    freopen("C-large-1.in", "r", stdin);
    freopen("C-large-1.out", "w", stdout);
    ll i, j;
    int T, NT;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cout<<"Case #"<<T<<": ";
        ll a, b;
        cin>>a>>b;
        ll res = 0;
        for(i=1; ; ++i) {
            pair<ll, ll> cur = genPalindromeSq(i);
            if (cur.first > b && cur.second > b) break;
            if (cur.first >= a && cur.first <= b && isPalindrome(cur.first)) ++res;
            if (cur.second >= a && cur.second <= b && isPalindrome(cur.second)) ++res;
        }
        cout<<res<<endl;
    }
    return 0;
}
