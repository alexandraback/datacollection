#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;
ofstream fout ("output.txt");
ifstream fin ("input.txt");

int main()
{
    int cases, r, p, x, n;
    fin >> cases;
    go(a, cases){
        fin >> r >> p;
        x=0;
        n=1;
        while(p>=0){
            p-=2*r;
            p-=n;
            x++;
            n+=4;
        }
        case(a+1) x-1 << endl;
    }
}
