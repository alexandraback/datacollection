#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
double p[110000];

int main()
{
    ifstream fin;
    fin.open("A-small-attempt0.in");
    cin.rdbuf(fin.rdbuf());
    int A,B,T;
    cin >> T;
    for (int test=1; test<=T; ++test)
    {
        cin >> A >> B;
        for (int i=1; i<=A; ++i)
            cin >> p[i];
        double min = B+2;
        double cp = 1;
        for (int i=A; i>=0; --i)
        {
            double t = i + B-(A-i)+1 + (1-cp)*(B+1);
            if (t<min)
                min = t;
            cp *= p[A-i+1];
        }
        printf("Case #%d: %.6f\n", test, min);
    }
}
