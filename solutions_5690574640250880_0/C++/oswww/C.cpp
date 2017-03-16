#define OSW2

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;



int main() {
    #ifdef OSW
    freopen("C:\\Users\\Osw\\Desktop\\in.txt", "r", stdin);
    #endif // OSW
    #ifdef OSW2
    freopen("C:\\Users\\Osw\\Desktop\\Attempt\\Google Code Jam\\Cin.txt", "r", stdin);
    freopen("C:\\Users\\Osw\\Desktop\\Attempt\\Google Code Jam\\c.txt", "w", stdout);
    #endif // OSW
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    int t=0;
    while (T-(t++)) {
        cout << "Case #" << t << ":" << endl;

        double R,C,M;
        cin >> R >> C >> M;
    #ifdef OSW
    cout << R << ' ' << C << ' ' << M << endl;
    #endif // OSW
        int free = R*C-M;
        int minRC = min(R,C);
        int flag = true;

        if (minRC==2 && free%2==1) flag = false;
        if ((free==2 || free==3 || free==5 || free==7) && minRC!=1) flag = false;
        if (1==free) flag = true;
        if (!flag) {
            cout << "Impossible" << endl;
            continue;
        }

        char space[200][200];
        for (int i=0; i!=R; ++i) {
            for (int j=0; j!=C; ++j) {
                space[i][j] = '.';
            }
        }
        space [0][0] = 'c';

        int r=R, c=C, m=M;
        while(m) {
            if (r>c && m>=c) {
                for (int i=0; i!=c; ++i) space[r-1][i] = '*';
                m -= c;
                --r;
            } else if (r<=c && m>=r){
                for (int i=0; i!=r; ++i) space[i][c-1] = '*';
                m -= r;
                --c;
            } else {
                int rr = r;
                int cc = c;

                while (m>0 && rr>2) {
                    space[rr-1][cc-1] = '*';
                    --rr;
                    --m;
                }
                rr = r;
                cc = c-1;
                while (m>0 && cc>2) {
                    space[rr-1][cc-1] = '*';
                    --cc;
                    --m;
                }
            }


        }


        for (int i=0; i!=R; ++i) {
            for (int j=0; j!=C; ++j) {
                cout << space[i][j];
            }
            cout << endl;
        }



    }
}

