#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int T,R,C,M;
bool possible;
int r,c,f;
bool adj;
char arr[50][50];

void fullFill()
{
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            arr[i][j] = '*';
}
void regularFill()
{
    arr[0][0] = 'c';
    for(int i=1; i<f; i++)
        arr[i%r][i/r] = '.';
    for(int i=f; i<r*c; i++)
        arr[i%r][i/r] = '*';
}
void plusOne()
{
    arr[r-1][f/r-1] = '*';
    arr[1][f/r] = '.';
}
void plusOneMod()
{
    plusOne();
    arr[r-1][f/r-2] = '*';
    arr[2][f/r] = '.';
}

int main()
{
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> R >> C >> M;
        f = R*C-M;
        if(R <= C)
        {
            r = R;
            c = C;
            adj = false;
        }
        else
        {
            r = C;
            c = R;
            adj = true;
        }
        //cout << "\trc adj: " << r << ' ' << c << "  " << adj << endl;

        if(f == 1 || r == 1)
        {
            possible = true;
            regularFill();
        }
        else if(r == 2)
        {
            if(f%2 == 1 || f == 2)
                possible = false;
            else
            {
                possible = true;
                regularFill();
            }
        }
        else if(r == 3)
        {
            if(f==2 || (f%2 == 1 && f<=7))
                possible = false;
            else
            {
                possible = true;
                regularFill();
                if(f%r == 1)
                    plusOne();
            }
        }
        else
        {
            if(f >= 2*r)
            {
                possible = true;
                regularFill();
                //cout << '\t' << f << ' ' << r << endl;
                if(f == 2*r+1)
                    plusOneMod();
                else if(f%r == 1)
                    plusOne();
            }
            else if(f%2 == 0 && f >= 4)
            {
                possible = true;
                fullFill();
                for(int i=0; i<f; i++)
                    arr[i/2][i%2] = '.';
                arr[0][0] = 'c';
            }
            else if(f%2 == 1 && f >= 9)
            {
                possible = true;
                fullFill();
                for(int i=0; i<9; i++)
                    arr[i/3][i%3] = '.';
                for(int i=0; i<f-9; i++)
                    arr[3+i/2][i%2] = '.';
                arr[0][0] = 'c';
            }
            else
                possible = false;
        }

        printf("Case #%d:\n", t);
        if(!possible)
            cout << "Impossible" << endl;
        else
        {
            if(!adj)
            {
                for(int i=0; i<r; i++)
                {
                    for(int j=0; j<c; j++)
                        cout << arr[i][j];
                    cout << endl;
                }
            }
            else
            {
                for(int j=0; j<c; j++)
                {
                    for(int i=0; i<r; i++)
                        cout << arr[i][j];
                    cout << endl;
                }
            }
        }
    }
}
