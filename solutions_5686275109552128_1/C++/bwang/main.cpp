#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(long long int i = a; i < b; i++)

long long int T;
long long int D;

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("outputL.txt");
    fin >> T;
    FOR(i, 0, T) {
        fin >> D;
        vector<long long int> plates;
        long long int maxPlate = 0;
        FOR(j, 0, D) {
            long long int pancakes;
            fin >> pancakes;
            plates.push_back(pancakes);
            if (pancakes > maxPlate) {
                maxPlate = pancakes;
            }
        }
        long long int bestScore = 999999999999;
        FOR(j, 1, maxPlate + 1) {
            long long int splitTotal = 0;
            FOR(k, 0, D) {
                long long int temp = plates[k]/j;
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
