#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC = 1, T;
string str;

int main ()
{
    for (cin >> T; TC <= T; TC++) {
        getline(cin >> ws, str);
        int i = 0;
        int result = 0;
        bool encounter = false;
        while (i < str.length()) {
            if (str[i] == '+') {
                encounter = true;
                i++;
            } else {
                if (encounter) {
                    result += 2;
                } else {
                    result++;
                }
                while (i < str.length() && str[i] == '-') {
                    i++;
                }
            }
        }
        cout << "Case #" << TC << ": " << result << endl;
    }
    return 0;
}
