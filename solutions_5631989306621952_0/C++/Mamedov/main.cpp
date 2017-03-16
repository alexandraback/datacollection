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

int t;
string s, res;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        cin >> s;
        res = "";
        res = res + s[0];
        for(int i = 1; s[i] != '\0'; i++){
            if(s[i] >= res[0])
                res = s[i] + res;
            else
                res = res + s[i];
        }
        cout << "Case #" << cases << ": ";
        cout << res << endl;
    }

    return 0;
}
