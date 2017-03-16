#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
bool f (int x, int y, int m, int &a, int &b, int &c, int &d, vector<vector<bool> > &v, int x1, int y1)
{
    if (v[x][y])
    {
        return 0;
    }
    v[x][y]=1;
    if (x==1 && y==1)
    {
        a=x;
        b=y;
        return 1;
    }
    if (m==0)
    {
        if (x>1 && y>1)
        {
            a=x;
            b=y;
            return 1;
        }
    }
    if (m>=x)
    {
        if (f(x, y-1, m-x, a, b, c, d, v, x1, y1))
        {
            return 1;
        }
    }
    if (m>=y)
    {
        if (f(x-1, y, m-y, a, b, c, d, v, x1, y1))
        {
            return 1;
        }
    }
    if (m<=x+y-5 && x>2 && y>2)
    {
        a=x;
        b=y;
        c=max(2, x-m);
        m-=x-c;
        d=y-m-1;
        return 1;
    }
    return 0;
}
int main()
{
    ifstream cin("C-small-attempt3.in");
    ofstream cout("output.txt");
    int n, i;
    cin>>n;
    for (i=0;i<n;++i)
    {
        int x, y, m, j, k;
        cin>>x>>y>>m;
        int a=x, b=y, c=x, d=y;
        vector<vector<bool> > v(x+1, vector<bool>(y+1));
        cout<<"Case #"<<i+1<<":\n";
        if (x==1 || y==1 || f(x, y, m, a, b, c, d, v, x, y))
        {
            cout<<'c';
            if (x==1)
            {
                for (j=1;j<y;++j)
                {
                    if (y-j<=m)
                    {
                        cout<<'*';
                    }
                    else
                    {
                        cout<<'.';
                    }
                }
                cout<<endl;
                continue;
            }
            if (y==1)
            {
                cout<<endl;
                for (j=1;j<x;++j)
                {
                    if (x-j<=m)
                    {
                        cout<<'*';
                    }
                    else
                    {
                        cout<<'.';
                    }
                    cout<<endl;
                }
                continue;
            }
            for (j=0;j<x;++j)
            {
                for (k=0;k<y;++k)
                {
                    if (j==0 && k==0)
                    {
                        continue;
                    }
                    if (j<a && k<b && !(j==a-1 && k>=d) && !(k==b-1 && j>=c))
                    {
                        cout<<'.';
                    }
                    else
                    {
                        cout<<'*';
                    }
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<"Impossible\n";
        }
    }
    return 0;
}
