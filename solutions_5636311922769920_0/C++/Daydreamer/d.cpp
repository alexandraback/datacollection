#include <iostream>
using namespace std;
int main()
{
    int T, K, C, S;
    cin >> T;
    for (int kase = 1; kase <= T; kase++)
    {   cin >> K >> C >> S;
        
        cout << "Case #" << kase << ": ";
        if (K == S) 
        {
            for (int i = 0; i < K; ++i) cout << i+1 << " ";

                cout << endl;
        }   
    }
    return 0;
}
