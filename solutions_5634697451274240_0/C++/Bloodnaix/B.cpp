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

string s;

void reverse(int k)
{
    for(int i = 0; i < k/2; ++i)
    {
        swap(s[i], s[k-i-1]);
    }
    for(int i = 0; i < k; ++i)
    {
        if(s[i] == '+') s[i] = '-';
        else s[i] = '+';
    }
}

int last_()
{
    for(int i = s.size()-1; i >= 0; --i)
        if(s[i] == '-')
            return i;
    return -1;
}

int first__()
{
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == '-')
            return i-1;
    return -1;
}

int main()
{
    ifstream f1("B-small-attempt0.in");
    ofstream f2("B-small-attempt0.out");
    int T;
    int n;
    int ans;
    f1 >> T;
    for(int t = 0; t < T; ++t)
    {
        f2 << "Case #" << t+1 << ": ";
        f1 >> s;
        ans = 0;
        n = last_();
        while(n >= 0)
        {
            if(s[0] == '+')
            {
                ++ans;
                reverse(first__()+1);
            }
            ++ans;
            reverse(n+1);
            n = last_();
        }

        f2 << ans << endl;
    }
    return 0;
}

