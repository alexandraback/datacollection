#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

char s[128];

bool isPalindrome(long long x)
{
    sprintf(s, "%I64d", x);
    int n = strlen(s);
    for (int i=0; i<n; i++)
        if (s[i] != s[n-1-i])
            return false;
    return true;
}

vector<long long> a;

int main()
{
    for (long long i=1; i<10000000; i++)
        if (isPalindrome(i) && isPalindrome(i*i))
            a.push_back(i*i);

    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        long long x, y;
        cin >> x >> y;
        cout << "Case #" << tt << ": " << lower_bound(a.begin(), a.end(), y+1) - lower_bound(a.begin(), a.end(), x) << endl;
    }

    return 0;
}
