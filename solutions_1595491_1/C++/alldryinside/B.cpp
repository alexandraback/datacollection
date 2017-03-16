#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i, j, k, T;
    int N, S, P, score;
    cin >> T;
    for(i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        cin >> N >> S >> P;
        int ans = 0, best, bestsup;
        for(j = 0; j < N; ++j)
        {
            cin >> score;
            if(score % 3 == 0)
            {
                best = score / 3;
                if(score > 0) bestsup = score / 3 + 1;
                else bestsup = 0;
            }
            else if(score % 3 == 1)
            {
                best = score / 3 + 1;
                bestsup = score / 3 + 1;
            }
            else if(score % 3 == 2)
            {
                best = score / 3 + 1;
                bestsup = score / 3 + 2;
            }
            if(best >= P)
            {
                ++ans;
                continue;
            }
            if(S > 0 && bestsup >= P)
            {
                --S;
                ++ans;
            }

        }
        cout << ans << '\n';
    }
    return 0;
}
