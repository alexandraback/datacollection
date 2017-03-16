#include <bits/stdc++.h>
#define lli long long int
#define s(x) scanf("%lld", &x);
lli mod = 1000000007;
using namespace std;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    lli i, l, t, ta, a[2505], mi, ma, n, j;

    //string s, p;

    s(t);
    ta = 1;
    while(t--) {
        vector<lli>v;
        mi = INT_MAX;
        ma = INT_MIN;
        for (i = 0; i < 2505; i++) {
            a[i] = 0;
        }
        cin>>n;
        for (i = 0; i < 2 * n - 1; i++) {
            for (j = 0; j < n; j++) {
                cin>>l;
                ma = max(ma, l);
                mi = min(mi, l);
                a[l]++;
            }
        }

        for (i = mi; i <= ma; i++) {
            if (a[i] % 2 != 0) {
                v.push_back(i);
            }
        }


        cout<<"Case #"<<ta<<": ";
        for (i = 0; i < v.size(); i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        v.clear();
        ta++;
    }

    return 0;
}
