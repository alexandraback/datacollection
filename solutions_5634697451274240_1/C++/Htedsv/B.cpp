#include <iostream>
using namespace std;
string s;
bool f[103], g[103];
void flip(int n)
{
    for (int i = 0; i <= n; ++i)
        g[i] = !f[n-i];
    for (int i = 0; i <= n; ++i)
        f[i] = g[i];
    return;
}
int main()
{
    int T;
    cin >> T;
    for (int I = 1; I <= T; ++I)
    {
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '+') 
                f[i] = true;
            else
                f[i] = false;
        }
        bool obj = true;
        int ans = 0;
        for (int i = n-1; i >= 0; --i)
        {
            if (f[i] != obj)
            {
                if (f[0] != obj)
                {
                    flip(i);
                    ans++;
                }
                else
                {
                    obj = !obj;
                    ans++;
                }
            }
        }
        cout << "Case #" << I << ": " << ans << endl;
    }

}
