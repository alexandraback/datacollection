#include <iostream>
#include <string>

using namespace std;

int main()
{ 
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t)
    {
        string s;
        cin >> s;

        int ans = 0;
        size_t end = s.find_last_of('-');
        if(end == string::npos)
        {
            cout << "Case #" << t << ": " << ans << std::endl;
            continue;
        }

        while(end != string::npos)
        {
            size_t cont_plus = s.find_first_of('-');
            if(cont_plus != 0)
            {
                for(int i = 0; i < cont_plus; ++i)
                    s[i] = '-';
                ans += 1;
            }

            for(int i = 0; i <= end; ++i)
            {
                if(s[i] == '+') s[i] = '-';
                else s[i] = '+';
            }
            ans += 1;
            end = s.find_last_of('-');
        }
        cout << "Case #" << t << ": " << ans << std::endl;
    }
    return 0;
}