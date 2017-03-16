#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        cout << "case #" << i + 1 << ": ";
        for (int i = 0; i < m['Z']; i++)
            cout << '0';

        int num = m['O'] - m['U'] - m['W'] - m['Z'];
        for (int i = 0; i < num; i++)
            cout << '1';

        for (int i = 0; i < m['W']; i++)
            cout << '2';

        num = m['R'] - m['U'] - m['Z'];
        for (int i = 0; i < num; i++)
            cout << '3';

        for (int i = 0; i < m['U']; i++)
            cout << '4';

        num = m['V'] - m['S'] + m['X'];
        for (int i = 0; i < num; i++)
            cout << '5';
        for (int i = 0; i < m['X']; i++)
            cout << '6';

        num = m['S'] - m['X'];
        for (int i = 0; i < num; i++)
            cout << '7';

        for (int i = 0; i < m['G']; i++)
            cout << '8';

        num = m['I'] - m['G'] - m['X'] - m['V'] + m['S'] - m['X'];
        for (int i = 0; i < num; i++)
            cout << '9';
        cout << "\n";
    }
    return 0;
}
