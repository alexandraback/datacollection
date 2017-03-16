#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, t, n, i, j, num, aud;
    string tmp;
    cin >> t;
    for(a=0; a<t; a++) {
        cin >> n;
        cin >> tmp;
        num = 0;
        aud = 0;
        for(i=0; i<=n; i++) {
            if(num>=i) {
                num+=tmp[i]-'0';
            } else {
                aud+=i-num;
                num=i+tmp[i]-'0';
            }
        }
        cout << "Case #" << a+1 << ": " << aud << endl;
    }
    return 0;
}

