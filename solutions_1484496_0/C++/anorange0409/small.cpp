#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 50;
const int M = 1050000;
int f[M], a[N], two[N], n;
vector < pair<int, int> > s;
void pt(int p, int q){
    int k = 0;
    for (int i = 0; i < n; i++) if ( (p & two[i]) > 0){
        if (!k) cout << a[i];
        else cout << " " << a[i];
        k = 1;
    }
    k = 0;
    for (int i = 0; i < n; i++) if ( (q & two[i]) > 0){
        if (!k) cout << a[i];
        else cout << " " << a[i];
        k = 1;
    }
}
void solve(){
    s.clear();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < two[n] - 1; i++)
    for (int j = 0; j < n; j++) if ( (i & two[j]) > 0 ){
        f[i] = f[i - two[j]] + a[j];
        s.push_back( make_pair(f[i], i));
    }
    sort(s.begin(), s.end());
    int i = 0;
    while (i < s.size()){
        int j = i;
        while ( j + 1 < s.size() && s[j+1].first == s[i].first) j++;
        for (int p = i; p <= j; p++)
            for (int q = p + 1; q <= j; q++)
                if ( (s[p].second && s[q].second) == 0) {
                    pt(s[p].second ,s[q].second);
                    return;
                }
        i = j + 1;
    }
    cout << "Impossible" << endl;
}

int main(){
    freopen("1.in", "r", stdin);
    two[0] = 1;
    for (int i = 1; i <= 20; i++)
        two[i] = two[i-1] * 2;
    int T;cin >> T;
    for (int i = 1; i <= T; i++){
        printf("Case #%d:\n", i);
        solve();
    }
}
