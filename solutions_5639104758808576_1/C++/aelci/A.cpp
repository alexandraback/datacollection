#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ofstream fout ("contest.out");
    ifstream fin ("contest.in");

    int caseCount;
    fin >> caseCount;

    for(int caseNo = 1; caseNo <= caseCount; caseNo++) {
        int maxShy;
        fin >> maxShy;
        vector<int> shyCount(maxShy + 1);
        for(int i = 0; i <= maxShy; i++) {
            char buffer;
            fin >> buffer;
            shyCount[i] = buffer - '0';
        }

        int clapCount = 0, invitedCount = 0;
        for(int i = 0; i <= maxShy; i++) {
            invitedCount += max(i - clapCount,0);
            clapCount += max(i - clapCount, 0) + shyCount[i];
        }
        fout << "Case #" << caseNo << ": " << invitedCount << "\n";
    }

    return 0;
}
