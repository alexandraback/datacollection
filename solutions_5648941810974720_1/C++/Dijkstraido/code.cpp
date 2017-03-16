#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,ntest=1;
    int frec[256];
    string s;
    vector<char> ans;
    cin >> T;
    while(T--)
    {
        cin >> s;
        memset(frec, 0, sizeof frec);
        for(int i = 0; i < (int)s.size(); i++)
            frec[s[i]]++;

        ans.clear();
        // 0
        while(frec['Z'] && frec['E'] && frec['R'] && frec['O'])
        {
            frec['Z']--; frec['E']--; frec['R']--; frec['O']--;
            ans.push_back('0');
        }
        // 2
        while(frec['T'] && frec['W'] && frec['O'])
        {
            frec['T']--; frec['W']--; frec['O']--; 
            ans.push_back('2');
        }
        // 4
        while(frec['F'] && frec['O'] && frec['U'] && frec['R'])
        {
            frec['F']--; frec['O']--; frec['U']--; frec['R']--; 
            ans.push_back('4');
        }
        // 6
        while(frec['S'] && frec['I'] && frec['X'])
        {
            frec['x']--; frec['I']--; frec['X']--; 
            ans.push_back('6');
        }
        // 8
        while(frec['E'] && frec['I'] && frec['G'] && frec['H'] && frec['T'])
        {
            frec['E']--; frec['I']--; frec['G']--; frec['H']--; frec['T']--; 
            ans.push_back('8');
        }
        // 1
         while(frec['O'] && frec['N'] && frec['E'])
        {
            frec['O']--; frec['N']--; frec['E']--; 
            ans.push_back('1');
        }
        // 3
        while(frec['T'] && frec['H'] && frec['R'] && frec['E'] && frec['E'])
        {
            frec['T']--; frec['H']--; frec['R']--; frec['E']--; frec['E']--; 
            ans.push_back('3');
        }
        // 5
        while(frec['F'] && frec['I'] && frec['V'] && frec['E'])
        {
            frec['F']--; frec['I']--; frec['V']--; frec['E']--; 
            ans.push_back('5');
        }
        // 7
        while(frec['S'] && frec['E'] && frec['V'] && frec['E'] && frec['N'])
        {
            frec['S']--; frec['E']--; frec['V']--; frec['E']--; frec['N']--; 
            ans.push_back('7');
        }
        // 9
        while(frec['N'] && frec['I'] && frec['N'] && frec['E'])
        {
            frec['N']--; frec['I']--; frec['N']--; frec['E']--; 
            ans.push_back('9');
        }

        sort(ans.begin(), ans.end());
        cout << "Case #" << ntest++ << ": ";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << '\n';
    }
    return 0;
}