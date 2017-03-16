#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("1.in");
    ofstream fout("1.out");
    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        fout << "Case #" << i + 1 << ": ";
        int n;
        fin >> n;
        int ar[3000] = {};
        for (int j = 0; j < 2 * n - 1; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int x;
                fin >> x;
                ar[x]++;
            }
        }
        for (int k = 0; k < 3000; k++)
            if (ar[k] % 2 != 0)
                fout << k << " ";
        fout << "\n";
    }
    //cout << "Hello World!" << endl;
    return 0;
}

