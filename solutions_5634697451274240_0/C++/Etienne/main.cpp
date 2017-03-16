#include <iostream>
#include <vector>
#include <string>

using namespace std;

void doCase()
{
    string s;
    cin >> s;
    char last = s[0];
    int changes = 0;
    for(int i=1; i<s.length(); i++)
    {
        if(s[i] != last)
            changes++;
        last = s[i];
    }
    if(last == '-')
        changes++;
    cout << changes << endl;
    return;
}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        cout << "Case #" << i+1 << ": ";
        doCase();
    }
    return 0;
}
