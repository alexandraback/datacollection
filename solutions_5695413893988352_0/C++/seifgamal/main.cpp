#include <bits/stdc++.h>

using namespace std;
vector < string > v;
int n;
void solve(int i, string s)
{
    if (i == n)
    {
        v.push_back(s);
        return ;
    }
    for (int ii = 0 ; ii <= 9 ; ii++ )
    {
        solve(i + 1, s + char(ii + '0'));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    int t, T = 1;
    cin >> t;
    while(t--)
    {
        string s,t;
        cin >> s >> t;
        int sz = int (s.size());
        v.clear();
        n = sz;
        solve(0,"");
        int res = 10000, NUM1 = 10000,  NUM2 = 1000000;
        for (int i = 0 ; i < v.size() ; i++ )
        {
            for (int j = 0 ; j < v.size() ; j++)
            {
                bool check = 1;
                for (int k = 0 ; k < s.size() ; k++)
                {
                    if (s[k] != '?' && s[k] != v[i][k])
                    {
                        check = 0 ;
                    }
                    if (t[k] != '?' && t[k] != v[j][k])
                    {
                        check = 0 ;
                    }
                }
                if (check)
                {
                    int num1, num2;
                    stringstream ss;
                    ss << v[i] ; ss >> num1 ; ss.clear();
                    ss << v[j] ; ss >> num2 ; ss.clear();
                    if (abs(num1 - num2) < abs(NUM1 - NUM2))
                    {
                        NUM1 = num1;
                        NUM2 = num2;
                    }
                    else if (abs(num1 - num2) == abs(NUM1 - NUM2))
                    {
                        if (num1 < NUM1 || num1 == NUM1 && num2 < NUM2)
                        {
                            NUM1 = num1;
                            NUM2 = num2;
                        }
                    }
                }
            }
        }


        cout << "Case #" << T++ << ": " << setfill('0') << setw(sz) << NUM1 << " " << setfill('0') << setw(sz) << NUM2 << "\n";
    }
}
