#include <bits/stdc++.h>
using namespace std;

struct sol
{
    int x,y,z;
} a;

int t,j,p,s,k,num;
stack<sol> S;
bool B[11][11][11];

int main()
{
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        cin >> j >> p >> s >> k;

        if (k>=p)
        {cout <<"Case #" << i << ": "<< num << endl;

            cout << j*p*min(s,k) << endl;

            for (int x = 1; x <= j; ++x)
            {
                for (int y = 1; y <= p; ++y)
                {
                    for (int z = 1; z <= min(s,k); ++z)
                    {
                        cout << x << ' ' << y << ' ' << z << endl;
                    }
                }
            }
        }
        else
        {
            for (int x = 0; x < 10; ++x)
            {
                for (int y = 0; y < 10; ++y)
                {
                    for (int z = 0; z < 10; ++z)
                    {
                        B[x][y][z] = true;
                    }
                }
            }

            num = j*p*s;

            for (int x = 0; x < j; ++x)
            {
                for (int y = 0; y < p; ++y)
                {
                    for (int z = 0; z < p; ++z)
                    {
                        if ((x/k==y/k && z/k==0)||(y/k==z/k && x/k==0)||(z/k==x/k && y/k==0))
                        {
                            num--;
                            B[x][y][z] = false;
                        }
                    }
                }
            }

            cout <<"Case #" << i << ": "<< num << endl;

            for (int x = 0; x < j; ++x)
            {
                for (int y = 0; y < p; ++y)
                {
                    for (int z = 0; z < p; ++z)
                    {
                        if (B[x][y][z])
                        {
                            cout << x+1 << ' ' << y+1 << ' ' << z+1 <<endl;
                        }
                    }
                }
            }
        }
    }
}
