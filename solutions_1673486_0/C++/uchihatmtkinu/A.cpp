#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

fstream fin,fout;

int t;
int a,b;
double p[100000];
double f[100000];
int k;
double pi;
double ans,tmp;

int main()
{
    fin.open("A-small-attempt0.in",ios::in);
    fout.open("ans.out",ios::out);
    fin >> t;
    for (int l = 0; l < t; l++)
    {
        fin >> a >> b;
        for (int i = 1; i <= a;i++) fin>> p[i];
        f[0] = 0;
        for (int i = 1; i<= a; i++)
            f[i] = f[i-1] + (1-f[i-1])*(1-p[i]);
        ans = 1+b+1;
        for (int i = 0; i <= a; i++)
        {
            tmp = (1-f[a-i])*(i+(b-(a-i))+1) + f[a-i]*(i+(b-(a-i))+1+b+1);
            if (tmp < ans) ans = tmp;
        }
        fout << "Case #" << l+1 << ": "<< fixed << setprecision(6) << ans <<endl;

    }
    fout.close();
    return 0;
}
