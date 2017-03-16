#include <iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream f("ships.in");
    ofstream g("ships.out");
    int r,c,w;
    int t;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>r>>c>>w;
        g<<"Case #"<<i<<": "<<(c/w)*r+((c%w==0)?(w-1):w)<<"\n";

    }
    return 0;
}
