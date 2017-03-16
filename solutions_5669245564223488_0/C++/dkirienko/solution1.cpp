#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <string> S;
vector <int> P;
int N;

int check()
{
    string R;
    int i;
    for(i = 0; i < N; ++i)
        R += S[P[i]];
    char c;
    int count[128];
    for (i = 0; i < 128; ++i)
        count[i] = 0;
    int s = R.size();
    for(i = 0; i < s; ++i)
    {
        count[R[i]] += 1;
        if (count[R[i]] > 1)
            return 0;
        while(i + 1 < s && R[i + 1] == R[i])
            i += 1;
    }
    return 1;
}

int solve()
{
    int i, ans = 0;
    cin >> N;
    S.resize(N);
    P.resize(N);
    for(i = 0 ; i < N; ++i)
    {
        cin >> S[i];
        P[i] = i;
    }
    ans = check();
    while(next_permutation(P.begin(), P.end()))
        ans += check();
    return ans;
}

int main()
{
    int T, num;
    cin >> T;
    for (num = 1; num <= T; ++num)
    {
        cout << "Case #" << num << ": " << solve() << endl;
    }
}

