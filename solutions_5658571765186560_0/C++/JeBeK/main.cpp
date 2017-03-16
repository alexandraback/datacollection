#include <iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int qw,x,n,m;
ifstream fin("D-small-attempt0.in");
ofstream fout("D-small-attempt0.out");

bool check()
{
    if((n*m)%x!=0 || max(n,m)<x || min(n,m)<(x+1)/2)
        return false;
    if(x<4)
        return true;
    if(x==4)
    {
        if(min(n,m)==2)
            return false;
        return true;
    }
}

int main()
{
    fin>>qw;
    for(int q=1;q<=qw;q++)
    {
        fin>>x>>n>>m;
        fout<<"Case #"<<q<<": ";
        if(check())
            fout<<"GABRIEL"<<endl;
        else
            fout<<"RICHARD"<<endl;
    }
}
