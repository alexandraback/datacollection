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
        string str;
        long long n;
        long long answer = 0;
        cin >> str >> n;
        for (string::iterator iter = str.begin (); iter != str.end (); ++iter)
        {
            if ((*iter == 'a') || (*iter == 'e') || (*iter == 'i') || (*iter == 'o') || (*iter == 'u'))
            {
                *iter = '0';
            }
            else
            {
                *iter = '1';
            }
        }
        long long last = 0;
        long long curr_len = 0;
        for (long long pos = 0; pos < str.length (); ++pos)
        {
            if (str [pos] == '1')
            {
                ++curr_len;
            }
            else
            {
                curr_len = 0;
            }
            if (curr_len >= n)
            {
                answer += (pos - n + 2 - last) * (str.length () - pos);
                last = pos - n + 2;
            }
        }
        cout << "Case #" << l << ": " << answer << endl;
    }
	return 0;
}

