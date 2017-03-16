#include <iostream>
#include <string>

using namespace std;

int i, t, j;
int r, c, m, n;

bool impossible;

string s;

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> t;

    for(i = 1; i <= t; ++i)
    {
        cin >> r >> c >> m;
        cout << "Case #" << i << ":";

        n = r * c;
        s = "";
        impossible = false;
        if(r == 1 || c == 1)
        {
            if(m == n) impossible = true;
            else
            {
                s += "c";
                for(j = 1; j < n - m; ++j) s += ".";
                for(; j < n; ++j) s += "*";
            }
        }
        else if(r == 2 || c == 2)
        {
            if((m % 2 || m == n - 2 || m == n) && m != n - 1) impossible = true;
            else
            {
                s += "c";
                if(r == 2 && m != n - 1)
                {
                    m /= 2;
                    for(j = 1; j < c - m; ++j) s += ".";
                    for(;j < c; ++j) s += "*";
                    for(j = 0; j < c - m; ++j) s += ".";
                    for(;j < c; ++j) s += "*";
                }
                else
                {
                    for(j = 1; j < n - m; ++j) s += ".";
                    for(; j < n; ++j) s += "*";
                }
            }
        }
        else
        {
            if(m == n || m == n - 2 || m == n - 3 || m == n - 5 || m == n - 7) impossible = true;
            else
            {
                s += "c";
                if(m < n - 2 * c - 1)
                {
                    for(j = 1; j < n - m - 2; ++j) s += ".";
                    if(m % c + 1 == c) s += "*..";
                    else s += "..*";
                    j += 3;
                    for(; j < n; ++j) s += "*";
                }
                else if(m < n - 7)
                {
                    if((n - m) % 2 == 0)
                    {
                        for(j = 1; j < (n - m) / 2 - 1; ++j) s += ".";
                        for(;j < c; ++j) s += "*";
                        for(j = 0; j < (n - m) / 2 - 1; ++j) s += ".";
                        for(;j < c; ++j) s += "*";
                        j *= 2;
                        s += "..";
                        j += 2;
                        for(; j < n; ++j) s += "*";
                    }
                    else
                    {
                        ++m;
                        for(j = 1; j < (n - m) / 2 - 1; ++j) s += ".";
                        for(;j < c; ++j) s += "*";
                        for(j = 0; j < (n - m) / 2 - 1; ++j) s += ".";
                        for(;j < c; ++j) s += "*";
                        j *= 2;
                        s += "...";
                        j += 3;
                        for(; j < n; ++j) s += "*";
                    }
                }
                else 
                {
                    for(j = 1; j < n; ++j) s += "*";
                    if(m < n - 2)
                    {
                        s[1] = '.';
                        s[c] = '.';
                        s[c + 1] = '.';
                    }
                    if(m == n - 6)
                    {
                        s[2 * c] = '.';
                        s[2 * c + 1] = '.';
                    }
                }
            }
        }

        if(impossible) cout << "\nImpossible" << endl;
        else
        {
            for(j = 0; j < n; ++j)
            {
                if(j % c == 0) cout << endl;
                cout << s[j];
            }
            cout << endl;
        }
    }

    return 0;
}
