#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

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
        cout << 1.0l * answer / (answers.size()) << "\n";
    }
    
    return 0;
}