#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        int r,c,w;
        cin >> r >> c >> w;

        int result = 0;
        if(r > 1) {
            result += c/w * (r-1);
        }
        if(c/w * w == c) {
            result += c/w - 1;
        } else {
            result += c/w;
        }
        result += w;

        cout << "Case #" << i << ": ";
        cout << result;
        cout << endl;
    }

    return 0;
}

