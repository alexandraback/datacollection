#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A, N;

int solve(vector<int>::iterator begin, vector<int>::iterator end, int A)
{
    int result = 0;
    vector<int>::iterator it = begin;
    while (it != end)
    {
        if (A > *it)
        {
            A += *it;
            it++;
        }
        else
        {
            if (A == 1)
                return N;
            A += A - 1;
            ++result;
        }
    }
    return result;
}

int main()
{
    int task, T;
    cin >> T;
    for (int task = 1; task <= T; task++)
    {
        cout << "Case #" << task << ": ";

        cin >> A >> N;
        vector<int> motes(N);
        for (int i = 0; i < N; i++) cin >> motes[i];

        sort(motes.begin(), motes.end());

        int result = N;
        for (int i = N; i > 0; i--)
        {
            int temp = solve(motes.begin(), motes.begin() + i, A) + N - i;
            if (temp < result)
                result = temp;
        }
        cout << result << endl;
    }
}
