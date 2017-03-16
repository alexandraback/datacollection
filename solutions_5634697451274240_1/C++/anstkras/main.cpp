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
        string s;
        fin >> s;
        int count  = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '-')
            {
                count++;
                for (int j = i; j >= 0; j--)
                {
                    s[j] == '-' ? s[j] = '+' : s[j] = '-';
                }
            }
        }
        fout << "Case #" << i + 1 << ": " << count << '\n';
    }

    return 0;
}

