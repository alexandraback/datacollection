#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>

using namespace std;



int solve_row( int c, int w)
{
    int r1 = c/w;
    int r2 = c % w;
    if (r2)
        return r1 + w;
    else
        return r1+w-1;


}

int main()
{
    int t;
    cin >> t;

    for (int i=0; i < t; i++)
    {
        int r,c,w;
        cin >> r >> c >> w;
        cout << "Case #" << i+1 << ": " << solve_row(c,w) + (r-1)*(c/w) << endl;
    }
}