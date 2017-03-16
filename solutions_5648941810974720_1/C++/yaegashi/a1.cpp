#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int sub(vector<int> &h, vector<int> &n)
{
        int pos = INT_MAX;
        for (int i = 0; i < 26; i++) {
                if (n[i] > 0) {
                        int m = h[i] / n[i];
                        pos = min(m, pos);
                }
        }
        if (pos == INT_MAX)
                return 0;
        for (int i = 0; i < 26; i++)
                if (n[i] > 0)
                        h[i] -= n[i] * pos;
        return pos;
}

int main(int argc, char **argv)
{
        const char *numbers[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
        vector<int> nh[10];
        for (int i = 0; i < 10; i++) {
                string s(numbers[i]);
                nh[i].resize(26);
                for (int c: s)
                        nh[i][c-'A']++;
        }

        int T;
        cin >> T;
        for (int testcase = 0; testcase < T; testcase++) {
                string s;
                cin >> s;
                vector<int> h(26);
                for (auto c: s)
                        h[c-'A']++;
                vector<int> p(10);
                p[0] = sub(h, nh[0]);
                p[2] = sub(h, nh[2]);
                p[4] = sub(h, nh[4]);
                p[6] = sub(h, nh[6]);
                p[8] = sub(h, nh[8]);
                p[3] = sub(h, nh[3]);
                p[1] = sub(h, nh[1]);
                p[5] = sub(h, nh[5]);
                p[7] = sub(h, nh[7]);
                p[9] = sub(h, nh[9]);
                cout << "Case #" << testcase+1 << ": ";
                for (int i = 0; i < 10; i++)
                        for (int j = 0; j < p[i]; j++)
                                cout << i;
                cout << endl;
        }
        return 0;
}
