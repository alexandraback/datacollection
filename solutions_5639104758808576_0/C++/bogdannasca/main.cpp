#include <iostream>
#include <fstream>
using namespace std;
int n,m,v[1000],s,suma;
char x;
int main()
{
    ifstream f("in.in");
    ofstream g("output.out");
    f>>n;
    for(int i=1;i<=n;++i)
    {
        s = 0;
        suma = 0;
        f>>m;
        f>>x;
        s = x-'0';
        for(int j=1;j<=m;++j)
        {
            f>>x;
            if(x>'0')
            {
                if(s<j)
                {
                    suma+=j-s;
                    s = j+x-'0';
                }
                else s+=x-'0';
            }
        }
        g<<"Case #"<<i<<": "<<suma<<"\n";
    }
    return 0;
}
