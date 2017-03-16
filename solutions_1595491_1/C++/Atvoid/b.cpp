#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int a[200];

int solve(int n, int surprizing, int p)
{
    int ans = 0;
    for (int i=0;i<n;++i)
    {
        fin>>a[i];
        if ((a[i]+2)/3>=p)
        {
            ++ans;
        }
        else if (surprizing>0 && ((a[i]/3+a[i]%3>=p)||(a[i]%3==0 && a[i]/3>0 && (a[i]/3+1>=p))))
        {
            ++ans;
            --surprizing;
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
        int a,b,c;
        fin>>a>>b>>c;
        int ans = solve(a,b,c);
        fout<<"Case #"<<i<<": "<<ans<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
