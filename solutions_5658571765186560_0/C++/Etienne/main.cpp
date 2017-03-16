#include <iostream>

using namespace std;

void doTest()
{
    int x,r,c;
    cin >> x >> r >> c;
    if(r > c)
        swap(r,c);

    // some corner cases
    if(x == 1)
    {
        cout << "GABRIEL" << endl;
        return;
    }
    if(r*c % x != 0)
    {
        cout << "RICHARD" << endl;
        return;
    }
    if(r == 1)
    {
        if(x > 2)
        {
            cout << "RICHARD" << endl;
            return;
        }
        else
        {
            cout << "GABRIEL" << endl;
            return;
        }
    }
    if(x >= 7)
    {
        cout << "RICHARD" << endl;
        return;
    }
    if(x > 2*r || (r == c && x == 2*r))
    {
        cout << "RICHARD" << endl;
        return;
    }
    if(x < 2*r-1)
    {
        cout << "GABRIEL" << endl;
        return;
    }

    // Richard can force Gabriel to partition the board into two connected components.
    // Gabriel will win if there are enough columns to "pad" both sides of Gabriel's tile.
    // Check using brute force

    int emptyspaces = r*(x-r+1)-x;
    for(int l = 1; l<emptyspaces; l++)
    {
        // solve l + r * k == 0 (mod x).
        // should use Euclid's algorithm, but x is so small we can get away with the lazy solution

        int leftk = -1;
        for(int k=0; k<x; k++)
        {
            if( (l+r*k)%x == 0)
            {
                leftk = k;
                break;
            }
        }

        int rightk = -1;
        for(int k=0; k<x; k++)
        {
            if( (emptyspaces-l+r*k)%x == 0)
            {
                rightk = k;
                break;
            }
        }

        if(leftk == -1 || rightk == -1)
        {
            cout << "RICHARD" << endl;
            return;
        }
        int total = leftk + r + rightk;
        if(total > c)
        {
            cout << "RICHARD" << endl;
            return;
        }
    }
    cout << "GABRIEL" << endl;
}

int main()
{
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++)
    {
        std::cout << "Case #" << i+1 << ": ";
        doTest();
    }
}
