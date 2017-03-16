#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int ans = 0;
        string s;
        int n;
        cin >> s;
        cin >> n;
        vector <int> a(s.length(), 0);
        vector <int> b(s.length(), 0);
        vector <int> c(s.length(), 0);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e')
                a[i] = 0;
            else
                a[i] = 1;
        }
        int sl = s.length();
        int k = 0;
        for (int i = 0; i < sl; i++)
        {
            if (a[i] == 1)
                k++;
            else
                k = 0;
            if (k >= n)
                b[i] = 1;
            else
                b[i] = 0;
        }
        c[0] = b[0];
        for (int i = 1; i < sl; i++)
        {
            c[i] = c[i-1] + b[i-1];
        }
        k = n - 2;
        int mark = 0;
        for (int i = 0; i < sl; i++)
        {
            if (k < i + n - 1)
                k++;
            if (b[k - 1] == 1)
                mark = 0;
            while (b[k] == 0 && k < sl)
                k++;
            if (k == sl)
                break;
            mark = 1;
            ans += sl - k;
        }
        cout << "Case #" << q + 1 << ": " << ans << endl;
    }
    return 0;
}
