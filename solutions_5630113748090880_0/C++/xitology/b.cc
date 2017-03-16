
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t ++) {
        int N;
        vector<int> Hs(2501, 0);
        cin >> N;
        for (int k = 0; k < N*(2*N-1); k ++) {
            int h;
            cin >> h;
            Hs[h] ++;
        }
        vector<int> row;
        for (int h = 0; h <= 2500; h ++) {
            if (Hs[h] % 2 == 1) {
                row.push_back(h);
            }
        }
        cout << "Case #" << (t+1) << ":";
        for (const auto x : row) {
            cout << " " << x;
        }
        cout << '\n';
    }
}

