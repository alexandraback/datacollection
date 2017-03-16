#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int MOD = 1000000007;
int a[5][5] = {
    {0 , 0 , 0 , 0 , 0},
    {0 , 1 , 2 , 3 , 4},
    {0 , 2 , -1 , 4 , -3},
    {0 , 3 , -4 , -1 , 2},
    {0 , 4 , 3 , -2 , -1}
};
void mut (int &p , int b) {
    if (p < 0) p = -1 * a[-p][b];
    else p = a[p][b];
}
int main () {
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;
    cin >> t;
    while (t --) {
        int l , x;string s , e = "";
        cin >> l >> x >> s;
        for (int i = 0 ; i < x ; i ++)
            e += s;
        int now = 1 , first = 0 , second = 0;
        for (int i = 0 ; i < l * x ; i ++) {
            int p = 2;
            if (e[i] == 'j') p = 3;
            else if (e[i] == 'k') p = 4;
            mut (now , p);
            if (now == 2) {
                first = 1;
            }
            if (now == 4) {
                if (first == 1) second = 1;
            }
        }
        cout << "Case #" << ++ cas << ": ";
        if (first && second && now == -1) {
            puts ("YES");
        }
        else puts ("NO");
    }
    return 0;
}