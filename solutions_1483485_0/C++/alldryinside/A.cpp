#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#define pb push_back
using namespace std;

string rep[] = {"a y",
"b h",
"c e",
"d s",
"e o",
"f c",
"g v",
"h x",
"i d",
"j u",
"k i",
"l g",
"m l",
"n b",
"o k",
"p r",
"q z",
"r t",
"s n",
"t w",
"u j",
"v p",
"w f",
"x m",
"y a",
"z q"};

string cases[32];

map<char, char> R;

int main()
{
    int i, j, T;
    char temp[128];
    cin >> T;
    cin.getline(temp, 1);
    R[' '] = ' ';
    for(i = 0; i < 26; ++i) R[rep[i][0]] = rep[i][2];
    for(i = 0; i < T; ++i)
    {
        cin.getline(temp, 128);
        cases[i] = temp;
        cout << "Case #" << i + 1 << ": ";
        for(j = 0; j < cases[i].length(); ++j) cout << R[cases[i][j]];
        cout << '\n';
    }

    return 0;
}
