#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    ifstream cin("A-small-attempt0.in");
    ofstream cout("output.txt");
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; caso++) {
        string S;
        cin >> S;
        vector<int> times(100, 0);
        for (int i = 0; i < (int) S.length(); i++)
            times[S[i]]++;
        vector<int> numbers(10, 0);
        // Zeroes
        numbers[0] = times['Z'];
        times['E'] -= times['Z'];
        times['R'] -= times['Z'];
        times['O'] -= times['Z'];
        // Twos
        numbers[2] = times['W'];
        times['T'] -= times['W'];
        times['O'] -= times['W'];
        // Six
        numbers[6] = times['X'];
        times['S'] -= times['X'];
        times['I'] -= times['X'];
        // Seven
        numbers[7] = times['S'];
        times['E'] -= times['S'];
        times['V'] -= times['S'];
        times['E'] -= times['S'];
        times['N'] -= times['S'];
        // Five
        numbers[5] = times['V'];
        times['F'] -= times['V'];
        times['I'] -= times['V'];
        times['E'] -= times['V'];
        // Four
        numbers[4] = times['F'];
        times['O'] -= times['F'];
        times['U'] -= times['F'];
        times['R'] -= times['F'];
        // Three
        numbers[3] = times['R'];
        times['T'] -= times['R'];
        times['H'] -= times['R'];
        times['E'] -= times['R'];
        times['E'] -= times['R'];
        // Eight
        numbers[8] = times['G'];
        times['E'] -= times['G'];
        times['I'] -= times['G'];
        times['H'] -= times['G'];
        times['T'] -= times['G'];
        // Nine
        numbers[9] = times['I'];
        times['N'] -= times['I'];
        times['N'] -= times['I'];
        times['E'] -= times['I'];
        // One
        numbers[1] = times['O'];
        // Build the number
        string ans;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < numbers[i]; j++)
                ans.push_back(i+'0');
        cout << "Case #" << caso << ": " << ans << endl;
    }
    return 0;
}
