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
#define DOWN(i,a,b) for(int i=(a); i >=(b); i--)
#define X first
#define Y second
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second
using namespace std;

int n;
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
int main() {
    std::ios::sync_with_stdio(false);
    freopen("C-small.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest,x;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        cin >> x;

        cin >> orig_s;
        s = "";
        FOR(i,1,x) s += orig_s;
        n = s.size();
        memset(isI, false,sizeof(isI));
        memset(isK, false,sizeof(isK));
        if (s[0] == 'i') isI[0] = true;
        if (s[n-1] == 'k') isK[n-1] = true;

        Data prod = Data(1,s[0]);
        FOR(i,1,n-1) {
            prod = mul(prod, Data(1,s[i]));
            if (prod == Data(1,'i')) isI[i] = true;
        }

        prod = Data(1,s[n-1]);
        DOWN(i,n-2,0) {
            prod = mul(Data(1,s[i]), prod);
            if (prod == Data(1,'k')) isK[i] = true;
        }

        if (prod != Data(-1, '1')) cout << "NO" << endl;
        else  {
            DOWN(i,n-2,0) isK[i] = isK[i+1] ? true : isK[i];
            bool found = false;
            FOR(i,0,n-3) {
                if (isI[i] && isK[i+2]) {
                    found = true;
                    cout << "YES" << endl;
                    break;
                }
            }
            if (!found)
            cout << "NO" << endl;
        }


    }
    return 0;
}

