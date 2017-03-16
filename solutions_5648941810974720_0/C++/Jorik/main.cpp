#include <bits/stdc++.h>

using namespace std;

vector<string> numbers;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    numbers.push_back("ZERO");
    numbers.push_back("ONE");
    numbers.push_back("TWO");
    numbers.push_back("THREE");
    numbers.push_back("FOUR");
    numbers.push_back("FIVE");
    numbers.push_back("SIX");
    numbers.push_back("SEVEN");
    numbers.push_back("EIGHT");
    numbers.push_back("NINE");

    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        //CHECK if with or without endline!!!
        printf("Case #%d: ", kras);
        string s;
        cin >> s;
        vector<int> occurences(300, 0);
        for(int i=0; i<s.size(); i++)
        {
            occurences[s[i]]++;
        }
        string ans = "";

        int tmp;
        tmp = occurences['Z'];
        for(int i=0; i<tmp; i++)
        {
            ans += "0";
            for(int j=0; j<numbers[0].size(); j++)
            {
                occurences[numbers[0][j]]--;
            }
        }

        tmp = occurences['X'];
        for(int i=0; i<tmp; i++)
        {
            ans += "6";
            for(int j=0; j<numbers[6].size(); j++)
            {
                occurences[numbers[6][j]]--;
            }
        }

        tmp = occurences['W'];
        for(int i=0; i<tmp; i++)
        {
            ans += "2";
            for(int j=0; j<numbers[2].size(); j++)
            {
                occurences[numbers[2][j]]--;
            }
        }

        tmp = occurences['U'];
        for(int i=0; i<tmp; i++)
        {
            ans += "4";
            for(int j=0; j<numbers[4].size(); j++)
            {
                occurences[numbers[4][j]]--;
            }
        }

        tmp = occurences['F'];
        for(int i=0; i<tmp; i++)
        {
            ans += "5";
            for(int j=0; j<numbers[5].size(); j++)
            {
                occurences[numbers[5][j]]--;
            }
        }

        //cout << occurences['N'] << endl;

        tmp = occurences['V'];
        for(int i=0; i<tmp; i++)
        {
            ans += "7";
            for(int j=0; j<numbers[7].size(); j++)
            {
                occurences[numbers[7][j]]--;
            }
        }

        tmp = occurences['G'];
        for(int i=0; i<tmp; i++)
        {
            ans += "8";
            for(int j=0; j<numbers[8].size(); j++)
            {
                occurences[numbers[8][j]]--;
            }
        }

        tmp = occurences['I'];
        for(int i=0; i<tmp; i++)
        {
            ans += "9";
            for(int j=0; j<numbers[9].size(); j++)
            {
                occurences[numbers[9][j]]--;
            }
        }

        tmp = occurences['T'];
        for(int i=0; i<tmp; i++)
        {
            ans += "3";
            for(int j=0; j<numbers[3].size(); j++)
            {
                occurences[numbers[3][j]]--;
            }
        }

        //cout << occurences['N'] << endl;

        tmp = occurences['N'];
        for(int i=0; i<tmp; i++)
        {
            ans += "1";
            for(int j=0; j<numbers[1].size(); j++)
            {
                occurences[numbers[1][j]]--;
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans << endl;

    }
    return 0;
}
