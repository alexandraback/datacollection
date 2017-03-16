#include <iostream>
#include <fstream>

using namespace std;

int T,X,Y;

int main()
{
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B.out");
    fin >> T;
    for (int i=1;i<=T;i++)
    {
        fout << "Case #" << i << ": ";
        fin >> X >> Y;
        if (X>0) for (int j=0;j<X;j++) fout <<"WE";
        else if (X<0) for (int j=0;j<(-1)*X;j++) fout <<"EW";
        if (Y>0) for (int j=0;j<Y;j++) fout <<"SN";
        else if (Y<0) for (int j=0;j<(-1)*Y;j++) fout <<"NS";
        fout << endl;
    }
    return 0;
}
