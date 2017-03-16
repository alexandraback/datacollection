#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int cuenta [1000005];
char cad[1000005];

int main ()
{

    int T;
    int n;


    freopen ("A-large.in","r",stdin);
    freopen ("a.out","w",stdout);

    cin >> T;

    for (int tc = 0; tc < T; tc ++)
    {
        scanf ("%s %i",cad , &n);
        long long ans = 0;
        int size = strlen (cad);
        int last = -1  ;
        for (int i = 0; i < size; i ++)
        {
            if (cad [i] != 'a' && cad [i]!= 'e' && cad [i] != 'i' && cad [i] != 'o' && cad [i] != 'u')
            {
                if (i > 0)
                    cuenta [i] = cuenta [i - 1] + 1;
                else
                    cuenta [i] = 1;
            }
            else
            {
                cuenta [i] = 0;
            }

            if (cuenta [i] < n)
            {
                if (last != -1)
                {
                    ans += last + 1;
                }
            }else
            {
                last = (i - n) + 1;
                ans += last + 1;
            }
        }

        cout << "Case #" << tc + 1 << ": " << ans << endl;


    }

    return 0;
}










