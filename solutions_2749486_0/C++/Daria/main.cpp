#include <fstream>
#include <cstring>

using namespace std;

int t, test, x, y, i;
string sol;

int main()
{
    ifstream fi("pogo.in");
    ofstream fo("pogo.out");
    fi >> t;
    for(test = 1; test <= t; test++)
    {
        fi >> x >> y;
        sol = "";
        if(x > 0) for(i = 1; i <= x; i++) sol += "WE";
        if(x < 0) for(i = 1; i <= -x; i++) sol += "EW";
        if(y > 0) for(i = 1; i <= y; i++) sol += "SN";
        if(y < 0) for(i = 1; i <= -y; i++) sol += "NS";
        fo << "Case #" << test << ": " << sol << "\n";
    }
    return 0;
}
