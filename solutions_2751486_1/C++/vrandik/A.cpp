#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

long long solve() 
{
    long long ans = 0;
    int gc = 0;
    int g1c = 0;
    int gs = 0;
    int lasts = -1;
    string s;
    cin >> s;
    int n;
    cin >> n;
//    cout << n;
    int l = s.length();
    for (int i = 0; i < l; ++i) {
        if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')) {
            gs++;
        } else {
            gs = 0;
        }

        if (gs >= n) 
        {
            lasts = i + 1;
        }

//        cout << lasts << " " << gs << endl;

        if (lasts > 0) {
            ans += lasts - n + 1;
        }
    }

    return ans;   
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}