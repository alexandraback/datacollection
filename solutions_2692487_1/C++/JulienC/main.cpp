#include <iostream>
#include <algorithm>

using namespace std;

int A;
int N;
int motes[100];

int solve_recursive(int i, int a)
{
    int remaining_motes = N - i;
    if (remaining_motes <= 0)
    {
        return 0;
    }
    if (a == 1)
    {
        return remaining_motes;
    }
    int to_add = 0;
    while (a <= motes[i])
    {
        a += a - 1;
        to_add++;
    }
    to_add += solve_recursive(i+1, a+motes[i]);
    return min(to_add, remaining_motes);
}

int solve()
{
    sort(motes, motes+N);
    return solve_recursive(0, A);

    /*
    int mods = 0;
    for (int i = 0; i < N; i++)
    {
        if (A > motes[i])
        {
            A += motes[i];
            continue;
        }

        int remaining_motes = N - i;
        int to_add = 0;
        while (A <= motes[i])
        {
            if (A == 1)
            {
                to_add = 1<<30;
                break;
            }
            A += A - 1;
            to_add++;
        }
        if (to_add >= remaining_motes)
        {
            // delete the remaining motes
            mods += remaining_motes;
            break;
        }
        mods += to_add;
        A += motes[i];
    }
    return mods;
    */
}

int main()
{
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> A >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> motes[i];
        }
        cout << "Case #" << (t+1) << ": " << solve() << endl;
    }
    return 0;
}

