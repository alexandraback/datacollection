#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int base[] = {10,100,1000,10000,100000,1000000,10000000};

int solve(int a, int b)
{
    int flag = 0;
    int ans = 0;
    while (base[flag]<=b) ++flag;
    for (int i=a;i<=b;++i)
    {
        for (int j=0;j<flag;++j)
        {
            int k = (i%base[j])*base[flag-j-1]+i/base[j];
            if (k == i) break;
            if (k>i && k<=b)
            {
                ++ans;
//                fout<<i<<"   "<<k<<endl;
            }
        }
    }
    return ans;
}

int main()
{
    int total;
    fin.open("in.txt");
    fout.open("out.txt");
    fin>>total;
    for (int i=1;i<=total;++i)
    {
        int a,b;
        fin>>a>>b;
        int ans = solve(a,b);
        fout<<"Case #"<<i<<": "<<ans<<endl;
    }
}

