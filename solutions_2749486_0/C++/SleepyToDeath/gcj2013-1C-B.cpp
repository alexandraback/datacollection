#include<iostream>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;
void deal(int);

int main()
{
    fin.open("gcj2013-1C-B.in");
    fout.open("gcj2013-1C-B.out");
    int t;
    fin>>t;
    for (int i=0;i<t;i++)
        deal(i);
}

void deal(int p)
{
    int x0,y0;
    fin>>x0>>y0;
    fout<<"Case #"<<p+1<<": ";
    if (x0>0)
        for (int i=0;i<x0;i++)
            fout<<"WE";
    else
        for (int i=0;i<(-x0);i++)
            fout<<"EW";
    if (y0>0)
        for (int i=0;i<y0;i++)
            fout<<"SN";
    else
        for (int i=0;i<(-y0);i++)
            fout<<"NS";
    fout<<endl;
}
