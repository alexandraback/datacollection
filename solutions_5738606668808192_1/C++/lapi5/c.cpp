#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int T, n, j;
    cin >> T >> n >> j;

    int cnt = 0;
    set<string> ans;
    cout << "Case #1:" << endl;
    for(int i = 0; i < (1 << (n - 4) / 2); ++i)
    {
        string s1 = "11", s2 = "1";
        int tmp = i;
        while(tmp)
        {
            if(tmp % 2 == 1) { s1 += "11"; s2 += "1"; }
            else { s1 += "00"; s2 += "0"; }
            tmp /= 2;
        }

        s1 += string((n - 2) - s1.length(), '0') + "11";
        s2 += string(((n / 2) - 1) - s2.length(), '0') + "1";
        s2 = s2 + s2;

        if(ans.count(s1) == 0)
        {
            ans.insert(s1);
            cout << s1;
            for(int divisor = 3; divisor <= 11; ++divisor)
                cout << " " << divisor;
            cout << endl;
            ++cnt;
        }
        if(cnt == j) break;
        if(ans.count(s2) == 0)
        {
            ans.insert(s2);
            cout << s2;
            for(int k = 2; k <= 10; ++k)
            {
                long long divisor = 0;
                for(int l = 0; l < s2.size() / 2; ++l)
                {
                    if(s2[l] == '1') divisor += 1;
                    divisor *= k;
                }
                divisor /= k;
                cout << " " << divisor;
            }
            cout << endl;
            ++cnt;
        }
        if(cnt == j) break;
    }

    
    return 0;

}