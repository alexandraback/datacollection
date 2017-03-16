#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int t, r, n, m, k;
int def[10], poss;
int pa[10];

int main()
{
    srand(time(0));
    cin >> t >> r >> n >> m >> k;

    cout << "Case #1:\n";
    for (int c = 0; c < r; c++)
    {
        for (int i = 0; i < 10; i++)
            def[i] = 0;
        poss = 0;
        for (int i = 0; i < k; i++)
            cin >> pa[i];
        for (int i = 0; i < k; i++)
        {
            int p = pa[i];
            int n5s = 0, n3s = 0;
            while (p % 5 == 0)
            {
                n5s++;
                p /= 5;
            }
            while (p % 3 == 0)
            {
                n3s++;
                p /= 3;
            }
            def[5] = max(def[5], n5s);
            def[3] = max(def[3], n3s);

            if (n5s + n3s == n)
                break;

            if (p != 1)
            {
                int left = n - n5s - n3s;
                if (left == 1)
                {
                    def[p] = 1;
                }
                else if (left == 2)
                {
                    if (p == 8)
                    {
                        def[2] = 1;
                        def[4] = 1;
                    }
                    else if (p == 16)
                    {
                        def[4] = 2;
                    }
                    else if (p == 2)
                    {
                        def[2] = max(def[2], 1);
                    }
                    else
                    {
                        poss = max(poss, 1);
                    }
                }
                else
                {
                    if (p == 8)
                    {
                        def[2] = 1;
                        poss = max(poss, 1);
                    }
                    else if (p == 16)
                    {
                        poss = max(poss, 1);
                        def[4] = 1;
                    }
                    else if (p == 32)
                    {
                        def[2] = 1;
                        def[4] = 2;
                    }
                    else if (p == 64)
                    {
                        def[4] = 3;
                    }
                }
            }
        }
        int tot = 0;
        for (int i = 2; i <= 5; i++)
        {
            tot += def[i];
        }
        for (int i = 2; i <= 5; i++)
        {
            for (int j = 0; j < def[i]; j++)
                cout << i;
        }
        if (tot == 2)
        {
            if (poss)
                cout << 4;
            else
                cout << (rand() % 4 + 2);
        }
        else if (tot == 1)
        {
            if (poss)
                cout << 22;
            else
                cout << (rand() % 4 + 2) << (rand() % 4 + 2);
        }
        else if (tot == 0)
        {
            cout << (rand() % 4 + 2) << (rand() % 4 + 2) << rand() % 4 + 2;
        }
        cout << '\n';
    }
    return 0;
}

