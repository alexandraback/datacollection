#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    vector<string> str = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int order[] = {8, 3, 2, 4, 6, 0, 5, 1, 7, 9};
    char orderChar[] = {'G', 'H', 'T', 'U', 'X', 'Z', 'F', 'O', 'S', 'I'};
    int arr[10][26] = {0, };

    for (int i = 0; i < str.size(); i++)
        for (int j = 0; j < str[i].size(); j++)
            arr[i][str[i].at(j)-'A']++;

    for (int i = 0; i < T; i++) {
        string S;
        cin >> S;
        vector<int> r;

        int inarr[26] = {0, };

        for (int j = 0; j < S.size(); j++)
            inarr[S.at(j)-'A']++;

        for (int j = 0; j < 10; j++) {
            int check = orderChar[j]-'A';
            int count = inarr[check];

            if (count > 0) {
                for (int k = 0; k < count; k++)
                    r.push_back(order[j]);

                for (int k = 0; k < 26; k++)
                    inarr[k] -= (arr[order[j]][k] * count);
            }
        }

        sort(r.begin(), r.end());
        cout << "Case #" << (i + 1) << ": ";
        for (int j = 0; j < r.size(); j++)
            cout << r[j];
        cout << endl;
    }
    return 0;
}