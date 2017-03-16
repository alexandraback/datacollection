#include <iostream>

using namespace std;

int main()
{
        int T;
        cin >> T;
        for (int c = 1; c <= T; c++)
        {
                int K, C, S;
                cin >> K >> C >> S;
                cout << "Case #" << c << ":";
                if (C == 1)
                {
                        for (int i = 1; i <= K; i++)
                        {
                                cout << " " << i;
                        }
                }
                else if (K == 1)
                {
                        cout << " " << 1;
                }
                else
                {
                        for (int i = 1; i < K; i++)
                        {
                                cout << " " << i*K;
                        }
                }
                cout << endl;
        }
}
