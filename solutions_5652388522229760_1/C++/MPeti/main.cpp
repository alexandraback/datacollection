#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string file;
    cin >> file;
    ifstream in(file.append(".txt"));
    ofstream out(file.append("-out.txt"));
    int T;
    in >> T;
    cout << T << endl;
    for (int t = 1; t <= T; t++)
    {
        int N;
        in >> N;
        if (N == 0)
        {
            out << "Case #" << t << ": INSOMNIA" << endl;
            continue;
        }
        bool D[10];
        for (int i = 0; i < 10; i++)
        {
            D[i] = false;
        }
        int l = 10;
        int i = 0;
        while(l > 0)
        {
            i++;
            int n = N*i;
            while(n > 0)
            {
                int d = n%10;
                if (!D[d])
                {
                    D[d] = true;
                    l--;
                }
                n /= 10;
            }
        }
        out << "Case #" << t << ": " << N*i << endl;
    }
}
