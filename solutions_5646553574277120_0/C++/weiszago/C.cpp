#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int c, d, v;

int penz[100];
bool kif[100][1000];

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("Cki.txt", "w", stdout);
    int t;
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >>c>>d>>v;
        for (int i=1;i<=d;i++) {
            cin >> penz[i];
        }

        for (int i=0;i<=d;i++) for (int j=0;j<=v;j++) kif[i][j]=false;
        kif[0][0]=true;
        for (int i=1;i<=d;i++) {
            kif[i][0]=true;
            for (int j=1;j<=v;j++) {
                kif[i][j]=kif[i-1][j];
                for (int k=1;k<=c;k++) {
                    if (j-k*penz[i]>=0 && kif[i-1][j-k*penz[i]]) kif[i][j]=true;
                }
            }
        }
        int mo=0;
        for (int i=1;i<=v;i++) {
            if (!kif[d][i]) {
                mo++;
                for (int j=v;j>=1;j--) {
                    for (int k=1;k<=c;k++) {
                        if (j-k*i>=0 && kif[d][j-k*i]) kif[d][j]=true;
                    }
                }
            }
        }

        cout << "Case #" << tt<< ": "<<mo<<endl;
    }
    return 0;
}
