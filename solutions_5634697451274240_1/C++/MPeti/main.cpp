#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string file;
    cin >> file;
    ifstream in(file);
    ofstream out(file.append("-out.txt"));
    int T;
    in >> T;
    for (int t = 1; t <= T; t++)
    {
        string S;
        in >> S;
        S.push_back('+');
        int c = 0;
        for (int i = 0; i < S.size()-1; i++)
        {
            if (S[i] != S[i+1])
                c++;
        }
        out << "Case #" << t << ": " << c << endl;
    }
}
