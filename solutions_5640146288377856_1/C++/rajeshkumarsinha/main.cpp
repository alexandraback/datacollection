#include <bits/stdc++.h>
using namespace std;
/*
#define fin cin
#define fout cout
*/
ifstream fin("input.in");
ofstream fout("output.out");


int main()
{
    int t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        double r,c,w;
        fin>>r>>c>>w;
        int ans=floor(c/w);ans=ans*((int)r-1);
        ans=ans+ceil(c/w);
        ans=ans+w-1;
        fout<<"Case #"<<i<<": ";
        fout<<ans;
        fout<<endl;
    }
}
