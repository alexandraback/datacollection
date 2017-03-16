#include <iostream>
using namespace std;

long long tcase() {
    string name;
    int n;
    cin >> name >> n;
    long long res = (long long)name.length() * ((long long)name.length() + 1LL) / 2LL;
    long long last = 0LL;
    int cur = 0;
    for(int i = 0; i < name.length(); i ++) {
        switch(name[i]) {
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' :
                cur = 0;
                break;
            default:
                cur ++;
                if(cur >= n)
                    last = (long long)i - n + 2LL;
                break;
        }
        long long len = (long long)i - (long long)last + 1LL;
        res -= len;
    }
    return res;
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 1; i <= t; i ++)
        cout << "Case #" << i << ": " << tcase() << "\n";
}