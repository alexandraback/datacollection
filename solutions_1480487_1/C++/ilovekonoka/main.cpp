#include <iostream>

int T;
int N;

using namespace std;

double score[220];
double answer[220];

int main()
{
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        double totalScore = 0;
        for (int n = 0; n < N; ++n)
        {
            cin >> score[n];
            totalScore += score[n];
        }
        // compute average score
        totalScore *= 2;
        double origTotal = totalScore;
        double averageScore = totalScore / N;
        int M = N;
        for (int i = 0; i < N; ++i)
        {
            if (score[i] >= averageScore)
            {
                totalScore -= score[i];
                --M;
            }
        }
        averageScore = totalScore / M;
        for (int i = 0; i < N; ++i)
        {
            answer[i] = (averageScore - score[i]) / (origTotal / 2) * 100;
            if (answer[i] < 0)
                answer[i] = 0;
            else if (answer[i] >= 100)
                answer[i] = 100;
        }
        /*
        bool allEqual = true;
        for (int i = 0; i < N; ++i)
            if (answer[i] != answer[0])
                allEqual = false;
        if (allEqual)
            for (int i = 0; i < N; ++i)
                answer[i] = 0;
        */
        cout << "Case #" << (t + 1) << ":";
        for (int i = 0; i < N; ++i)
        {
            printf(" %.7f", answer[i]);
            //cout << answer[i] << " ";
        }
        cout << endl;
    }
}