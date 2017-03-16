#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ofstream fout ("contest.out");
    ifstream fin ("contest.in");

    int caseCount;
    fin >> caseCount;

    for(int caseNo = 1; caseNo <= caseCount; caseNo++) {
        int nonEmptyCount = 0;
        fin >> nonEmptyCount;
        map<int, int> fulls = map<int, int>();

        for(int i = 0; i < nonEmptyCount; i++) {
            int cakeAtNonEmpty;
            fin >> cakeAtNonEmpty;
            fulls[cakeAtNonEmpty]++;
        }

        auto maxPan = fulls.rbegin();
        int minCount = maxPan->first;

        for(int plummetTo = maxPan->first - 1; plummetTo >= 1; plummetTo--) {
            int totalWait = 0;
            for(auto it = maxPan; it->first > plummetTo && it != fulls.rend(); it++) {
                totalWait += it->second *
                             ((it->first % plummetTo)? it->first / plummetTo: it->first / plummetTo - 1);
            }
            minCount = min(totalWait + plummetTo, minCount);
        }

        fout << "Case #" << caseNo << ": " << minCount << "\n";
    }

    return 0;
}
