#include <iostream>
#include <string>

using namespace std;

char combine[1001];

bool check(int n, int order[], string set[]) {
    bool seen[26] = {0};

    // Combine the strings
    int pos = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (auto& c : set[order[i]]) {
            combine[pos++] = c;
            total++;
        }
    }

    char curChar = 0;
    for (int i = 0; i < total; i++) {
        if (curChar!= 0 && combine[i] != curChar && seen[combine[i] - 'a']) {
            return false;
        } else if (combine[i] != curChar || curChar == 0) {
            curChar = combine[i];
            seen[curChar-'a'] = true;
        }
    }

    return true;
}

void permuteAndCount(int curPos, int n, int order[], string set[],
                     unsigned long& count, bool selected[]) {
    if (curPos == n) {
        if (check(n, order, set)) {
            count = (count + 1) % 1000000007;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!selected[i]) {
            order[curPos] = i;
            selected[i] = true;
            permuteAndCount(curPos+1, n, order, set, count, selected);
            selected[i] = false;
        }
    }
}

int main() {
    int t; // number of test cases
    int curCase = 1;

    cin >> t;
    while (t--) {
        cout << "Case #" << curCase << ": ";

        int n;
        string set[101];

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> set[i];
        }

        int order[101] = {0};
        unsigned long count = 0;
        bool selected[101] = {0};

        permuteAndCount(0, n, order, set, count, selected);
        cout << count << endl;

        curCase++;
    }

    return 0;
}
