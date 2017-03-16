#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <iomanip>
#include <utility>
#include <math.h>
#include <bitset>

using namespace std;    

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int t;
    fin >> t;
    int r,c,w,s;
    for (int i=1; i<=t; i++){
        fin >> r >> c >> w;    
        s=(c/w)*r+w-1;
        if (c%w)
           s++;
        fout << "Case #" << i << ": " << s << endl;    
    }
    fin.close();
    fout.close();
    return 0;
}
