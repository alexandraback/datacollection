#include <iostream>

using namespace std;

int T, K, C, S;

int main()
{
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        cin >> K >> C >> S;
        cout << "Case #" << i << ":";
        for(int j = 1; j <= S; j++)
        {
            cout << " " << j;
        }
        cout << endl;
    }
}
