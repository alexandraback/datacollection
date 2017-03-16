#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double calc(const vector<double>& probs, int typed, int total, int keyCost)
{
    double probCorrect = 1.0;
    for (int i = 0; i < typed; i++)
        probCorrect *= probs[i];
    int keysIfCorrect = total - typed + 1 + keyCost;
    int keysIfNotCorrect = keysIfCorrect + total + 1;
    return probCorrect * keysIfCorrect + (1.0 - probCorrect) * keysIfNotCorrect;
}

int main()
{
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int typed;
        int total;
        cin >> typed >> total;

        vector<double> probs(typed, 0.0);
        for (int i = 0; i < typed; i++)
            cin >> probs[i];

        double best = 1e16;
        for (int backs = 0; backs <= typed; backs++)
        {
            double here = calc(probs, typed-backs, total, backs);
            best = min(best, here);
//             cout << here << endl;
        }
        double here = calc(probs, 0, total, 1);
        best = min(best, here);
//         cout << here << endl;
        cout << fixed << setprecision(6);
        cout << "Case #" << caseNum << ": " << best << endl;
    }

    return 0;
}
