#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long double> nBlocks, kenBlocks, nBlocks2, kenBlocks2;

bool hasNext() {
    if (kenBlocks.size() == 0) return false;
    long double min = kenBlocks[0];
    int i;
    for (i = 0; i < nBlocks.size(); i++) {
        if (nBlocks[i] > min) break;
    }
    if (i == nBlocks.size()) return false;
    kenBlocks.erase(kenBlocks.begin());
    nBlocks.erase(nBlocks.begin() + i);
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int count = 1; count <= n; count++) {
        nBlocks.clear(); nBlocks2.clear(); kenBlocks.clear(); kenBlocks2.clear();
        int num;
        long double tmp;
        cin >> num;
        for (int i = 0; i < num; i++) {
            cin >> tmp;
            nBlocks.push_back(tmp);
        }
        for (int i = 0; i < num; i++) {
            cin >> tmp;
            kenBlocks.push_back(tmp);
        }
        sort(nBlocks.begin(), nBlocks.end());
        sort(kenBlocks.begin(), kenBlocks.end());
        nBlocks2 = nBlocks;
        kenBlocks2 = kenBlocks;
        int score = 0;
        while (hasNext()) {
            score++;
        }
        int score2 = 0;
        for (int i = 0; i < nBlocks2.size(); i++) {
            long double cur = nBlocks2[i];
            bool works = false;
            for (int j = 0; j < kenBlocks2.size(); j++) {
                if (kenBlocks2[j] > cur) {
                    kenBlocks2.erase(kenBlocks2.begin() + j);
                    works = true;
                    break;
                }
            }
            if (!works) {
                score2++;
                kenBlocks2.erase(kenBlocks2.begin());
            }
        }
        cout << "Case #" << count << ": " << score << " " << score2 << endl;
    }
}