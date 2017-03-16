#include <iostream>

using namespace std;

string TZB = "yhesocvxduiglbkrztnwjpfmaq";

int main(void)
{
    int numTest;
    cin >> numTest;
    string s;
    getline(cin, s);
    for (int testCase = 1; testCase <= numTest; testCase++)
    {
        cout << "Case #" << testCase << ": ";
        getline(cin, s);
        for (unsigned int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                cout << ' ';
            }
            else
            {
                cout << TZB[s[i] - 'a'];
            }
        }
        cout << endl;
    }
    return 0;
}

