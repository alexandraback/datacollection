#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define mp make_pair
using namespace std;

const int maxn = 4000;

int d[10][maxn];
int mm, tofall;
int n0, k0;
int n, x, y;
int tc;
int aans[10][maxn];
int went[10][maxn];

string dict[521196];

int main()
{
    /*freopen("input.txt", "w", stdout);
    cout << 4 << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4000; j++)
        {
            cout << "a";
        }
        cout << endl;
    }
    return 0;
    */freopen("dict.txt", "r", stdin);
    for (int i = 0; i < 521196; i++)
    {
        cin >> dict[i];
    }
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (tc = 1; tc <= t; tc++)
    {
        cerr << tc << "\n";
        printf("Case #%d: ", tc);
        string s;
        cin >> s;
        int n = s.length();
        for (int z = 1; z <= 5; z++)
        {
            d[z][n] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int z = 1; z <= 5; z++)
            {
                d[z][i] = 1e9;
            }
            for (int j = 0; j < 521196; j++)
            {
                if (dict[j].length() > n - i) continue;
                bool ok = 1;
                int mist = 0;
                int l = dict[j].length();
                int last = -10;
                int first = -1;
                for (int z = 0; z <= min(5, l - 1); z++)
                {
                    if (dict[j][z] == s[i + z]) continue;
                    first = z;
                    break;
                }
                for (int z = 0; z < l; z++)
                {
                    if (dict[j][z] == s[i + z]) continue;
                    if (z - last < 5)
                    {
                        ok = 0; break;
                    }
                    last = z;
                    mist++;
                }
                if (!ok) continue;

                //update Answer
                if (first != -1)
                {
                    for (int z = max(5 - first, 0); z <= 5; z++)
                    {
                        if (d[z][i] > mist + d[min(5, i + l - last)][i + l])
                        {
                            aans[z][i] = min(5, i + l - last);
                            went[z][i] = j;
                        }
                        d[z][i] = min(d[z][i], mist + d[min(5, i + l - last)][i + l]);
                    }
                }
                else
                {
                    for (int z = 1; z <= 5; z++)
                    {
                        if (d[z][i] > d[min(5, z + l)][i + l])
                        {
                            aans[z][i] = min(5, z + l);
                            went[z][i] = j;
                        }
                        d[z][i] = min(d[z][i], d[min(5, z + l)][i + l]);
                    }
                }


            }
        }
        printf("%d\n", d[5][0]);

        /*int z = 5, i = 0;
        while (i != n)
        {
            cout << went[z][i] << " " << dict[went[z][i]] << "\n";
            i += dict[went[z][i]].length();
            z = aans[z][i];
        }*/
        //return 0;

    }


    return 0;
}
