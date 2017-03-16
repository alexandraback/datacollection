#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int t, num, a[5][5];

void solve(int x) {
     getchar();
     bool aw = false, bw = false;
     int blank = 0;
     for (int i = 1; i <= 4; i++) {
         for (int j = 1; j <= 4; j++) {
             char d = getchar();
             if (d == 'X') a[i][j] = 1;
             else if (d == 'O') a[i][j] = 2;
             else if (d == 'T') a[i][j] = 3;
             else a[i][j] = 4, blank++;
         }
         getchar();
     }
     for (int i = 1; i <= 4; i++) {
         bool flag = true;
         for (int j = 1; j <= 4; j++)
         if (a[i][j] == 2 || a[i][j] == 4) flag = false;
         if (flag) aw = true;
     }
     for (int i = 1; i <= 4; i++) {
         bool flag = true;
         for (int j = 1; j <= 4; j++)
         if (a[j][i] == 2 || a[j][i] == 4) flag = false;
         if (flag) aw = true;
     }
     
     bool flag = true;
     for (int i = 1; i <= 4; i++)
         if (a[i][i] == 2 || a[i][i] == 4) flag = false;
     if (flag) aw = true;
     
     flag = true;
     for (int i = 1; i <= 4; i++)
         if (a[i][4 - i + 1] == 2 || a[i][4 - i + 1] == 4) flag = false;
     if (flag) aw = true;
     
     for (int i = 1; i <= 4; i++) {
         bool flag = true;
         for (int j = 1; j <= 4; j++)
         if (a[i][j] == 1 || a[i][j] == 4) flag = false;
         if (flag) bw = true;
     }
     for (int i = 1; i <= 4; i++) {
         bool flag = true;
         for (int j = 1; j <= 4; j++)
         if (a[j][i] == 1 || a[j][i] == 4) flag = false;
         if (flag) bw = true;
     }
     
     flag = true;
     for (int i = 1; i <= 4; i++)
         if (a[i][i] == 1 || a[i][i] == 4) flag = false;
     if (flag) bw = true;
     
     flag = true;
     for (int i = 1; i <= 4; i++)
         if (a[i][4 - i + 1] == 1 || a[i][4 - i + 1] == 4) flag = false;
     if (flag) bw = true;
     
     if (aw) cout << "Case #" << x << ": X won\n";
     else if (bw) cout << "Case #" << x << ": O won\n";
     else if (!blank) cout << "Case #" << x << ": Draw\n";
     else cout << "Case #" << x << ": Game has not completed\n";
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t; while (t--) solve(++num);
}
