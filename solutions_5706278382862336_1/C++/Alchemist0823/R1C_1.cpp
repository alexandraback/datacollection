#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10;
int n, m;

int T,TT;

long long gcd ( long long a, long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b % a;  b = c;
  }
  return b;
}

int main()
{
    freopen("R1C_1_in.txt", "r", stdin);
    freopen("R1C_1_out.txt", "w", stdout);

    cin >> T;
    TT = 1;

    while(T) {

        long long a, b, kb, c;
        int k;
        scanf("%lld/%lld", &a, &b);

        //cout << a << ' ' << b << endl;
        bool t = false;
        if (a != 0)
        {

            c = gcd(a, b);

            a /= c;
            b /= c;

            kb = b;

            while(b > 1) {
                if(b % 2 == 0)
                {
                    b /= 2;
                }
                else {
                    t = true;
                    break;
                }
            }
            if(!t) {
                k = 0;
                while(kb > 1) {
                    if(kb % 2 == 0)
                    {
                        kb /= 2;
                        k ++;
                        if (a >= kb)
                            break;
                    }
                }
            }
        }
        else {
            t = true;
        }
        cout << "Case #" << TT << ": ";
        if (t)
            cout << "impossible" << endl;
        else
            cout << k << endl;
        T --;
        TT ++;
    }

    return 0;
}

