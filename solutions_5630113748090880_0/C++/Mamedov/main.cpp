#include <bits/stdc++.h>
#define maxx 100005
#define inf 2000000000
#define mod 1000000007
#define pii pair<int,int>
#define piii pair<pii,pii>
#define pli pair<long long,int>
#define f first
#define s second
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%lld",&x)
#define inch(x) scanf("%s",x)
#define indo(x) scanf("%lf",&x)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int t, n, x;
int h[3000];
vector<int>v;
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        cin >> n;
        memset(h, 0, sizeof(h));
        v.clear();
        for(int i = 1; i < n + n; i++)
            for(int j = 1; j <= n; j++){
                    cin >> x;
                    h[x]++;
            }
        for(int i = 1; i <= 2500; i++)
            if((h[i] & 1))
                v.pb(i);
        cout << "Case #" << cases << ": ";
        for(int i = 0; i < v.size() - 1; i++)
            cout << v[i] << " ";
        cout << v[v.size() - 1] << endl;
    }

    return 0;
}
