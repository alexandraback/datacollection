#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int T;
int A,B;
int p[100] = {1, 2, 3, 11, 22};

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    fin>>T;
    for (int i = 0; i < T; ++i)
    {
        fin >> A >> B;
        int countit = 0;
        for (int j = 0; j < 5; j++)
        {
            int x = p[j] * p[j];
            if (x >= A && x <= B )
                ++countit;
        }
        fout << "Case #" << i + 1 << ": " << countit << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
