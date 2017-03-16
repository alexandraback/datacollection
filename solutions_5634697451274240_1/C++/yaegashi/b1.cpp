#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
                string s;
                cin >> s;
                int n = s.size();
                int r = 0;
                while (true) {
                        int m = 0;
                        if (s[m] == '-') {
                                while (s[m] == '-' && m < n)
                                        m++;
                        }
                        else {
                                while (s[m] == '+' && m < n)
                                        m++;
                                if (m == n)
                                        break;
                        }
                        for (int i = 0; i < (m + 1) / 2; i++) {
                                swap(s[i], s[m-i-1]);
                                s[i] = s[i] == '+' ? '-' : '+';
                                if (m - i - 1 != i)
                                        s[m-i-1] = s[m-i-1] == '+' ? '-' : '+';
                        }
                        r++;
                }
                cout << "Case #" << t+1 << ": " << r << endl;
        }
        return 0;
}
