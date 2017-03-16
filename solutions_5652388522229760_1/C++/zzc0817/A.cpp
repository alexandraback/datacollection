#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca)
    {
        long long N;
        cin >> N;
        long long ans = 0;
        if(N > 0)
        {
            int cnt[10] = {0};
            int rem = 10;
            while(rem > 0)
            {
                ans += N;
                long long T = ans;
                while(T)
                {
                    if(cnt[T%10] == 0)
                    {
                        --rem;
                        cnt[T%10] = 1;
                    }
                    T /= 10;
                }
            }
        }
        cout << "Case #" << ca << ": ";
        if(ans == 0)
            cout << "INSOMNIA\n";
        else
            cout << ans << "\n";
    }
    cout << flush;
    return 0;
}
