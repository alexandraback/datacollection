#include <iostream>
#include <vector>

using namespace std;

int A[20];

int T[20];

int K[300];

int n, k;

bool B[20];

bool OK = false;

int keys[20][300];

void gen(int p)
{
    if (p == n)
    {
        OK = true;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] + 1 << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!B[i] && K[T[i]])
        {
            K[T[i]]--;
            for (int j = 0; j < 300; j++)
                K[j] += keys[i][j];
            B[i] = true;
            A[p] = i;
            gen(p + 1);
            if (OK)
                return;
            K[T[i]]++;
            B[i] = false;
            for (int j = 0; j < 300; j++)
                K[j] -= keys[i][j];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int u = 0; u < t; u++)
    {
        if (u == 3 || u == 4 || u == 5 || u == 6)
            continue;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 300; j++)
                keys[i][j] = 0;
        for (int i = 0; i < 300; i++) K[i] = 0;
        for (int i = 0; i < 20; i++) B[i] = false;
        for (int i = 0; i < 20; i++) T[i] = -1;
        cin >> k >> n;
        for (int i = 0; i < k; i++)
        {
            int z;
            cin >> z;
            z--;
            K[z]++;
        }
        for (int i = 0; i < n; i++)
        {
            int kk, ll;
            cin >> kk >> ll;
            kk--;
            T[i] = kk;
            for (int j = 0; j < ll; j++)
            {
                int z = 0;
                cin >> z;
                z--;
                keys[i][z]++;
            }
        }
        OK = false;
        cout << "Case #" << u + 1 << ": ";
        gen(0);
        if (!OK)
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
