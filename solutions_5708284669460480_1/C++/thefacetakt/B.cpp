#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


struct Small
{
    int K, L, S;
    int keyboard[26];
    string target;
    string s;
    vector <int> answers;
    int maximum;

    void go(int i, string cur)
    {
        if (i == S)
        {
            int curAns = 0;
            for (int i = 0; i <= cur.size() - target.size(); ++i)
            {
                if (string(cur.begin() + i, cur.begin() + i + target.size()) == target)
                    ++curAns;
            }
            answers.push_back(curAns);
            maximum = max(maximum, curAns);
            return;
        }
        for (int j = 0; j < K; ++j)
        {
            cur.push_back(s[j]);
            go(i + 1, cur);
            cur.pop_back();
        }
    }

    int main()
    {
        int T;
        cout.precision(30);
        cout << fixed;
        cin >> T;
        for (int z = 1; z <= T; ++z)
        {
            cout << "Case #" << z << ": ";
            answers.clear();
            maximum = 0;
            cin >> K >> L >> S;
            for (int i = 0; i < 26; ++i)
                keyboard[i] = 0;
            cin >> s >> target;
            for (int i = 0; i < s.size(); ++i)
                ++keyboard[s[i] - 'A'];
            string cur = "";
            go(0, cur);
            long long answer = 0;
            for (int i = 0; i < answers.size(); ++i)
                answer += (maximum - answers[i]);
//             cout << 1.0l * answer / (answers.size()) << "\n";
        }
        
        return 0;
    }
};

const int MAXK = 100;
const int MAXL = 100;
const int MAXS = 100;
const int ALP = 26;

long double dp[MAXS + 1][MAXL + 1][MAXS + 1];
int precalc[ALP][MAXL];

int keyBoard[ALP];
vector <int> positions[ALP];

int main()
{
    int T;
    cin >> T;
// //     T = 1;
    cout.precision(30);
    cout << fixed;
    for (int z = 1; z <= T; ++z)
    {
        cout << "Case #" << z << ": ";
        
        for (int i = 0; i < ALP; ++i)
        {
            keyBoard[i] = 0;
            positions[i].clear();
        }
        int K, L, S;
        cin >> K >> L >> S;
        string target, letter;
        cin >> letter >> target;
        for (int i = 0; i <= S; ++i)
        {
            for (int j = 0; j <= L; ++j)
            {
                for (int h = 0; h <= S; ++h)
                {
                    dp[i][j][h] = 0;
                }
            }
        }
        
        for (int k = 0; k < ALP; ++k)
            for (int j = 0; j <= L; ++j)
                precalc[k][j] = 0;
        
        for (int i = 0; i < K; ++i)
        {
            ++keyBoard[letter[i] - 'A'];
        }
        int flag = 0;
        for (int i = 0; i < L; ++i)
        {
            if (!keyBoard[target[i] - 'A'])
            {
                cout << 0.0 << endl;
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        for (int i = 0; i < L; ++i)
        {
            positions[target[i] - 'A'].push_back(i);
        }
        dp[0][0][0] = 1.0l;
        
        for (int k = 0; k < ALP; ++k)
        {
            for (int j = 0; j <= L; ++j)
            {
                precalc[k][j] = upper_bound(positions[k].begin(), positions[k].end(), j) - positions[k].begin();
            }
        }
        for (int i = 0; i < S; ++i)
        {
            for (int j = 0; j <= L; ++j)
            {
                for (int k = 0; k < ALP; ++k)
                {
                    if (keyBoard[k])
                    {
                        for (int h = 0; h <= i; ++h)
                        {
                            int x = precalc[k][j];
                            if (x == 0)
                            {
                                dp[i + 1][0][h] += (1.0l * keyBoard[k] * dp[i][j][h]) / (1.0l * K);
                            }
                            else if (positions[k][x - 1] == L - 1)
                            {
                                dp[i + 1][L][h + 1] += (1.0l * keyBoard[k] * dp[i][j][h]) / (1.0l * K);
                            }
                            else
                            {
                                dp[i + 1][positions[k][x - 1] + 1][h] += (1.0l * keyBoard[k] * dp[i][j][h]) / (1.0l * K);
                            }
                        }
                    }
                }
            }
        }
        int maximum = 0;
        for (int i = 1; i < L; ++i)
        {
            if (string(target.begin(), target.begin() + i) == string(target.end() - i, target.end()))
                maximum = i;
        }
    //     cout << maximum << endl;
        maximum = (S - maximum) / (L - maximum);
    //     cout << maximum << "\n";
        long double answer = 0;
        for (int i = 0; i <= S; ++i)
        {
            for (int j = 0; j <= L; ++j)
            {
    //             cout << maximum - i << " " << dp[S][j][i] << "\n";
                if (i <= maximum)
                    answer += dp[S][j][i] * (maximum - i);
            }
        }
        
        cout << answer << endl;
        
    //     for (int i = 1; i <= S; ++i)
    //     {
    //         for (int j = 0; j < L; ++j)
    //         {
    //             for (int k = 0; k < K; ++k)
    //             {
    //                 for (int h = 0; h < S?; ++h)
    //                 {
    //                     if (target[j] == letter[k])
    //                     {
    //                         if (j + 1 == L)
    //                         {
    //                             dp[i][KMP][h + 1] += dp[i - 1][j][h];
    //                         }
    //                         else
    //                         {
    //                             dp[i][j + 1][
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    }
    return 0;
}