

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <utility>
#include <list>
#include <sstream>
#include <iostream>
#include <functional>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;




struct node{
    int w, e, s, d;
}x[10000];

bool cmp(node a, node b) {
    return a.d < b.d;
}

int hi[1000000];

int main()
{

      ifstream cin("C-small-attempt0.in");
    ofstream cout("b.txt");

    int t;

    cin >> t;

    int c = 1;


    while (t--)
    {

        int ans = 0, N;

        cin >> N;

        int k = 0;
        int d, n, w, e, s, dd, dp, ds;

        for (int i = 0; i < N; ++i) {

            cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;

            for (int j = 0; j < n; j++)
            {
                x[k].d = d + j * dd;
                x[k].s = s + j * ds;
                x[k].w = w + j * dp;
                x[k].e = e + j * dp;
                x[k].w *= 2;
                x[k].e *= 2;
                k++;
            }
        }

        sort(x, x + k, cmp);
        memset(hi, 0, sizeof(hi));

        //cout << k << endl;

       // for (int i = 0; i < k; i++)
       // {
         //   cout << x[i].d << " "<< x[i].w << " " << x[i].e << " " << x[i].s << endl;
       // }


        for (int i = 0; i <= x[k - 1].d; ++i) {

            for (int j = 0; j < k; j++)
                if (x[j].d == i) {

                    for (int l = x[j].w; l <= x[j].e; ++l)
                    {
                        if (hi[l + 500000] < x[j].s){
                            ans++;
                            break;
                        }
                    }

                }

            for (int j = 0; j < k; j++)
                if (x[j].d == i) {

                    bool ok = 0;

                    for (int l = x[j].w; l <= x[j].e; ++l)
                    {
                        if (hi[l + 500000] < x[j].s){
                            ok = 1;
                            break;
                        }
                    }

                    if (ok) {
                        for (int l = x[j].w; l <= x[j].e; ++l)
                        {
                            //if (hi[j + 500000] < x[j].s){
                            hi[l + 500000] = max(x[j].s, hi[l + 500000]);
                           // }
                        }
                    }
                }
        }

        cout << "Case #"<< c++ <<": " << ans << endl;
    }

    return 0;
}
