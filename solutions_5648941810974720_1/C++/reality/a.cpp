# include <bits/stdc++.h>
using namespace std;
# define x first
# define y second
# define ll long long
# define db long double
ifstream fi("a.in");
ofstream fo("a.out");
const string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
map < char , int > has;
int main(void)
{
    int t;
    fi>>t;
    for (int cs = 1;cs <= t;++cs)
    {
        fo << "Case #" << cs << ": ";
        string s;
        fi>>s;
        has.clear();
        for (auto it : s) has[it]++;
        string ans = "";
        while (has['G'])
        {
            ans += '8';
            for (auto it : num[8]) --has[it];
        }
        while (has['W'])
        {
            ans += '2';
            for (auto it : num[2]) --has[it];
        }
        while (has['X'])
        {
            ans += '6';
            for (auto it : num[6]) --has[it];
        }
        while (has['Z'])
        {
            ans += '0';
            for (auto it : num[0]) --has[it];
        }
        while (has['H'])
        {
            ans += '3';
            for (auto it : num[3]) --has[it];
        }
        while (has['S'])
        {
            ans += '7';
            for (auto it : num[7]) --has[it];
        }
        while (has['R'])
        {
            ans += '4';
            for (auto it : num[4]) --has[it];
        }
        while (has['F'])
        {
            ans += '5';
            for (auto it : num[5]) --has[it];
        }
        while (has['O'])
        {
            ans += '1';
            for (auto it : num[1]) --has[it];
        }
        while (has['N'])
        {
            ans += '9';
            for (auto it : num[9]) --has[it];
        }
        sort(ans.begin(),ans.end());
        fo << ans << '\n';
    }
    return 0;
}
