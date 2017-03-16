#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

int ProblemSolve(double n, int x)
{
    if(x > 40) return -1;
    if(n*2 == 1) return x;
    if(n*2 < 1) return ProblemSolve(n*2, x+1);
    if(ProblemSolve(n*2 - 1, x + 1) != -1) return x;
    return -1;

}

int main()
{
    ifstream in;
    in.open("in.txt");
    ofstream out;
    out.open("output.txt");


    int n; in >> n;
    for(int i = 0; i < n; ++i)
    {
        string input;
        in >> input;
        char ch;
        stringstream pStream;
        stringstream qStream;
        bool switcher = false;

        for(int j = 0; j < input.length(); ++j)
        {
            char ch = input[j];
            if(ch == '/')
                switcher = !switcher;
            else if(!switcher)
                pStream << ch;
            else
                qStream << ch;
        }
        long long int p, q;
        pStream >> p;
        qStream >> q;

        int answer = ProblemSolve((double)p / (double)q, 1);

        out << "Case #" << i+1 << ": ";
        if(answer == -1)
        {
            out << "Impossible" << endl;
        }
        else
        {
            out << answer << endl;
        }
    }

    return 0;
}
