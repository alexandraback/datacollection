#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int K, L, S;
        cin >> K >> L >> S;
        string keyboard, lex;
        cin >> keyboard >> lex;
        char* mess = new char[S];
        int outcomes = 1;
        for(int i = 0; i < S; i++)
            outcomes *= K;
        double maxOccurences = 0;
        double totalOccurences = 0;
        for(int i = 0; i < outcomes; i++)
        {
            int index = i;
            for(int j = 0; j < S; j++)
            {
                mess[j] = keyboard[index % K];
                index /= K;
            }
            int occurences = 0;
            for(int j = 0; j < S; j++)
            {
                bool match = true;
                for(int k = 0; k < L; k++)
                {
                    if(j + k == S || mess[j + k] != lex[k])
                    {
                        match = false;
                        break;
                    }
                }
                if(match)
                    occurences++;
            }
            if(maxOccurences < occurences)
                maxOccurences = occurences;
            totalOccurences += occurences;
        }
        delete[] mess;
        double result = (double)maxOccurences - (double)totalOccurences / outcomes;
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}

int mainA()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int R, C, W;
        cin >> R >> C >> W;
        int* row = new int[C];
        for(int i = 0; i < C; i++)
            row[i] = 0;
        row[W - 1] = W;
        for(int i = W; i < C; i++)
        {
            int minShots = 1 + row[i - 1];
            for(int j = 1; j < i; j++)
            {
                int maxShots = row[j - 1] + row[i - j - 1] + 1;
                if(W + 1 > maxShots) maxShots = W + 1;
                if(minShots > maxShots) minShots = maxShots;
            }
            row[i] = minShots;
        }
        cout << "Case #" << t << ": " << (R - 1)*(C / W) + row[C - 1] << endl;
    }
    return 0;
}
