#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int K,C,S;
        cin >> K >> C >> S;
        cout << "Case #" << tc << ":";
        if (C == 1) {
            if (S<K) {
                cout << " IMPOSSIBLE";
            } else {
                for (int i = 1; i <= K; ++i)
                    cout << ' ' << i;
            }
        }
        else if (S<((K%2)?(K/2+1):(K/2))) {
            cout << " IMPOSSIBLE";
        }
        else {
            int i=1;
            while(i<K) {
                cout << ' ' << (i-1)*K+i+1;
                i+=2;
            }
            if (i == K) {
                cout << ' ' << i;
            }
        }
        cout << endl;
    }
    return 0;
}
