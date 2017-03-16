#include <iostream>

using namespace std;

int main()
{
    int T, K, C, S;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> K >> C >> S;
        cout << "Case #" << i+1 << ": ";
        for(int j=1; j<=S; j++)
            cout << j << " ";
        cout << endl;
    }
}

