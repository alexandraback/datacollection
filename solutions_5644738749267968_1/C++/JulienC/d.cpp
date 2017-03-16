#include <algorithm>
#include <iostream>

using namespace std;

int N;
double naomiWeights[1000];
double kenWeights[1000];
bool usedKen[1000];

int simulateWar()
{
    for (int i = 0; i < N; i++)
    {
        usedKen[i] = false;
    }

    int scoreHonest = 0;
    for (int i = 0; i < N; i++)
    {
        bool found = false;
        int lowestKenIndex = -1;
        for (int j = 0; j < N; j++)
        {
            if (usedKen[j])
            {
                continue;
            }
            if (lowestKenIndex == -1)
            {
                lowestKenIndex = j;
            }
            if (kenWeights[j] > naomiWeights[N-1-i])
            {
                found = true;
                usedKen[j] = true;
                break;
            }
        }
        if (!found)
        {
            usedKen[lowestKenIndex] = true;
            scoreHonest++;
        }
    }
    return scoreHonest;
}

int simulateDeceitfulWar()
{
    int scoreCheat = 0;
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (naomiWeights[i] > kenWeights[j])
        {
            scoreCheat++;
            j++;
        }
    }
    return scoreCheat;
}

void solve(int t)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> naomiWeights[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> kenWeights[i];
    }
    sort(naomiWeights, naomiWeights+N);
    sort(kenWeights, kenWeights+N);

    int y = simulateDeceitfulWar();
    int z = simulateWar();
    cout << "Case #" << t << ": " << y << " " << z << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve(t);
    }
    return 0;
}

