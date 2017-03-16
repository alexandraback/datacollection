#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

int main()
{
    freopen("C-large.in", "r", stdin); freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qw = 1; qw <= T; ++qw){
        cout << "Case #" << qw <<": \n";
        int n, k;
        cin >> n >> k;
        int deg = n / 2 - 1;
        for(int msk = 0; msk < k; ++msk){
            cout << 1;
            for(int i = 0; i < deg; ++i){
                if((1 << i) & msk){
                    cout << "11";
                }
                else{
                    cout << "00";
                }
            }
            cout << 1 << " ";
            for(int i = 2; i <= 10; ++i){
                cout << i + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
