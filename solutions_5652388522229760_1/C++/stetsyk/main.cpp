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
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qw = 1; qw <= T; ++qw){
        int n;
        cin >> n;
        if(n == 0){
            cout << "Case #" << qw <<": " << "INSOMNIA" << "\n";
            continue;
        }
        set<int> s;
        int nn = 0;
        do{
            nn += n;
            int tmp = nn;
            while(tmp > 0){
                s.insert(tmp % 10);
                tmp /= 10;
            }
        }while(s.size() != 10);
        cout << "Case #" << qw <<": " << nn << "\n";
    }
    return 0;
}
