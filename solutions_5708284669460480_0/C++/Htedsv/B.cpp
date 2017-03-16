#include <iostream>
#include <cmath>
using namespace std;

string w, u; int k, l, s, T, ans;
char v[100];
void deep(int pos)
{
    if (pos == s)
    {
        for (int i = 0; i < s-l+1; ++i)
        {
            bool found = true;
            for (int j = 0; j < l; ++j)
            {
                if (w[j] != v[i+j])
                {
                    found = false;
                    break;
                }
                
            }
            if (found) ans++;
        }
    }
    else
    {
        for (int i = 0; i < u.size(); ++i)
        {
            v[pos] = u[i];
            deep(pos+1);
        }
    }
}


bool findall(string u,string w)
{
    for (int i = 0; i < w.size(); ++i)
        if (u.find(w[i]) == std::string::npos)
            return false;
    return true;
}

            
int main()
{
    cin >> T;
    for (int I = 1; I <= T; ++I)
    {
        cin >> k >> l >> s;
        cin >> u;
        cin >> w;
        int len = 0;
        for (int i = 1; i < l; ++i)
        {
            bool found = true;
            for (int j = i; j < l; ++j)
                if (w[j] != w[j-i])
                {
                    found = false;
                    break;
                }
            if (found)
            {
                len = i;
                break;
            }
        }
        int mmax;
        if (len > 0 && s >= l) 
            mmax = (s - l + len) / len;
        else if (findall(u, w))
            mmax = s / l;
        else mmax = 0;
        ans = 0;
        if (mmax > 0)
            deep(0);
        printf("Case #%d: %.8lf\n", I, mmax - ans/pow(k,s));
    }
}

