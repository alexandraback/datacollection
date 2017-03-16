#include<iostream>
#include<vector>
#include<string>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int t = 0; t<T; ++t) {
        int m;
        string a;
        cin >> m;
        cin >> a;
        int s = 0, v = 0;
        for (int i = 0; i<=m; ++i) {
            int x = a[i] - '0';
            int y = max(0,i-s);
            s += x;
            v += y;
            s += y;
        }
        cout << "Case #" << t+1 << ": " << v << "\n";
    }
	return 0;
}
