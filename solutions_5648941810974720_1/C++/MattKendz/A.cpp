#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<char> curr, answer;
        for (int j = 0; j < s.length(); j++)
            curr.push_back(s[j]);

        while (find(curr.begin(), curr.end(), 'Z') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'Z'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            curr.erase(find(curr.begin(), curr.end(), 'R'));
            curr.erase(find(curr.begin(), curr.end(), 'O'));
            answer.push_back('0');
        }

        while (find(curr.begin(), curr.end(), 'W') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'T'));
            curr.erase(find(curr.begin(), curr.end(), 'W'));
            curr.erase(find(curr.begin(), curr.end(), 'O'));
            answer.push_back('2');
        }

        while (find(curr.begin(), curr.end(), 'U') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'F'));
            curr.erase(find(curr.begin(), curr.end(), 'O'));
            curr.erase(find(curr.begin(), curr.end(), 'U'));
            curr.erase(find(curr.begin(), curr.end(), 'R'));
            answer.push_back('4');
        }

        while (find(curr.begin(), curr.end(), 'F') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'F'));
            curr.erase(find(curr.begin(), curr.end(), 'I'));
            curr.erase(find(curr.begin(), curr.end(), 'V'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            answer.push_back('5');
        }

        while (find(curr.begin(), curr.end(), 'X') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'S'));
            curr.erase(find(curr.begin(), curr.end(), 'I'));
            curr.erase(find(curr.begin(), curr.end(), 'X'));
            answer.push_back('6');
        }

        while (find(curr.begin(), curr.end(), 'V') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'S'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            curr.erase(find(curr.begin(), curr.end(), 'V'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            curr.erase(find(curr.begin(), curr.end(), 'N'));
            answer.push_back('7');
        }

        while (find(curr.begin(), curr.end(), 'G') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            curr.erase(find(curr.begin(), curr.end(), 'I'));
            curr.erase(find(curr.begin(), curr.end(), 'G'));
            curr.erase(find(curr.begin(), curr.end(), 'H'));
            curr.erase(find(curr.begin(), curr.end(), 'T'));
            answer.push_back('8');
        }

        while (find(curr.begin(), curr.end(), 'O') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'O'));
            curr.erase(find(curr.begin(), curr.end(), 'N'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            answer.push_back('1');
        }

        while (find(curr.begin(), curr.end(), 'R') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'T'));
            curr.erase(find(curr.begin(), curr.end(), 'H'));
            curr.erase(find(curr.begin(), curr.end(), 'R'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            answer.push_back('3');
        }

        while (find(curr.begin(), curr.end(), 'N') != curr.end()) {
            curr.erase(find(curr.begin(), curr.end(), 'N'));
            curr.erase(find(curr.begin(), curr.end(), 'I'));
            curr.erase(find(curr.begin(), curr.end(), 'N'));
            curr.erase(find(curr.begin(), curr.end(), 'E'));
            answer.push_back('9');
        }

        sort(answer.begin(), answer.end());
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < answer.size(); j++)
            cout << answer[j];
        cout << endl;
    }

    return 0;
}