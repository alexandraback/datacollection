//Problem A. The Last Word
//By: phoenixinter@gmail.com
//Apr 15, 2016

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t, kase = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ret = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
                ret += s[i];
            else
            {
                if (s[i] >= ret[0])
                    ret = s[i] + ret;
                else
                    ret += s[i];
            }
        }
        cout << "Case #" << ++kase << ": " << ret << endl;
    }
    return 0;
}