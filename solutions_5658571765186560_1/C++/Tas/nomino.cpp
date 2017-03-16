#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
#include <bitset>
#include <map>
using namespace std;



bool richard(int x, int r, int c)
{
    int vol = r*c;
    int m = min(r,c);
    int M = max(r,c);

    if ( vol % x)
        return true;

    if ( x >= 7)
        return true;

    if ( 2*(m+1) - 1 <= x)
        return true;

    if (  M < x)
        return true;


    if ( x == 4 && m==2)
        return true;

    if ( x == 5 and m==3 and M==5)
        return true;

    if ( x == 6 and m==3 )
        return true;

    return false;
}

void test()
{
    for (int x=5; x <=6; x++)
        for (int r = 1; r < 9; r++)
            for (int c=r; c < 9; c++)
            {
                if (  !richard(x,r,c) && x > 2)
                    cout << x << "     :" << r << " " << c <<  " > " << endl;
            }
}

int main()
{
//     test();
//     return 0;

    int t;



    cin >> t;
    for (int cs=1; cs <=t; cs++)
    {
        int x,r,c;

        cin >> x >> r >> c;
        bool res = richard(x,r,c);


        cout << "Case #" << cs << ": " << (res ? "RICHARD" : "GABRIEL" );




        cout << endl ;

    }
}