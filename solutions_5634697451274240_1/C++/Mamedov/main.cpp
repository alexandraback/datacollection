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

int t, n, ans;
string s;
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("b_large_output.txt", "w", stdout);
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        cin >> s;
        s = s + '+';
        cout << "Case #" << cases << ": ";
        n = s.size();
        n--;
        while(n >= 0 && s[n] == '+')
            n--;
        ans = 0;
        while(n >= 0){
            if(s[n] != s[n + 1])
                ans++;
            n--;
        }
        cout << ans << endl;
    }
    return 0;
}
