#include <iostream>

using namespace std;

bool range(int n, int a, int b) {
    return a <= n && n <= b;
}

int main() {
    int N;
    cin >> N;
    for(int no = 1; no <= N; no++) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if(range(1*1, a, b)) ans++;
        if(range(2*2, a, b)) ans++;
        if(range(3*3, a, b)) ans++;
        if(range(11*11, a, b)) ans++;
        if(range(22*22, a, b)) ans++;
        cout << "Case #" << no << ": " << ans << endl;
    }
}
