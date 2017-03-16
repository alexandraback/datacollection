#include <stdio.h>
#include  <iostream>

using namespace std;

int main()
{
    freopen("outputC.txt", "w", stdout);

    int N = 16;
    int J = 50;

    cout << "Case #1: " << endl;
    int cnt = 0;
    for (int i1 = 1;  i1 < N - 1 && cnt < J; i1 += 2)
        for (int i2 = i1 + 2; i2 < N - 1 && cnt < J; i2 += 2)
            for (int i3 = 2; i3 < N - 1 && cnt < J; i3 += 2)
                for (int i4 = i3 + 2; i4 < N - 1 && cnt < J; i4 += 2)
                {
                    cnt++;
                    for (int j = N - 1; j >= 0; j--)
                        if (j == 0 || j == N - 1 || j == i1 || j == i2 || j == i3 || j == i4) cout << "1";
                        else cout << "0";
                    cout << " 3 4 5 6 7 8 9 10 11" << endl;


                }
    return 0;
}
