#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        int swaps = 0;
        if (s.length() == 1)
        {
            if (s[0] == '-')
                swaps = 1;
        }
        else
        {
            for (int i = 1; i < s.length(); ++i)
                if (s[i] != s[i-1])
                    swaps++;
            if (s[s.length()-1] == '-')
                ++swaps;
        }
        cout << "Case #" << i<< ": " << swaps << endl;
    }
}
