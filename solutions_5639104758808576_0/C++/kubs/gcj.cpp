#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve()
{
    int m;
    cin >> m;
    string s;
    s.reserve(m + 1);
    cin >> s;
    int num;
    int added = 0;
    int people_standing = 0;
    int added_this_turn;
    for (int i = 0; i < m + 1; i++)
    {

        added_this_turn = 0;
        num = s[i] - '0';
        if (people_standing < i)
            added_this_turn = i - people_standing;
        people_standing += num + added_this_turn;
        added += added_this_turn;
    }
    return added;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int s = solve();
        cout << "Case #" << i << ": " << s << endl;
    }
    return 0;
}
