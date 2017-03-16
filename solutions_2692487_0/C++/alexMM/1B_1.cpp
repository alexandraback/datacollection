// 1B_1.cpp : Defines the entry point for the console application.
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
    int count_of_games;
    cin >> count_of_games;
    for (int l = 0; l < count_of_games; ++l)
    {
        int a, n;
        cin >> a >> n;
        vector <int> motes;
        for (int i = 0; i < n; ++i)
        {
            int k;
            cin >> k;
            motes.push_back (k);
        }
        sort (motes.begin (), motes.end ());
        set <int> answers;
        int adding_answer = 0;
        for (int i = 0; i < n; ++i)
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

