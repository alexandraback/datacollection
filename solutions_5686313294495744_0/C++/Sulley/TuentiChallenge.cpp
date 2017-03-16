#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int main(int argc, char *argv[]) {
    ifstream cin("C-small-attempt0.in");
    ofstream cout("output.txt");
    int T, N;
    cin >> T;
    string A, B;
    for (int caso = 1; caso <= T; caso++) {
        cin >> N;
        map<string, int> asFirst, asSecond;
        vector<string> first(N), second(N);
        for (int i = 0; i < N; i++) {
            cin >> first[i] >> second[i];
            asFirst[first[i]]++, asSecond[second[i]]++;
        }
        
        vector<bool> legitTopic(N, false);
        int legitCount = 0;
        map<string, bool> usedFirst, usedSecond;
        for (int i = 0; i < N; i++) {
            if (asFirst[first[i]] == 1 || asSecond[second[i]] == 1) {
                // The i-th topic is legit, so its words are subject to copies
                legitTopic[i] = true;
                legitCount++;
                usedFirst[first[i]] = usedSecond[second[i]] = true;
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (!legitTopic[i] && !usedFirst[first[i]] && !usedSecond[second[i]]) {
                // Regard i-th topic as legit
                legitTopic[i] = true;
                legitCount++;
                usedFirst[first[i]] = usedSecond[second[i]] = true;
            }
        }
        
        int prevLegitCount = -1;
        while (legitCount != prevLegitCount) {
            prevLegitCount = legitCount;
            for (int i = 0; i < N; i++) {
                if (!legitTopic[i] && (!usedFirst[first[i]] || !usedSecond[second[i]])) {
                    // Regard i-th topic as legit
                    legitTopic[i] = true;
                    legitCount++;
                    usedFirst[first[i]] = usedSecond[second[i]] = true;
                }
            }
        }
        
        cout << "Case #" << caso << ": " << N - legitCount << endl;
    }
    return 0;
}
