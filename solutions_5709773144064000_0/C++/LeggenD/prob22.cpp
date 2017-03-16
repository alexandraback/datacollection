#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

long double tot_time(long double C, long double F, long double X, long double A, long double base, long double time )
{

    long double B = C/base;
    long double D = X/(base + F);
    while (A >= B+D)
    {
        A = D;
        base = base+F;
        time = time + B;
        B = C/base;
        D = X/(base + F);
    }
    return time + A;

}



int main()
 {
    int i,T;
    long double C[100],F[100],X[100], A;
    ifstream File("B-small-attempt0 (1).in");
    File>>T;
    for(i=0;i<T;i++)
        File>>C[i]>>F[i]>>X[i];

    ofstream ofile;
    ofile<<setprecision(7)<<fixed;

    ofile.open("out.txt");

    for(i=0;i<T;i++)
    {
        A = X[i]/2;
        ofile<<"Case #"<<(i+1)<<": "<<tot_time(C[i], F[i], X[i], A, 2.0,0.0)<<endl;
    }
    return 0;
 }


