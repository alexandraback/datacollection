#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
string words[521196];
int main()
{
    ifstream dict("dict.txt");
    for (int i=0;i<521196;i++) dict>>words[i];
    dict.close();
    sort(words,words+521196, [](const string& a, const string& b){return a.size()<b.size();});
    int t;
    cin >> t;
    for (int cases=1;cases<=t;cases++) {
        string s;
        cin >> s;
        int n =s.size();
        int cost[n+1][5];
        for (int i=0;i<5;i++)cost[0][i] = 0;
        for (int i=1;i<=n;i++) {
            for (int j=0;j<5;j++) {
                cost[i][j] = 1000000;
                for (auto w : words) {
                    if (w.size()>i) break;
                    int x = i-w.size();
                    int change = 0;
                    int changei = 0;
                    int prev = -1000;
                    for (int k=0;k<w.size();k++) {
                        if (s[x+k]!=w[k]) {
                            changei = max(changei,4-k);
                            if (x+k>i-1-j||k-prev<5) {
                                change = 10000000;
                                break;
                            }
                            prev = k;
                            change++;
                        }
                    }
                    if (change < 10000000) {
                        changei = max(0,changei);
                        cost[i][j] = min(cost[i][j],cost[i-w.size()][max(j-int(w.size()),changei)]+change);
                    }
                }
            }
        }
        int best = cost[n][0];
        for (int i=1;i<5;i++) best = min(best,cost[n][i]);
        cout << "Case #" << cases << ": " << best << endl;
    }
    return 0;
}
