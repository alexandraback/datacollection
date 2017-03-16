// 1B_1.cpp : Defines the entry polong long for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    long long count_of_games;
    cin >> count_of_games;
    for (long long l = 0; l < count_of_games; ++l)
    {
        long long a, n;
        cin >> a >> n;
        vector <long long> motes;
        for (long long i = 0; i < n; ++i)
        {
            long long k;
            cin >> k;
            motes.push_back (k);
        }
        sort (motes.begin (), motes.end ());
        set <long long> answers;
        long long adding_answer = 0;
        for (long long i = 0; i < n; ++i)
        {
            if (a <= motes [i])
            {
                answers.insert (n - i + adding_answer);
                while (a <= motes [i])
                {
                    if (a == 1)
                    {
                        adding_answer = n;
                        break;
                    }
                    adding_answer++;
                    a = 2 * a - 1;
                }
            }
            a += motes [i];
        }
        answers.insert (adding_answer);
        cout << "Case #" << l + 1 << ": " << *answers.begin () << endl;
    }
	return 0;
}

