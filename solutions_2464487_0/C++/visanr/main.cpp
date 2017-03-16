#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int Tests;
long long R, T;

int main()
{
    ifstream cin("test.in");
    ofstream cout("test.out");
    int i;
    cin >> Tests;
    for(int TestCase = 1; TestCase <= Tests; ++ TestCase)
    {
        cout << "Case #" << TestCase << ": ";
        cin >> R >> T;
        long long Left = 1, Right = 1LL * 1000000000, Mid, Ans = -1;
        while(Left <= Right)
        {
            Mid = Left + (Right - Left) / 2;
            long long Res = (2 * Mid + 2 * R - 1);
            if(Res <= T / Mid) Ans = Mid, Left = Mid + 1;
            else Right = Mid - 1;
        }
        cout << Ans << "\n";
    }
    return 0;
}
