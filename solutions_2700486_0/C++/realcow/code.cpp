#include <cstdio>
#include <iostream>
#include <tchar.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int1024_t combination[1001][1001]; // nCr -> combination[n][r] 
void init_combination() {
    for (int i = 0; i <= 1000; i++) {
        combination[i][0] = 1;
        for (int j = 1; j <= i; j++) 
            combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
    }
}

int f(int n) {return n * (2 + (n - 1) * 4) / 2;}
int _tmain(int argc, TCHAR* argv[])
{
    int i, j, k, pn = 0;
    int n, x, y;
    scanf("%*d");
    init_combination();
    while (3 == scanf("%d%d%d", &n, &x, &y)) {
        pn++;
        if (pn == 7) 
            pn = pn;
        for(i = 1; f(i) <= n; i++);
        int l = i - 2;
        int myl = (x + y) / 2;
        if (myl <= l) {
            printf("Case #%d: 1.0\n", pn);
            continue;
        }
        else if (myl > l + 1)
        {
            printf("Case #%d: 0.0\n", pn);
            continue;
        }
        else 
        {
            int m = n - f(l + 1);
            int needblock = y + 1;

            if (m < needblock)
            {
                printf("Case #%d: 0.0\n", pn);
                continue;
            }
            int t = f(l + 2);
            if (needblock == l + 3 && t != n)
            {
                printf("Case #%d: 0.0\n", pn);
                continue;
            }

            int1024_t sum = 1, p = 0;
            sum <<= m;
            for (i = needblock; i <= m; i++) {
                p += combination[m][i];
            }
            int1024_t v = p * 10000000 / sum;
            
            printf("Case #%d: 0.", pn);
            cout << v << endl;
        }
    }	
}