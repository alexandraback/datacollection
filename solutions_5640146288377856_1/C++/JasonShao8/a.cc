#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int dp[21][21];
    for (int c = 0; c <= 20; c++) {
        for (int w = 0; w <= 20; w++) {
            dp[c][w] = 1 << 25;
        }
    }
    for (int c = 0; c <= 20; c++) {
        dp[c][c] = c;
    }

    for (int c = 0; c <= 20; c++) {
        dp[0][c] = 0;
        dp[c][0] = 0;
        for (int w = c + 1; w <= 20; w++) {
            dp[c][w] = 0;
        }
    }

    for (int c = 0; c <= 20; c++) {
        for (int w = 0; w < c; w++) {
            int min = dp[c][w];
            for (int ind = 1; ind <= c; ind ++) {
                int temp;
                //miss
                temp = 1 + dp[ind-1][w] + dp[c-ind][w];

                //hit
                int temp2 = 0;
                if (ind == 1 || ind == c) 
                    temp2 = w;
                else
                    temp2 = w + 1;

                int temp3 = max(temp, temp2);
                if (temp3 < min) 
                    min = temp3;
            }
            dp[c][w] = min;
        }
    }

//    for (int i = 0; i <= 20; i++)
//            for (int j = 0; j < 21; j++) 
//                    cout << i << " " << j << " " << dp[i][j] << endl;

    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        int r, c, w; cin >> r >> c >> w;
        cout << "Case #" << test << ": " << dp[c][w] + (r - 1) * (c / w) << endl; 
    }
}
