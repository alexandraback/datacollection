#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <limits>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
#define pb push_back

#include <fstream>
ifstream fin("input.txt");
ofstream fout("output.txt");
int T,X,R,L;

int main()
{
    fin>>T;
    for(int t=1;t<=T;++t)
    {
        fin>>X>>R>>L;
        fout<<"Case #"<<t<<": ";
        if((R*L)%X!=0) fout<<"RICHARD\n";
        else if(X>max(R,L)) fout<<"RICHARD\n";
        else if(X>=7) fout<<"RICHARD\n";
        else if(X>=4 && (R==2 || L==2)) fout<<"RICHARD\n";
        else if(X>=min(R,L)*2+1) fout<<"RICHARD\n";
        else if(X>=6 && min(R,L)==3) fout<<"RICHARD\n";
        else fout<<"GABRIEL\n";
    }
}
