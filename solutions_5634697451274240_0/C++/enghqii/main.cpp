#include <iostream>
#include <cstring>

using namespace std;

int main() {

    int count;
    cin >> count;

    cin.ignore();

    for (int i = 1; i <= count; i++) {

        string cakes;
        getline(cin, cakes);

        reverse(cakes.begin(), cakes.end());

        bool plusStart = cakes[0] == '+' ? true : false;
        char tmp = plusStart ? '+' : '-';
        int switchCount = plusStart ? 0 : 1;

        for (int j = 1; j < cakes.length(); j++) {
            if (cakes[j - 1] != cakes[j]) {
                switchCount += 1;
            }
        }

        cout << "Case #"<< i <<": " << switchCount << endl;

    }

    return 0;
}