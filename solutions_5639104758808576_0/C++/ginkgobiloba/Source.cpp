#include <iostream>
#include <string>
using namespace std;

int calculate(const string& data)
{
    int additional = 0;
    int currentlyHave = 0;

    for (int i = 0; i < data.length(); ++i)
    {
        if (currentlyHave >= i)
        {
            currentlyHave += data[i] - '0';
        }
        else
        {
            additional += i - currentlyHave;
            currentlyHave = i + data[i] - '0';
        }
    }

    return additional;
}

int main()
{
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; ++t)
    {
        int l;
        string data;
        cin >> l >> data;
        cout << "Case #" << t << ": "<< calculate(data) << endl;
    }
    return 0;
}