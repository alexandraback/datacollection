#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
#define X first
#define Y second
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define bp __builtin_popcount
//////////////////////
string naive(string s){
    int n = s.size();
    string jav = "";
    for(int mask = 0; mask < (1<<n); mask++){
        string cur = "";
        for(int i=0; i<n; i++)
            if(mask & (1<<i))
                cur += s[i];
            else
                cur = s[i] + cur;
        jav = max(jav, cur);
    }
    return jav;
}
main(){
    freopen("AS.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for(int it=0; it<T; it++){
        cout << "Case #" << it+1 << ": ";
        string s;
        cin >> s;
        string cur = "";
        for(int j=0; j<s.size(); j++){
            string fi = s[j] + cur;
            string se = cur + s[j];
            cur = max(fi, se);
        }
        cout << cur << endl;
        if(cur != naive(s)){
            cout << "WA" << endl;
            cout << naive(s) << endl;
            cout << cur << endl;
            return 0;
        }
    }
}
