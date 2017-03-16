#include <iostream>
using namespace std;

char map[] = {
    'y', 'h', 'e', 's', 'o', 
    'c', 'v', 'x', 'd', 'u',
    'i', 'g', 'l', 'b', 'k',
    'r', 'z', 't', 'n', 'w',
    'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    for (int t = 0; t < T; ++t) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); ++i)
            if (islower(s[i]))
                s[i] = map[s[i] - 'a'];
        cout << "Case #" << (t + 1) << ": " << s << endl;
    }
    return 0;
}
