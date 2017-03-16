#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

char *words_str[] = {"zero", "two", "four", "six", "eight", "three", "five", "seven", "one", "nine"};
int nums[] = {0, 2, 4, 6, 8, 3, 5, 7, 1, 9};
string keyChars = "zwuxghfvoi";


int getMax(int ind, vector<int> &chars, const vector<string>& words)
{
    int res = 0;
    string word = words[ind];

    while (true) {
        bool can = true;
        for (int i = 0; i < word.size(); ++i) {
            if (!chars[word[i]]) can = false;
        }

        if (!can) break;
        res++;

        for (int i = 0; i < word.size(); ++i) {
            chars[word[i]]--;
        }
    }

    return res;
}

int main()
{
    int T;
    cin >> T;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);

    vector<string> words(words_str, words_str + 10);

    for (int test = 1; test <= T; ++test) {
        vector<int> chars(250, 0);

        string s;
        cin >> s;

        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (int i = 0; i < s.size(); ++i) {
            chars[s[i]]++;
        }

        vector<pair<int, int>> phoneNumber;
        for (int i = 0; i < 10; ++i) {
            phoneNumber.push_back(make_pair(nums[i], getMax(i, chars, words)));
        }

        sort(phoneNumber.begin(), phoneNumber.end());

        cout << "Case #" << test << ": ";

        for (int i = 0; i < phoneNumber.size(); ++i) {
            for (int j = 0; j < phoneNumber[i].second; ++j) {
                cout << phoneNumber[i].first;
            }
        }
        cout << endl;
    }

    return 0;
}
