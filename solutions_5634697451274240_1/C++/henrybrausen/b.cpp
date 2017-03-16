#include <iostream>

using namespace std;

bool done(const string& s)
{
    for (int i = 0; i < s.size(); ++i)
        if (s[i] != '+') return false;
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        string s;
        cin >> s;
        int flips = 0;
        while (!done(s)) {
            ++flips;
            //cout << s << endl;
            char first = s[0];
            int j;
            for (j = 1; j < s.size(); ++j) {
                if (j>=s.size() || s[j] != first) break;
            }
            for (int k = 0; k < j; ++k) {
                s[k] = (s[k] == '+')?('-'):('+');
            }
        }
        cout << "Case #" << tc << ": " << flips << endl;
    }
    return 0;
}
