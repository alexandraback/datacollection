#include <iostream>
#include <string>
using namespace std;

char mapping[256][256];
int neg[256][256];

bool check(int l, int x, const string& t)
{
    x = x % 4;
    if (x == 0) x = 4;
    
    string s;
    for (int i = 1; i <= x; ++i)
        s = s + t;

    int sign = 1;
    char value = '1';

    for (int i = 0; i < s.length(); ++i)
    {
        char newValue = mapping[value][s[i]];
        int newSign = sign * neg[value][s[i]];
        value = newValue;
        sign = newSign;
    }

    if (value == '1' && sign == -1) return true;
    else return false;
}

string calculate(int l, int x, const string& t)
{
    if (!check(l, x, t)) return "NO";
    string s;
    for (int i = 1; i <= 8 && i <= x; ++i)
        s = s + t;
    bool hasI = false, hasJ = false;
    int sign = 1;
    char value = '1';

    for (int i = 0; i < s.length(); ++i)
    {
        char newValue = mapping[value][s[i]];
        int newSign = sign * neg[value][s[i]];
        value = newValue;
        sign = newSign;

        if (sign == 1 && value == 'i') hasI = true;
        if (sign == 1 && value == 'k' && hasI) hasJ = true;
    }
    
    if (hasI && hasJ) return "YES";
    else return "NO";
}


void init()
{
    mapping['1']['1'] = '1';
    neg['1']['1'] = 1;
    mapping['1']['i'] = 'i';
    neg['1']['i'] = 1;
    mapping['1']['j'] = 'j';
    neg['1']['j'] = 1;
    mapping['1']['k'] = 'k';
    neg['1']['k'] = 1;

    mapping['i']['1'] = 'i';
    neg['i']['1'] = 1;
    mapping['i']['i'] = '1';
    neg['i']['i'] = -1;
    mapping['i']['j'] = 'k';
    neg['i']['j'] = 1;
    mapping['i']['k'] = 'j';
    neg['i']['k'] = -1;

    mapping['j']['1'] = 'j';
    neg['j']['1'] = 1;
    mapping['j']['i'] = 'k';
    neg['j']['i'] = -1;
    mapping['j']['j'] = '1';
    neg['j']['j'] = -1;
    mapping['j']['k'] = 'i';
    neg['j']['k'] = 1;

    mapping['k']['1'] = 'k';
    neg['k']['1'] = 1;
    mapping['k']['i'] = 'j';
    neg['k']['i'] = 1;
    mapping['k']['j'] = 'i';
    neg['k']['j'] = -1;
    mapping['k']['k'] = '1';
    neg['k']['k'] = -1;
}

int main()
{
    init();
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; ++t)
    {
        int l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << calculate(l, x, s) << endl;
    }
    return 0;
}
