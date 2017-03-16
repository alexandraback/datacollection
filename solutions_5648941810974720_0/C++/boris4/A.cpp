#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

pair<char, pair<char, string> > dict[] = {
    make_pair('Z', make_pair('0', "ZERO")),
    make_pair('W', make_pair('2', "TWO")),
    make_pair('U', make_pair('4', "FOUR")),
    make_pair('G', make_pair('8', "EIGHT")),
    make_pair('H', make_pair('3', "THREE")),
    make_pair('F', make_pair('5', "FIVE")),
    make_pair('X', make_pair('6', "SIX")),
    make_pair('V', make_pair('7', "SEVEN")),
    make_pair('O', make_pair('1', "ONE")),
    make_pair('N', make_pair('9', "NINE"))
};
int cnt[30];

int main() {

    int testNum; cin >> testNum;
    for (int testId = 1; testId <= testNum; ++testId) {
        string str; cin >> str;
        memset(cnt, 0, sizeof(cnt));
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            cnt[str[i] - 'A']++;
        }

        string res = "";
        int left = n;
        while (left > 0) {
            for (int i = 0; i < 10; ++i) {
                if (cnt[dict[i].first - 'A'] > 0) {
                    for (int j = 0; j < dict[i].second.second.size(); ++j) {
                        --cnt[dict[i].second.second[j] - 'A'];
                        --left;
                    }
                    res += dict[i].second.first;
                    break;
                }
            }
        }

        sort(res.begin(), res.end());
        cout << "Case #" << testId << ": " << res << endl;
    }
    return 0;
}
