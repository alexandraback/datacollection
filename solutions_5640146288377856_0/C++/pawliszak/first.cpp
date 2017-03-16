#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    for (int i=0; i < tests; i++) {
        int r,c,w;
        cin >> r;
        cin >> c;
        cin >> w;
        int result = r* (c/w);
        if ( c % w == 0) {
            result += w-1;
        }
        else {
            result += w;
        }
        cout << "Case #" << i+1 << ": " << result << endl;
    }

    return 0;
}
