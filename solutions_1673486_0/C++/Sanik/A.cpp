#include<iostream>
#include<fstream>
#include <iomanip>
#include <math.h>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");
double P[1000000];
double p[1000000];

int main()
{
    int T;
    fin >> T;
    for(int i=0;i<T;i++)
    {
        int A,B;
        fin >> A >> B;
        for(int j=0;j<A;j++)
            fin >> p[j+1];
        double min = 999999999999.0;
        P[0]=0;
        for(int j=1;j<=A;j++)
        {
            P[j] = log(p[j]) + P[j-1];
            double E = (double)((A-j)+B-j+1) + (1-exp(P[j]))*(B+1);
            if(E<min)min = E;
        }
        double E = B+2;
        if(E<min)min = E;
        fout << "Case #" << i+1 << ": " << setprecision(6) << fixed << min << endl;
    }
    system("pause");
}
