#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int match(int input, string pattern)
{   
    if (pattern.size() == 1)
        pattern = "00" + pattern;
    else if (pattern.size() == 2)
        pattern = "0" + pattern;

    string str = to_string(input);

    if (input < 10)
        str = "00" + str;
    else if (input < 100)
        str = "0" + str;
    //cout << str << " " << pattern << endl;

    for (int i = 0; i < str.size(); i++) {
        if (pattern[i] == '?' || str[i] == pattern[i])
            continue;
        return 0;
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int gap = INT_MAX, minc = INT_MAX, valj = INT_MAX;
        string C, J;
        int comp = 0; // C>J: -1, C==J: 0, C<J: 1
        cin >> C >> J;

        string newC, newJ;

        //cout << "C.size: " << C.size() << endl;

        for (int j = 0; j < pow(10, C.size()); j++) {
            if (!match(j, C)) continue;
            for (int k = 0; k < pow(10, C.size()); k++) {
                if (!match(k, J)) continue;
                 //cout << "k: " << k << " j: " << j << endl;

                int tmp_gap = abs(j-k);

                //cout << tmp_gap << " ";
                if (tmp_gap < gap) {
                    gap = tmp_gap; 
                    minc = j; 
                    valj = k;
                } else if (tmp_gap == gap && j < minc) {
                    minc = j;
                    valj = k;
                }
            }
        }

        cout << "Case #" << (i+1) << ": " << setw(C.size()) << setfill('0') << minc << " " << setw(C.size()) << setfill('0') << valj << endl;
    }
    return 0;
}