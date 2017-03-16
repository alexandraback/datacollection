#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    ifstream fin("A.in");
    ofstream fout("A.out");
    int T;
    fin >> T;
    long long P,Q, gc, Q2;
    string sP, sQ;
    for (int testnum = 1; testnum <= T; testnum++)
    {
        getline(fin, sP, '/');
        stringstream ss;
        ss << sP;
        ss >> P;
        fin >> Q;
        gc = gcd(P, Q);
        P /= gc;
        Q /= gc;
        fout << "Case #" << testnum << ": ";
        
        Q2 = Q;
        while ((Q2 > 1) && (Q2 % 2 == 0))
            Q2 /= 2;
        
        if (Q2 == 1)
        {
            int y = 0;
            do {
                y++;
                P *= 2;
            }  while (P < Q);
            fout << y << endl;
        }
        else
            fout << "impossible" << endl;
    }
}