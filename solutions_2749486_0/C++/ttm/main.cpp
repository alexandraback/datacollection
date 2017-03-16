#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cstdint>

using namespace std;

int main(){
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
		cout << "Case #" << cas << ": ";
        int x, y;
        cin >> x >> y;
        if (x > 0) { for (int i = 0; i < x; ++i) cout << "WE"; }
		else { for (int i = 0; i < -x; ++i) cout << "EW"; }
        if (y > 0) { for (int i = 0; i < y; ++i) cout << "SN"; }
		else { for (int i = 0; i < -y; ++i) cout << "NS"; }
        cout << "\n";
	}
}
