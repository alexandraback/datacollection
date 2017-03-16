#include <bits/stdc++.h>

#define all(c) c.begin(),c.end()
#define ll long long
#define ii pair <ll ,ll>
#define iii pair <int, ii >
#define vi vector <int>
#define vii vector < ii >
#define viii vector < iii >
#define oo numeric_limits<ll>::max()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MAXN 100000

using namespace std;

int main()
{
    freopen("input.in","r+",stdin);
    freopen("output.txt","w+",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int Smax;
        char c;
        int K;
        int standing = 0;
        int needed = 0;
        cin >> Smax;
        for(int i=0;i<=Smax;i++){
            cin >> c;
            K = c-'0';
            if(standing<i)
                needed = max(needed,i-standing);
            standing += K;
        }
        cout << "Case #" << t << ": " << needed << endl;
    }
    return 0;
}
