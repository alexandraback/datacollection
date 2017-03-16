#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int cnt, i, len, t;
    string map = "yhesocvxduiglbkrztnwjpfmaq", temp, text_in, text_out;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    getline(cin, temp);
    for (cnt = 1; cnt <= t; cnt++)
    {
        getline(cin, text_in);
        len = text_in.length();
        text_out = text_in;
        for (i = 0; i < len; i++)
        {
            if ((text_in[i] >= 'A') && (text_in[i] <= 'Z')) text_out[i] = map[text_in[i] - 'A'] - 32;
            if ((text_in[i] >= 'a') && (text_in[i] <= 'z')) text_out[i] = map[text_in[i] - 'a'];
        }
        cout << "Case #" << cnt << ": " << text_out << endl;
    }
    return 0;
}
