#include <iostream>
using namespace std;
int main()
{
    int T, n;
    bool bl[10];
    cin >> T;
    for (int I = 1; I <= T; ++I)
    {
        cin >> n;
        if (n == 0)
            cout << "Case #" << I << ": " << "INSOMNIA" << endl;
        else
        {
            int count = 0, tmp;
            memset(bl, 0, sizeof(bl));
            int left = 10;
            while (true)
            {
                ++count;
                tmp = count * n;
                while (tmp > 0)
                {
                    if (!bl[tmp%10])
                    {
                        bl[tmp%10] = true;
                        left--;
                    }
                    tmp /= 10;
                }
 //               for (int i = 0; i < 10; ++i) cout << bl[i] << " ";
  //              cout << endl;
                if (left == 0)
                    break;
            }
            cout << "Case #" << I << ": " << count * n << endl;
        }
    }
}
