#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int test;
    fin>>test;

    for(int i=1;i<=test;i++)
    {
        int index[2501]={0};
        int n;
        fin>>n;

        for(int j=1;j<=(2*n-1);j++)
        {
            for(int k=1;k<=n;k++)
            {
                int x;
                fin>>x;
                index[x]++;
            }
        }

        fout<<"Case #"<<i<<": ";

        for(int j=1;j<=2500;j++)
        {
            if(index[j]%2 == 1)
                fout<<j<<" ";
        }
        fout<<endl;
    }


    return 0;
}
