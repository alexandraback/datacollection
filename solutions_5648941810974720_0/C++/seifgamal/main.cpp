#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    string arr[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int t, T = 1;
    cin >> t;
    while(t--)
    {
        string s, res;
        cin >> s;
        vector < int > v;
        unordered_map < char, int > mp ;
        for (int i = 0 ; i < s.size() ; i++ )
        {
            mp[s[i]]++;
        }
        // zero
        while(mp['Z'])
        {
            for (int i = 0 ; i < 4 ; i++ )
                mp[arr[0][i]] --;
            res += "0";
        }
        while(mp['W'])
        {
            for (int i = 0 ; i < 3 ; i++ )
                mp[arr[2][i]] --;
            res += "2";
        }
        // FOUR
        while(mp['U'])
        {
            for (int i = 0 ; i < 4 ; i++ )
                mp[arr[4][i]] --;
            res += "4";
        }
        while(mp['X'])
        {
            for (int i = 0 ; i < 3 ; i++ )
                mp[arr[6][i]] --;
            res += "6";
        }
        while(mp['G'])
        {
            for (int i = 0 ; i < 5 ; i++ )
                mp[arr[8][i]] --;
            res += "8";
        }
        while(mp['H'])
        {
            for (int i = 0 ; i < 5 ; i++ )
                mp[arr[3][i]] --;
            res += "3";
        }
        while(mp['F'])
        {
            for (int i = 0 ; i < 4 ; i++ )
                mp[arr[5][i]] --;
            res += "5";
        }
        while(mp['S'])
        {
            for (int i = 0 ; i < 5 ; i++ )
                mp[arr[7][i]] --;
            res += "7";
        }
        while(mp['I'])
        {
            for (int i = 0 ; i < 4 ; i++ )
                mp[arr[9][i]] --;
            res += "9";
        }
        while(mp['O'])
        {
            for (int i = 0 ; i < 3 ; i++ )
                mp[arr[1][i]] --;
            res += "1";
        }
        sort(res.begin(),res.end());
        cout << "Case #" << T++ << ": " << res << "\n";
    }
}
