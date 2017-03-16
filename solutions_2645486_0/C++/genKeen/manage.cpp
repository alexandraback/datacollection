#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int numTests;
    cin >> numTests;
    for(int test = 0; test < numTests; ++test)
    {
        int maxEnergy, regain, numThings;
        cin >> maxEnergy >> regain >> numThings;

        vector<int> vals(numThings);

        for(int i=0; i < numThings; ++i) {
            cin >> vals[i];
        }

        int answer = 0;

        if (regain >= maxEnergy) {
            for(int i=0; i < numThings; ++i) {
                answer += maxEnergy*vals[i];
            }
            cout << "Case #" << test+1 << ": " << answer << endl;
            continue;
        }

        int currEnergy = maxEnergy;
        for(int i=0; i < numThings; ++i) {
            int energyToUse = regain;

            for(int pos = i + 1;; ++pos) {
                if (pos == numThings) {
                    // None are bigger, use the whole shebang
                    energyToUse = currEnergy;
                    break;
                }
                else if (vals[pos] > vals[i]) {
                    // we found one that's bigger, so we want full energy by
                    // here to maximize use
                    energyToUse = (currEnergy + (pos-i)*regain) - maxEnergy;
                    break;
                }
            }

            if (energyToUse > currEnergy) {
                energyToUse = currEnergy;
            }
            else if (energyToUse < 0) {
                energyToUse = 0;
            }

            answer += energyToUse*vals[i];
            currEnergy -= energyToUse;
            currEnergy += regain;
        }

        cout << "Case #" << test+1 << ": " << answer << endl;
    }
}
