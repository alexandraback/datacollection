// 1B_1.cpp : Defines the entry polong long for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    long long count_of_games;
    cin >> count_of_games;
    for (long long l = 0; l < count_of_games; ++l)
    {
        double answer = 1;
        int n, x, y;
        cin >> n >> x >> y;
        x = abs (x);
        int h = x + y;
        if (n <= h * (h - 1) / 2) 
            cout << "Case #" << l + 1 << ": " << "0.0" << endl;
        else if (n >= h * (h - 1) / 2 + h + y + 1)
            cout << "Case #" << l + 1 << ": " << "1.0" << endl;
        else 
        {
            n -= h * (h - 1) / 2;
            if ((n - h) > 0)
            {
                y -= n - h;
                n -= 2 * (n - h);
            }
            int C = 1;
            int Csum = 0;
            answer = 1;
            for (int i = 1; i <= n; ++i)
            {
                C = C * (n - i + 1) / i;
                if (i > y)
                    Csum += C;
            }
            answer *= Csum;
            for (int i = 0; i < n; ++i)
                answer *= 0.5;
            if (answer == 0)
                cout << "Case #" << l + 1 << ": " << "0.0" << endl;
            else if (answer == 1)
                cout << "Case #" << l + 1 << ": " << "1.0" << endl;
            else
                cout << "Case #" << l + 1 << ": " << answer << endl;
        }
    }
	return 0;
}

