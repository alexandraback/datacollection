#include <bits/stdc++.h>
using namespace std;
#define W << " " <<
const int MOD = (int) 1e9 + 7;
const double eps = 1e-8, pi = acos(-1);
void MAIN();
int main(){
    //freopen("input.txt", "r", stdin);
    ios:: sync_with_stdio(false); cin.tie(0);
    MAIN();
    return 0;
}


void MAIN() {
    int nTest;
    cin >> nTest;
    for (int cs = 1; cs <= nTest; cs ++) {
        int n;
        cin >> n;
        vector <int> cnt(2501, 0);
        for (int i = 0; i < 2*n-1; i ++) {
            for (int j = 0; j < n; j ++) {
                int x;
                cin >> x;
                cnt[x] ++;
            }
        }
        vector <int> v;
        for (int i = 0; i < cnt.size(); i ++)   if (cnt[i] % 2)
            v.push_back(i);

        assert(v.size() == n);
        cout << "Case #" << cs << ":";
        for (int i = 0; i < n; i ++)    cout << " " << v[i];
        cout << "\n";


        cerr << "Case #" << cs << ":";
        for (int i = 0; i < n; i ++)    cerr << " " << v[i];
        cerr << "\n";
    }
}
