#include <iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int qw,x,n,m;
ifstream fin("D-large.in");
ofstream fout("D-large.out");

bool check()
{
    if(x>6 || (n*m)%x!=0 || max(n,m)<x || min(n,m)<(x+1)/2)
        return false;
    if(x<4)
        return true;
    if(x==4)
    {
        if(min(n,m)==2)
            return false;
    }
    if(x==5 && n*m==15)
        return false;
    if(x==6 && min(n,m)==3)
        return false;
    return true;
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
