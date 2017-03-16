#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <math.h>
#include <cstdlib>

using namespace std;

typedef vector<int>::iterator iter;
typedef vector<int>::reverse_iterator riter;
typedef vector<string>::iterator str_iter;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int cases;
    cin >> cases;
    
    for (int ncase = 0; ncase != cases; ++ncase) {
        int x, y;
        cin >> x >> y;

        string out;
        char xd = 'E';
        char yd = 'N';
        char mxd = 'W';
        char myd = 'S';
        if (x < 0) {xd = 'W'; mxd = 'E'; x = -x;}
        if (y < 0) {yd = 'S'; myd = 'N'; y = -y;}
        
        int xj = 0;
        int yj = 0;
        int j = 0;
        int par = -1;
        while (x != xj) {
            ++j;
            par = -par;
            xj  += par*j;
            if (par > 0) {out += xd;}
            if (par < 0) {out += mxd;}

        }
        //par = -1;
        while (y != yj) {
            ++j;
            par = -par;
            yj  += par*j;
            if (par > 0) {out += yd;}
            if (par < 0) {out += myd;}

        }
        cout << "Case #" << ncase+1 << ": " << out << endl;
    }
   
    return 0;
}