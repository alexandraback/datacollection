#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

vector<string> d, dm;
string s;
string c;

int main()
{
    ifstream dic("dict.txt");
    while (dic.good())
    {
        dic >> s;
        if (s != "")
        {
            d.push_back(s);
            dm.push_back(s.substr(1, s.length() - 1));
        }
    }

    sort(d.begin(), d.end());
    sort(dm.begin(), dm.end());

    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; caseNum++)
    {
        cin >> s;
        int best[s.length() + 1][5];
        memset(best, -1, sizeof(best));
        best[0][4] = 0;
        for (unsigned int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (best[i][j] == -1)
                    continue;

                string match = s.substr(i, 1);
                vector<string>::iterator lb = lower_bound(d.begin(), d.end(), match);
                while (lb != d.end() && (*lb)[0] == s[i])
                {
                    if (lb->length() > s.length() - i)
                    {
                        lb++;
                        continue;
                    }

                    int l = i - j - 1;
                    int diff = 0;
                    bool ok = true;
                    for (unsigned int k = 0; k < lb->length(); k++)
                    {
                        if ((*lb)[k] != s[i + k])
                        {
                            if (i + k - l < 5)
                            {
                                ok = false;
                                break;
                            }
                            else
                            {
                                l = i + k;
                                diff++;
                            }
                        }
                    }
                    if (ok)
                    {
                        int score = best[i][j] + diff;
                        int ni = i + lb->length();
                        int nj = ni - l - 1;
                        if (nj > 4)
                            nj = 4;
                        if (best[ni][nj] == -1 || best[ni][nj] > score)
                        {
                            //cerr << "a) " << i << " " << j << " " << *lb << " " << ni << " " << nj << " " << score << endl;
                            best[ni][nj] = score;
                        }
                    }

                    lb++;
                }

                if (j == 4)
                {
                    if (best[i + 1][0] == -1 || best[i + 1][0] > best[i][j] + 1)
                    {
                        //cerr << "b) " << i << " " << j << " " << " " << best[i][j] + 1 << endl;
                        best[i + 1][0] = best[i][j] + 1;
                    }

                    if (i < s.length() - 1) {
                        string match = s.substr(i + 1, 1);
                        vector<string>::iterator lb = lower_bound(dm.begin(), dm.end(), match);
                        while (lb != dm.end() && (*lb)[0] == s[i + 1])
                        {
                            if (lb->length() > s.length() - i - 1)
                            {
                                lb++;
                                continue;
                            }

                            int l = i;
                            int diff = 1;
                            bool ok = true;
                            for (unsigned int k = 0; k < lb->length(); k++)
                            {
                                if ((*lb)[k] != s[i + k + 1])
                                {
                                    if (i + k + 1 - l < 5)
                                    {
                                        ok = false;
                                        break;
                                    }
                                    else
                                    {
                                        l = i + 1 + k;
                                        diff++;
                                    }
                                }
                            }
                            if (ok)
                            {
                                int score = best[i][j] + diff;
                                int ni = i + 1 + lb->length();
                                int nj = ni - l - 1;
                                if (nj > 4)
                                    nj = 4;
                                if (best[ni][nj] == -1 || best[ni][nj] > score)
                                {
                                    //cerr << "c) " << i << " " << j << " " << *lb << " " << ni << " " << nj << " " << score << endl;
                                    best[ni][nj] = score;
                                }
                            }

                            lb++;
                        }
                    }
                }
            }
        }

        int ans = best[s.length()][0];
        for (int i = 1; i < 5; i++)
        {
            if (ans == -1 || (best[s.length()][i] != -1 && best[s.length()][i] < ans))
                ans = best[s.length()][i];
        }

        cout << "Case #" << caseNum << ": " << ans << endl;
        cerr << caseNum << endl;
    }
}
