#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))), (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define R(i,a,b)  for (int i=a; i<=b; i++)
#define Re(i,a,b) for (int i=a; i>=b; i--)
#define tr(i,a) for (__typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define tes cout << "test" << endl, fflush(stdout);
#define cincout ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define print(_v) cout << #_v << " : "; for (auto _i : _v) cout << _i <<", "; cout << endl;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define x first
#define y second

#define mod 1000000007
#define inf 1000111222
#define eps 1e-9
#define endl "\n"

using namespace std;

typedef long long int64;
typedef pair<int,int> ii;

int T, n;

vector<int64> factorize(string s) {
    vector<int64> ans;
    R(i,2,10) {
        int64 angka = stoll(s,NULL,i);
        for (int64 j=3; j*j <= angka; j+=2)
            if (angka % j == 0) { ans.pb(j); break; }
    }

    return ans;
}

int main () {
    cincout;
    cin >> T;

    R(tc,1,T) {
        int n,l; cin >> n >> l;
        int64 angka = (1<<(n-1))+1;

        cout << "Case #" << tc << ":" << endl;

        while (l > 0) {
            string num = bitset<32>(angka).to_string().substr(32-n);

            vector<int64> v = factorize(num);

            if (sz(v) == 9) {
                cout << num; for (auto i : v) cout << " " << i; cout << endl;
                l--;
            }

            angka += 2;
        }
    }
}