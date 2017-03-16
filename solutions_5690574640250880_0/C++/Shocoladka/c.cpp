#include <fstream>

using namespace std;

    ifstream cin("input");
    ofstream cout("output");
char a[100][100];
int m, r, c, o;

void start()
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            a[i][j] = '*';
}

void bad_way()
{
    cout << "Impossible" << endl;
}

void solve(int q, int w, int r, int c)
{
    for(int i = q; i < r; i++)
        for(int j = w; j < c; j++)
            if(o > 0)
            {
                a[i][j] = '.';
                o--;
            }
}

void output()
{
    a[0][0] = 'c';
    for(int i = 0; i < r; i++, cout << endl)
        for(int j = 0; j < c; j++)
            cout << a[i][j];
}

bool try_add_line(int &n)
{
    if(o > 1 && n < r)
    {
        a[n][0] = '.';
        a[n][1] = '.';
        n++;
        o-=2;
        return 1;
    }
    return 0;
}

bool try_add_column(int &m)
{
    if(o > 1 && m < c)
    {
        a[0][m] = '.';
        a[1][m] = '.';
        m++;
        o-=2;
        return 1;
    }
    return 0;
}

int main()
{
    
    int t;
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        cout << "Case #" << k + 1 << ":" << endl;
        cin >> r >> c >> m;
        start();
        o = r * c - m;
        if(r == 1 || c == 1)
        {
            solve(0, 0, r, c);
            output();
            continue;
        }
        if(o == 1)
        {
            output();
            continue;
        }

        if(o < 4)
        {
            bad_way();
            continue;
        }
        else
        {
            a[0][0] = '.';
            a[1][0] = '.';
            a[0][1] = '.';
            a[1][1] = '.';
            o -= 4;
            int n = 2, m = 2;
            int t = 1;
            for(int i = 0; t; i++)
            {
                    t = try_add_line(n);
                    t |= try_add_column(m);
            }

            if(o > 0 && (n == 2 || m == 2))
            {
                bad_way();
                continue;
            }
            solve(2, 2, n, m);
            output();
            continue;
        }
            
    }

    return 0;
}
