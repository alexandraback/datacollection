#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
bool digits[12];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("Asmall.out", "w", stdout);
	int t; cin >> t;
	int T = t;
    ll ans = 0;
    int n; bool impossible;
	while(t--)
    {
        cin >> n; ans = n; impossible = false;
        memset(digits, false, sizeof(digits));
        if(n == 0) impossible = true;
        if(!impossible)
        {
            while(1)
            {
                bool used = true;
                ll tmp = ans;
                while(tmp)
                {
                    digits[tmp%10] = true;
                    tmp /= 10;
                }
                for(int i = 0; i < 10; i++)
                {
                    if(!digits[i])
                    {
                        used = false; break;
                    }
                }
                if(used) break;
                ans += n;
            }
        }
        cout << "Case #" << T-t << ": ";
        if(impossible)
        {
            cout << "INSOMNIA";
        }
        else
        {
            cout << ans;
        }
        cout << "\n";
    }
	return 0;
}

