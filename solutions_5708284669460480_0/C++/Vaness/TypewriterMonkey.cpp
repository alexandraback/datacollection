#include <bits/stdc++.h>
using namespace std;

int T;
int K, L, S;
vector<char> keyboard, targetWord, currentWord;
vector<int> values;

void go(vector<char> &word, int position)
{
    if (position == (int)word.size())
    {
        int inclusionAmount = 0;
        for (int i = 0; i + targetWord.size() <= word.size(); i++)
        {
            bool equals = true;
            for (int j = 0; j < (int)targetWord.size(); j++)
                if (targetWord[j] != word[i + j])
                    equals = false;
            inclusionAmount += equals;
        }
        values.push_back(inclusionAmount);
        return;
    }

    for (int i = 0; i < (int)keyboard.size(); i++)
    {
        word[position] = keyboard[i];
        go(word, position + 1);
    }
}

double solve()
{
    values.clear();
    keyboard.clear();
    targetWord.clear();
    currentWord.clear();
    cin >> K >> L >> S;
    keyboard.resize(K);
    for (int i = 0; i < K; i++)
        cin >> keyboard[i];
    targetWord.resize(L);
    for (int i = 0; i < L; i++)
        cin >> targetWord[i];
    currentWord.resize(S);
    
    go(currentWord, 0);

    if ((int)values.size() == 0)
        return 0;
    int maxValue = *max_element(values.begin(), values.end());
    double sum = 0;
    for (int amount : values)
        sum += maxValue - amount;
    return sum / (int)values.size();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for (int test = 1; test <= T; test++)
        printf("Case #%d: %.10f\n", test, solve());
}
