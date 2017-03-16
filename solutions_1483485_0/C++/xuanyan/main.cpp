#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string map("yhesocvxduiglbkrztnwjpfmaq");
    int T;
    cin >> T;
    cin.ignore(100, '\n');

    for (int i = 1; i <= T; ++i)
    {
        string str;
        getline(cin, str);

		for (auto &x: str)
        {
            if (islower(x))
                x = map[x - 'a'];
        }

        cout << "Case #" << i << ": " << str << endl;
    }
}
