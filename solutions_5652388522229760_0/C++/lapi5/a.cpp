#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t)
    {
        int n;
        cin >> n;
        if(n == 0) 
        {
            cout << "Case #" << t << ": INSOMNIA" << endl;
            continue;
        }

        bool digit[10] = {false};
        int cnt = 0;
        int ans = n;

        while(cnt != 10)
        {
            int tmp = ans;
            while(tmp)
            {
                if(digit[tmp % 10] == false)
                {
                    digit[tmp % 10] = true;
                    ++cnt;
                }
                tmp /= 10;
            }
            ans += n;
        }

        cout << "Case #" << t << ": " << ans - n << endl;


    }
    return 0;
}