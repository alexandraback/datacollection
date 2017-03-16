#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string uniq(string s)
{
    stringstream ss;
    char curr = '*';
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != curr)
        {
            curr = s[i];
            ss << curr;
        }
    }
    string news;
    ss >> news;
    return news;
}

int main()
{
    ifstream fin("B.in");
    ofstream fout("B.out");
    int T, N;
    fin >> T;
    for (int testnum = 1; testnum <= T; testnum++)
    {
        fin >> N;
        string s;
        int left[26], right[26], middle[26], all[26], lr[26][26];
        for (int i = 0; i < 26; i++)
        {
            left[i] = 0; right[i] = 0; middle[i] = 0; all[i] = 0;
            for (int j = 0; j < 26; j++)
                lr[i][j] = 0;
        }
        for (int n = 0; n < N; n++)
        {
            fin >> s;
            s = uniq(s);
            if (s.length() == 1)
                all[s[0]-'a']++;
            else
            {
                left[s[0]-'a']++;
                right[s[s.length()-1]-'a']++;
                lr[s[0]-'a'][s[s.length()-1]-'a']++;
                for (int m = 1; m < s.length() - 1; m++)
                    middle[s[m]-'a']++;
            }
        }
        
        long long ans = 1;
        for (int i = 0; i < 26; i++)
        {
            if ((middle[i] > 1) || (left[i] > 1) || (right[i] > 1) || (middle[i] + left[i] > 1) || (middle[i] + right[i] > 1) || ((middle[i] == 1) && (all[i] > 0)))
            {
                ans = 0;
                break;
            }
        }
        if (ans > 0)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (lr[i][j] > 0)
                    {
                        if (lr[j][i] > 0)
                        {
                            ans = 0;
                            cout << testnum << ' ' << i << ' ' << j << endl;
                            break;
                        }
                        for (int k = 0; k < 26; k++)
                        {
                            if (lr[j][k] > 0)
                            {
                                lr[i][k]++;
                                lr[i][j]--;
                                lr[j][k]--;
                                N--;
                                j = k-1;
                                break;
                            }
                        }
                    }
                }
                if (ans == 0)
                    break;
            }
            if (ans > 0)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (all[i] > 0)
                    {
                        for (int m = 1; m <= all[i]; m++)
                            ans = (ans*m) % 1000000007;
                        if ((left[i] > 0) || (right[i] > 0))
                            N--;
                        N -= (all[i]-1);
                    }
                }
                for (int n = 1; n <= N; n++)
                    ans = (ans*n) % 1000000007;
            }
        }
                
                
        fout << "Case #" << testnum << ": " << ans << endl;
    }
}