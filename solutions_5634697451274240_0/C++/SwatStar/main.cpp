#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int cases, len, i, j, k, count;
    char array[101], state;
    ifstream fin;
    fin.open ("input.txt");
    ofstream fout;
    fout.open ("output.txt");
    fin >> cases;
    for (i = 0; i < cases; i++)
    {
        len = 0;
        state = '-';
        count = 0;
        fin >> array;
        for (j = 0; array[j] != 0; j++)
            len++;
        for (j = len - 1; j >= 0; j--)
        {
            if (array[j] == state)
            {
                for (k = 0; k < len; k++)
                    if (array[k] == '-')
                        array[k] = '+';
                    else
                        array[k] = '-';
                count++;
            }
        }
        fout << "Case #" << i + 1 << ": " << count << endl;
    }
    fin.close ();
    fout.close ();
    return 0;
}
