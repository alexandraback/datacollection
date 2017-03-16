#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define DEBUG(x) //cerr << #x << " = " << x << endl

const int ENTER = 1;

double eVIfBackspace(int numBack,
                     const vector<double>& probabilities,
                     int numTyped,
                     int numTotal)
{
    double oddsOfError = 1;
    for(int i = 0; i < numTyped - numBack; ++i)
    {
        oddsOfError *= probabilities[i];
    }
    oddsOfError = 1 - oddsOfError;
    DEBUG(oddsOfError);
    int numTypedIfWrong = numBack*2 + (numTotal - numTyped) + 2*ENTER +
                                                                numTotal;
    int numTypedIfRight = (numTotal - numTyped) + numBack*2 + ENTER;
    return numTypedIfWrong*oddsOfError + numTypedIfRight*(1-oddsOfError);
}

double findLowestEV(const vector<double>& probabilities,
                    int numTyped,
                    int numTotal)
{
    double lowestSeen = 99999999.99; // dangerous #YOLO
    for (int i = 0; i < numTyped; ++i)
    {
        double odds = eVIfBackspace(i, probabilities, numTyped, numTotal);
        DEBUG(odds);
        if (odds < lowestSeen) {
            lowestSeen = odds;
        }
    }
    return lowestSeen;
}

int main()
{
    int numTests;
    cin >> numTests;
    for (int currTest = 0; currTest < numTests; ++currTest)
    {
        //(p)^n
        int numCharsTyped, numCharsTotal;
        cin >> numCharsTyped >> numCharsTotal;
        vector<double> probabilities(numCharsTyped);
        for(int i = 0; i < numCharsTyped; ++i)
        {
            cin >> probabilities[i];
        }
        double lowest = findLowestEV(probabilities,
                                     numCharsTyped,
                                     numCharsTotal);
        double immediateEnter = numCharsTotal + 2*ENTER;

        if (immediateEnter < lowest) {
            lowest = immediateEnter;
        }

        cout << "Case #" << currTest+1 << ": "
             << fixed << setprecision(6) << lowest << endl;
    }
}
