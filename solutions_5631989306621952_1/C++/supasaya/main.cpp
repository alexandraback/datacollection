#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC = 1, T;
string S;
int main ()
{
    for (cin >> T; TC <= T; TC++) {
        cin >> S;
        string str = "";
        for (int i = 0; i < S.length(); i++) {
            if (str.empty() || S[i]>=str[0]) {
                str = S[i]+str;
            } else {
                str = str+S[i];
            }
        }
        cout << "Case #" << TC << ": " <<str << endl;
    }
    return 0;
}
