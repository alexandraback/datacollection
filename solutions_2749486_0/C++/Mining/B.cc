#include <iostream>
#include <string>
#include <sstream>

/*



*/
using namespace std;


string path(int dx, int dy)
{
    int cx = 0;
    int cy = 0;
    stringstream soln;
    int ci = 1;
    
    if(dy > 0)
        while(cy != dy)
        {
            soln << "SN";
            cy += 1;
        }
    if(dy < 0)
        while(cy != dy)
        {
            soln << "NS";
            cy -= 1;
        }
    if(dx > 0)
        while(cx != dx)
        {
            soln << "WE";
            cx += 1;
        }
    if(dx < 0)
        while(cx != dx)
        {
            soln << "EW";
            cx -= 1;
        }
    return soln.str();
}

int main()
{
    int num_cases = 0;
    cin >> num_cases;
    stringstream solution;
    for(int i = 0; i < num_cases; i++)
    {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        solution << "Case #" << i + 1 << ": " << path(x,y) << '\n';
    }
    cout << solution.str();
}