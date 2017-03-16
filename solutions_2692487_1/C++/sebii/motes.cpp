#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long solve(vector<long long> motes, long long A, long long N)
{
    long long j = 0;
    while (j < N && motes[j] < A) {
        A += motes[j];
        ++j;
    }

    long long ans = N - j;
    if (A - 1 == 0)
        return ans;

    long long ans2 = 0;
    while (j < N) {
        A += A - 1;
        ++ans2;
        while (j < N && motes[j] < A) {
            A += motes[j];
            ++j;
        }
        ans = min(ans, ans2 + N - j);
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    int id = 1;
    while (T--) {
        long long A, N;
        cin >> A >> N;

        vector<long long> motes(N);
        for (int i = 0; i < N; ++i)
            cin >> motes[i];
        sort(begin(motes), end(motes));

        cout << "Case #" << id << ": " << solve(motes, A, N) << "\n";
        ++id;
    }

    return 0;
}
