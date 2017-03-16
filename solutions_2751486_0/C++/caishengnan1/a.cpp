#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool check (const string& in, int n)
{
    int cnt = 0;
    int len = in.length();

    for (int i = 0; i < len; i++)
    {
        if (in[i] != 'a' && in[i] != 'e' && in[i] != 'i' && in[i] != 'o' && in[i] != 'u')
            cnt++;
        else
            cnt = 0;

        if (cnt >= n)
            return true;
    }
    if (cnt >= n)
        return true;

    return false;
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;

    for (int i = 0 ; i < T; i++)
    {
        string name;
        int n;

        cin >> name >> n;

        int len = name.length();
        int cnt = 0;
        for (int b = 0; b <= len; b++)
        {
            for (int e = b+1; e <= len; e++)
            {
                string tmp(name.begin()+b, name.begin()+e);
                //cout << tmp << endl;

                if (check(tmp, n))
                {
                    //cout << "\tyes" << endl;
                    cnt++;
                }
            }
        }

        cout << "Case #" << i+1 << ": ";
        cout << cnt << endl;
    }

    return 0;
}

