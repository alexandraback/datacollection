#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;
    for(int o = 0;o <t;++o)
    {
        int r,c,w;
        cin >>r >> c >> w;
        int bl = c/w;
        int ost = c%w;
        if(ost) ost = 0;
        else ost = 1;
        cout << "Case #" << o+1 <<": " << bl*(r - 1) + bl + w - ost << endl;
    }


    return 0;
}
