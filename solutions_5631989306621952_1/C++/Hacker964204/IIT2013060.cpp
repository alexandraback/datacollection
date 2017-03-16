#include <bits/stdc++.h>
#define lli long long int
#define s(x) scanf("%lld", &x);
lli mod = 1000000007;
using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    lli i, l, t, ta;

    string s, p;

    s(t);
    ta = 1;
    while(t--) {
        s.clear();
        cin>>s;
        l = s.length();
        std::string::iterator it;
        p = p + s[0];
        for (i = 1; i < l; i++) {
            if ((int)s[i] >= (int)p[0]) {
                it = p.insert(p.begin(), s[i]);
            } else {
                p = p + s[i];
            }
        }
        cout<<"Case #"<<ta<<": "<<p<<endl;
        p.clear();
        ta++;
    }

    return 0;
}
