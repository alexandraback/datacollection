#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <cstdio>
#define FOR(i,a,b) for(int i=(a);i<=(b); i++)
#define FR(i,b) for(int i=0; i<(b);i++)
#define DR(i,b) for(int i=(b)-1; i>=0;i--)
#define DOWN(i,a,b) for(int i=(a); i >=(b); i--)
#define X first
#define Y second
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second
using namespace std;

int n;
long long x;
string s, orig_s;
bool isI[20000], isK[20000];
struct Data {
    int sign;
    char kt;
    Data() {}
    Data(int sign, char kt):sign(sign),kt(kt) {}

    bool operator == (Data q) {
        return sign == q.sign && kt == q.kt;
    }
    bool operator != (Data q) {
        return sign != q.sign || kt != q.kt;
    }
};
Data mul(char x, char y) {
    if (x == '1') {
        if (y == '1') return Data(1,'1');
        if (y == 'i') return Data(1,'i');
        if (y == 'j') return Data(1,'j');
        if (y == 'k') return Data(1,'k');
    } else if (x == 'i') {
        if (y == '1') return Data(1,'i');
        if (y == 'i') return Data(-1,'1');
        if (y == 'j') return Data(1, 'k');
        if (y == 'k') return Data(-1,'j');
    } else if (x == 'j') {
        if (y == '1') return Data(1,'j');
        if (y == 'i') return Data(-1,'k');
        if (y == 'j') return Data(-1,'1');
        if (y == 'k') return Data(1,'i');
    } else if (x == 'k') {
        if (y == '1') return Data(1,'k');
        if (y == 'i') return Data(1,'j');
        if (y == 'j') return Data(-1,'i');
        if (y == 'k') return Data(-1,'1');
    }
}
Data mul(Data x, Data y) {
    Data z = mul(x.kt, y.kt);
    return Data(z.sign * x.sign * y.sign, z.kt);
}

long long FindSmallestI() {
    s = "";
    FOR(i,1,min(x,8LL)) s += orig_s;

    Data prod = Data(1,'1');
    FR(i,s.size()) {
        prod = mul(prod, Data(1, s[i]));
        if (prod == Data(1,'i')) return i;
    }
    return 1000000000000000000LL;
}

long long FindLargestK() {
    s = "";
    FOR(i,1,min(x,8LL)) s += orig_s;
    long long maxId = (long long)x*n-1;

    Data prod = Data(1,'1');
    DR(i,s.size()) {
        prod = mul(Data(1, s[i]),prod);
        if (prod == Data(1,'k')) return maxId;
        maxId--;
    }
    return -1000000000000000000LL;
}

Data SingleData;
Data POW(Data x, long long y) {
    if (y == 1) return x;
    Data u = POW(x, y / 2);
    u = mul(u,u);
    if (y % 2 == 1) return mul(u,SingleData);
    else return u;
}
Data CalculateData() {
    s = orig_s;
    Data prod = Data(1,'1');
    FR(i,s.size()) prod = mul(prod, Data(1, s[i]));
    SingleData = prod;

    return POW(SingleData, x);
}
int main() {
    std::ios::sync_with_stdio(false);
    freopen("C-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest;
    cin >> ntest;

    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        cin >> x;
        cin >> orig_s;

        long long idx = FindSmallestI();
        long long idy = FindLargestK();
        Data res = CalculateData();
        if (res != Data(-1,'1')) cout << "NO" << endl;
        else {
            if (idx + 2 <= idy) cout << "YES" << endl;
            else cout << "NO" << endl;
        }


    }
    return 0;
}

