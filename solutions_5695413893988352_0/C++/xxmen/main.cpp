#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int min_abs = 1000000;
int sa[5], sb[5];
int main()
{
    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("B-small-attempt0.out.txt", "w", stdout);
    int t, Case = 0;
    cin>>t;
    while (t--)
    {
        string a, b, ansa, ansb;
        cin>>a>>b;
        ansa = a;
        ansb = b;
        int len = (int)a.length();
        min_abs = 1000000;
        if (len == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                if (a[0] != '?' && a[0] - '0' != i) continue;
                for (int j = 0; j < 10; j++)
                {
                    if (b[0] != '?' && b[0] - '0' != j) continue;
                    if (min_abs > abs(i - j))
                    {
                        min_abs = abs(i - j);
                        ansa[0] = i + '0';
                        ansb[0] = j + '0';
                    }
                }
            }
        }
        else if (len == 2)
        {
            for (int i = 0; i < 100; i++)
            {
                if (a[0] != '?' && a[0] - '0' != i / 10) continue;
                if (a[1] != '?' && a[1] - '0' != i % 10) continue;
                for (int j = 0; j < 100; j++)
                {
                    if (b[0] != '?' && b[0] - '0' != j / 10) continue;
                    if (b[1] != '?' && b[1] - '0' != j % 10) continue;
                    if (min_abs > abs(i - j))
                    {
                        min_abs = abs(i - j);
                        ansa[0] = i / 10 + '0';
                        ansb[0] = j / 10+ '0';
                        ansa[1] = i % 10 + '0';
                        ansb[1] = j % 10+ '0';
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 1000; i++)
            {
                if (a[0] != '?' && a[0] - '0' != i / 100) continue;
                if (a[1] != '?' && a[1] - '0' != i / 10 % 10) continue;
                if (a[2] != '?' && a[2] - '0' != i % 10) continue;
                for (int j = 0; j < 1000; j++)
                {
                    if (b[0] != '?' && b[0] - '0' != j / 100) continue;
                    if (b[1] != '?' && b[1] - '0' != j / 10 % 10) continue;
                    if (b[2] != '?' && b[2] - '0' != j % 10) continue;
                    //cout<<i<<" "<<j<<endl;
                    if (min_abs > abs(i - j))
                    {
                        min_abs = abs(i - j);
                        ansa[0] = i / 100 + '0';
                        ansb[0] = j / 100 + '0';
                        ansa[1] = i / 10 % 10 + '0';
                        ansb[1] = j / 10 % 10+ '0';
                        ansa[2] = i % 10 + '0';
                        ansb[2] = j % 10+ '0';
                    }
                }
                if (min_abs == 0)
                    break;
            }
        }
        cout<<"Case #"<<++Case<<": "<<ansa<<" "<<ansb<<endl;
    }
    
    
}