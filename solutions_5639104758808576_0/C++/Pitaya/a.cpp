#include <iostream>

using namespace std;

int main() 
{
    int T, add, count, smax;
    char ch;
    cin >> T;
    for (int I = 0; I < T; ++I)
    {
        cin >> smax;
        count = 0;
        add = 0;
        for (int i = 0; i <= smax; ++i)
        {
            cin >> ch;
            if (ch != '0' && i > count + add) {
                add = i - count;
            }
            count += ch - 48;
        }
        cout << "Case #" << I + 1 << ": ";
        cout << add << endl;
    }
    return 0;
}