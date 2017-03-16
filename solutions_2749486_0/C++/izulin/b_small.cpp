#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int it=1;it<=n;it++)
    {
        int x,y;
        cin >> x >> y;
        cout << "Case #" << it << ": ";
        for(int i=0;i<x;i++)
            cout << "WE";
        for(int i=0;i<(-x);i++)
            cout << "EW";
        for(int i=0;i<y;i++)
            cout << "SN";
        for(int i=0;i<(-y);i++)
            cout << "NS";
        cout << endl;

    }
}
