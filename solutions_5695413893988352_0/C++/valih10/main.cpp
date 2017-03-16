#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

ofstream out("tttt");

char na[4], nb[4], a[4], b[4], nn[4];
int n;

int ab(int a) {
    return a > 0 ? a : -a;
}

bool ver(int nr,  char a[]) {
    if(n == 2 && nr > 99)
        return 0;
    if(n == 1 && nr > 9)
        return 0;

    if(nr % 10 != a[n - 1] - '0' && a[n - 1] != '?')
        return 0;

    if(n > 1 && (((nr / 10) % 10) != a[n - 2] - '0' && a[n - 2] != '?'))
        return 0;


    if(n > 2 && (nr / 100 != a[n - 3] - '0' && a[n - 3] != '?'))
        return 0;

    return 1;
}

int sol() {
    int i, j, smin = 1000000, n1, n2;

    cin >> a >> b;

    n = strlen(a);

    for(i = 0; i <= 999; ++i) if(ver(i, a)) {

        for(j = 0; j <= 999; ++j) if(ver(j, b)) {


            int aa = ab(i - j);

            if(aa < smin || (aa == smin && i < n1) | (aa == smin && i == n1 && j < n2)) {
                smin = ab(i - j);

                n1 = i; n2 = j;

                na[2] = i % 10 + '0';
                na[1] = (i / 10) % 10 + '0';
                na[0] = i / 100 + '0';


                nb[2] = j % 10 + '0';
                nb[1] = (j / 10) % 10 + '0';
                nb[0] = j / 100 + '0';
            }
        }
    }

    out << na + 3 - n << " " << nb + 3 - n;
}

int main() {
    freopen("ttt", "r", stdin);
    //freopen("tttt", "w", stdout);

    int t, a = 0;
    cin >> t;

    while(t--) {
        ++a;
        out << "Case #" << a << ": ";
        sol();
        out << "\n";

        printf("Test %d\n", a);
    }

    return 0;
}
