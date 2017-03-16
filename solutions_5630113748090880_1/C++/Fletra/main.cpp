#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp(a,b) make_pair(a,b)
#define F first
#define S second

#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define eps 1e-8
#define inf (int)(1e9+7)
#define infll (ll)(1e18+3)
#define sz(x) ((int)x.size())

typedef long long ll;
typedef  double ld;
typedef vector < ll > vll;
typedef vector < int > vi;
typedef pair < ll, ll > pll;
typedef pair < int, int > pii;
typedef int huint;

const ld PI = acosl(-1);


bool comp(vi &a, vi &b) {
    for (int i = 0; i<sz(a); ++i) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return true;
}

vi getLongestCommonSubsequence(const vi& a, const vi& b)
{
    vector<vector<int> > max_len;
    max_len.resize(a.size() + 1);
    for(int i = 0; i <= static_cast<int>(a.size()); i++)
        max_len[i].resize(b.size() + 1);
    for(int i = static_cast<int>(a.size()) - 1; i >= 0; i--)
    {
        for(int j = static_cast<int>(b.size()) - 1; j >= 0; j--)
        {
            if(a[i] == b[j])
            {
                max_len[i][j] = 1 + max_len[i+1][j+1];
            }
            else
            {
                max_len[i][j] = max(max_len[i+1][j], max_len[i][j+1]);
            }
        }
    }
    vi res;
    for(int i = 0, j = 0; max_len[i][j] != 0 && i < static_cast<int>(a.size()) && j < static_cast<int>(b.size()); )
    {
        if(a[i] == b[j])
        {
            res.push_back(j);
            i++;
            j++;
        }
        else
        {
            if(max_len[i][j] == max_len[i+1][j])
                i++;
            else
                j++;
        }
    }
    return res;
}


int main() {
#ifdef DEBUG
    freopen("/Users/rzmn/Documents/acm/acm/input.txt", "r", stdin);
    freopen("/Users/rzmn/Documents/acm/acm/output.txt", "w", stdout);
#else
    //freopen("gunman.in", "r", stdin);
    //freopen("gunman.out", "w", stdout);
#endif
    cout.precision(10);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    
    
    int Tcase; cin >> Tcase;
    for (int test = 1; test <= Tcase; ++test) {
        int n; cin >> n;
        map<int, int> m;
        for (int i = 0; i<n*2-1; ++i) {
            int t;
            for (int j = 0; j < n; j++){
                cin >> t; m[t]++;
            }
        }
        set<int> st;
        for (auto i = m.begin(); i != m.end(); ++i)
            if (i->S & 1) st.insert(i->F);
        cout << "Case #" << test << ": ";
        for (int i : st) cout << i << ' ';
        cout << '\n';
        
    }
    
    
    
    
    
    
#ifdef DEBUG
    cerr << "\n == TIME : " << clock() / ld(CLOCKS_PER_SEC) << " == " << endl;
#endif
}