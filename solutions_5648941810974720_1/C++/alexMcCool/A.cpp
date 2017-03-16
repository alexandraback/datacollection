#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

static const string _q = "A";

void solve()
{
    string S;
    cin >> S;

    vector<int> letter_counts(26, 0);

    for (int i = 0; i < S.size(); i++)
    {
        letter_counts[S[i] - 'A']++;
    }

    vector<string> num_strings(10);
    num_strings[0] = "ZERO";
    num_strings[1] = "TWO";
    num_strings[2] = "SIX";
    num_strings[3] = "EIGHT";
    num_strings[4] = "THREE";
    num_strings[5] = "FOUR";
    num_strings[6] = "FIVE";
    num_strings[7] = "SEVEN";
    num_strings[8] = "ONE";
    num_strings[9] = "NINE";

    vector<int> int_inds(10);
    int_inds[0] = 0;
    int_inds[1] = 2;
    int_inds[2] = 6;
    int_inds[3] = 8;
    int_inds[4] = 3;
    int_inds[5] = 4;
    int_inds[6] = 5;
    int_inds[7] = 7;
    int_inds[8] = 1;
    int_inds[9] = 9;

    vector<int> out_string;

    for (int i = 0; i < num_strings.size(); i++)
    {
        while(true)
        {
            bool can_make = true;
            for (int j = 0; j < num_strings[i].size(); j++)
            {
                if (!letter_counts[num_strings[i][j] - 'A'] > 0)
                {
                    can_make = false;
                    break;
                }
            }

            if (can_make)
            {
                for (int j = 0; j < num_strings[i].size(); j++)
                {
                    letter_counts[num_strings[i][j]-'A']--;
                }
                out_string.push_back(int_inds[i]);
            }
            else
            {
                break;
            }
        }
    }
    sort(out_string.begin(), out_string.end());
    for (int i = 0; i < out_string.size(); i++)
        cout << out_string[i];
}

int main(void)
{
    ifstream in(_q + ".in");
    ofstream out(_q + ".out");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
