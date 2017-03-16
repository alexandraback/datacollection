#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll solve(const string& s, int n)
{
    const int len = s.size();
    ll result = 0;

    int pre = 0;
    int cons = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            pre += cons + 1;
            cons = 0;
        }
        else
        {
            ++cons;
            if (cons >= n)
            {
                result += (pre + 1) * (len - i);
                pre = 0;
                cons = n - 1;
            }
        }
    }

    return result;
}

int main()
{
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i)
    {
        string s;
        int n;
        cin>>s>>n;

        ll result = solve(s, n);
        cout<<"Case #"<<(i + 1)<<": "<<result<<endl;
    }

    return 0;
}
