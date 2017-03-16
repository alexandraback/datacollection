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

main(){
    freopen("BL.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    for(int it=0; it<T; it++){
        cout << "Case #" << it+1 << ": ";
        int n;
        cin >> n;
        vector<int>v;
        for(int i=1; i<n*2; i++){
            for(int j=0; j<n; j++){
            int x;
            cin >> x;
            v.push_back(x);
            }
        }
        sort(all(v));
        vector<int>ans;
        for(int i=0; i<v.size(); i++){
            if(!i || v[i] != v[i - 1]){
                int cnt = 0;
                for(int j=i; j<v.size() && v[j] == v[i]; j++) cnt++;
                if(cnt & 1) ans.push_back(v[i]);
            }
        }
        sort(all(ans));
        for(int i : ans)
            cout << i << " ";
        cout << endl;
    }
}
