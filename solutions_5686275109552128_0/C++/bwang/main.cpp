#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i++)

int T;
int D;

int main()
{
    ifstream fin("B-small-attempt1.in");
    ofstream fout("output2.txt");
    fin >> T;
    FOR(i, 0, T) {
        fin >> D;
        vector<int> plates;
        int maxPlate = 0;
        FOR(j, 0, D) {
            int pancakes;
            fin >> pancakes;
            plates.push_back(pancakes);
            if (pancakes > maxPlate) {
                maxPlate = pancakes;
            }
        }
        int bestScore = 999999;
        FOR(j, 1, maxPlate + 1) {
            int splitTotal = 0;
            FOR(k, 0, D) {
                int temp = plates[k]/j;
                if (plates[k]%j == 0) {
                    temp--;
                }
                splitTotal += temp;
            }
            if (splitTotal + j < bestScore) {
                bestScore = splitTotal + j;
            }
        }
       /* int noMinutesIn = 0;
        int mostPancakes = 9999;
        while (mostPancakes > 1) {
            if (noMinutesIn + plates.top() < bestScore) {
                bestScore = noMinutesIn + plates.top();
            }
            mostPancakes = plates.top();
            plates.pop();
            if (mostPancakes%2 == 1) {
                plates.push(mostPancakes/2);
                plates.push(mostPancakes/2 + 1);
            }
            else {
                plates.push(mostPancakes/2);
                plates.push(mostPancakes/2);
            }
            noMinutesIn++;
        } */
        fout << "Case #" << i + 1 << ": " << bestScore << endl;
    }
    return 0;
}
