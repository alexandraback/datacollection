// 1B_1.cpp : Defines the entry polong long for the console application.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    long long count_of_games;
    cin >> count_of_games;
    for (long long l = 1; l <= count_of_games; ++l)
    {
        int x, y;
        cin >> x >> y;
        string answer;
        if (x > 0)
        {
            for (int i = 0; i < x; ++i)
                answer += "WE";
        }
        if (x < 0)
        {
            for (int i = 0; i < abs (x); ++i)
                answer += "EW";
        }
        if (y > 0)
        {
            for (int i = 0; i < y; ++i)
                answer += "SN";
        }
        if (y < 0)
        {
            for (int i = 0; i < abs (y); ++i)
                answer += "NS";
        }
        cout << "Case #" << l << ": " << answer << endl;
    }
	return 0;
}

