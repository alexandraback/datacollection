#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int t;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        int sum = 0;
        bool a[10] = {};
        int n;
        fin >> n;
        int nn = n;

        if (n == 0)
        {
            fout << "Case #" << i + 1 << ": " << "INSOMNIA" << '\n';
            continue;
        }
        int x = n;
        while (!(sum == 45 && a[0]))
        {
            while (x != 0)
            {
                if (!a[x % 10])
                {
                    a[x % 10] = true;
                    sum += x % 10;
                }
                x /= 10;
            }
            if ((sum == 45 && a[0]))
                break;
            nn += n;
            x = nn;
        }
        fout << "Case #" << i + 1 << ": " << nn << '\n';
    }

    return 0;
}

