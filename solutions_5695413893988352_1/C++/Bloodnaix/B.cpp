#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;

string C, J;
int n;
unsigned long long int a, b;
unsigned long long int ans_a, ans_b;
long long int min_d;

void update_and(unsigned long long int x, unsigned long long int y)
{
    //cout << "updating " << x << ' ' << y << endl;
    long long int d = x - y;
    if(d < 0)
    {
        d = -d;
    }
    //cout << C << ' ' << J << ' ' << d << endl;
    if(d == min_d)
    {
        if(x < ans_a || (x == ans_a && y < ans_b))
        {
            ans_a = x;
            ans_b = y;
        }
    }
    if(min_d < 0 || d < min_d)
    {
        min_d = d;
        ans_a = x;
        ans_b = y;
    }
}

void dfs(unsigned long long int a, unsigned long long int b, int i)
{
    //cout << "dfs " << a << ' ' << b << ' ' << i << endl;
    if(i == n)
    {
        update_and(a, b);
        return;
    }
    if(C[i] != '?' && J[i] != '?')
    {
        dfs(a*10 + C[i] - 48, b*10 + J[i] - 48, i+1);
        return;
    }
    if(a == b)
    {
        if(C[i] == '?' && J[i] == '?')
        {
            dfs(a*10 + 0, b*10 + 0, i+1);
            dfs(a*10 + 0, b*10 + 1, i+1);
            dfs(a*10 + 1, b*10 + 0, i+1);
            return;
        }
        if(C[i] == '?')
        {
            dfs(a*10 + J[i] - 48, b*10 + J[i] - 48, i+1);
            if(J[i] != '0')
            {
                dfs(a*10 + J[i] - 48 - 1, b*10 + J[i] - 48, i+1);
            }
            if(J[i] != '9')
            {
                dfs(a*10 + J[i] - 48 + 1, b*10 + J[i] - 48, i+1);
            }
            return;
        }
        if(J[i] == '?')
        {
            dfs(a*10 + C[i] - 48, b*10 + C[i] - 48, i+1);
            if(C[i] != '0')
            {
                dfs(a*10 + C[i] - 48, b*10 + C[i] - 48 - 1, i+1);
            }
            if(C[i] != '9')
            {
                dfs(a*10 + C[i] - 48, b*10 + C[i] - 48 + 1, i+1);
            }
            return;
        }
    }
    if(a < b)
    {
        if(C[i] == '?')
            a = a*10 + 9;
        else
            a = a*10 + C[i] - 48;
        if(J[i] == '?')
            b = b*10 + 0;
        else
            b = b*10 + J[i] - 48;
        dfs(a, b, i+1);
        return;
    }
    if(a > b)
    {
        if(C[i] == '?')
            a = a*10 + 0;
        else
            a = a*10 + C[i] - 48;
        if(J[i] == '?')
            b = b*10 + 9;
        else
            b = b*10 + J[i] - 48;
        dfs(a, b, i+1);
        return;
    }
}


int main()
{
    ifstream f1("B-large.in");
    ofstream f2("B-large.out");
    int T;
    f1 >> T;
    for(int t = 0; t < T; ++t)
    {
        f2 << "Case #" << t+1 << ": ";
        cout << "Case #" << t+1 << ": \n";
        f1 >> C >> J;
        //cout << C << ' ' << J << endl;
        n = C.size();
        min_d = -1;
        dfs(0, 0, 0);
        string ans_c = "", ans_j = "";
        for(int i = 0; i < n; ++i)
        {
            int x = ans_a % 10;
            ans_c = char(48 + x) + ans_c;
            x = ans_b % 10;
            ans_j = char(48 + x) + ans_j;
            ans_a /= 10;
            ans_b /= 10;
        }
        f2 << ans_c << ' ' << ans_j << endl;

    }
    return 0;
}

