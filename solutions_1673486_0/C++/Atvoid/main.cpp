#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

ifstream fin;
ofstream fout;

double pro[200000];

void solve(int num)
{
    int A,B;
    fin>>A>>B;
    double min = B+2;
    double nowPro = 1,pro;

/*    for (int i = 0; i < A; ++i)
    {
        fin>>pro[i];
    }*/
    for (int i = A-1; i >= 0; --i)
    {
        double delta = 0;
        fin>>pro;
        nowPro *= pro;
        delta = nowPro*(B-A+1+2*i)+(1-nowPro)*(B+1+B-A+1+2*i);
 //       cout<<i<<endl;
        if (delta<min)
        {
            min = delta;
        }
    }

    fout<<"Case #"<<num<<": "<<setiosflags(ios::fixed)<<setprecision(6)<<min<<endl;
}

int main()
{
    int total;
    fin.open("input.txt");
    fout.open("output.txt");

    fin>>total;
    for (int i=1;i<=total;++i)
    {
        solve(i);
    }

    fin.close();
    fout.close();
    return 0;
}
