#include <iostream>
#include <fstream>

using namespace std;

string moves(int x, int y)
{
    string r = "";
    if(x > 0)
        for(int i = 0; i < x; i++)
            r = r + "WE";
    else if (x < 0)
        for(int i = 0; i > x; i--)
            r = r + "EW";
    if(y > 0)
        for(int i = 0; i < y; i++)
            r = r + "SN";
    else if (y < 0)
        for(int i = 0; i > y; i--)
            r = r + "NS";
    return r;
}
int main()
{
    ifstream ent;
    ofstream sal;
    ent.open("input.txt");
    sal.open("output_R1C_B.txt");
    int casos, x, y;
    ent >> casos;
    for(long long i = 0; i < casos; i++){
        ent >> x >> y;
        sal << "Case #" << i+1 << ": " << moves(x,y) << endl;
    }
    ent.close();
    sal.close();
    return 0;
}
