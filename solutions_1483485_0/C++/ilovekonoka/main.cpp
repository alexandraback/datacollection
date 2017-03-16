#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int T;

string line;
string originalLine;

char alphabet[] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
                    'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };

int main()
{
    line.reserve(110);
    cin >> T;
    getline(cin, line);
    for (int t = 0; t < T; ++t)
    {
        getline(cin, line);
        originalLine.resize(line.size());
        for (unsigned int i = 0; i < line.size(); ++i)
        {
            if (line[i] == ' ')
                originalLine[i] = ' ';
            else
                originalLine[i] = alphabet[line[i] - 'a'];
        }
        cout << "Case #" << t + 1 << ": " << originalLine << endl;
    }
}