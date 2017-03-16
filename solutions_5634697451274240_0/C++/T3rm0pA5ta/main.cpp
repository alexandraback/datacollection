#include <iostream>
#include <string>
using namespace std;

int main()
{

    int T;
    cin >> T;
    string s;
    for (int i = 0; i < T; i++) {
        cin >> s;
        
        char prev = s.back();
        int blocks_num = (prev == '-' ? 1 : 0);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (prev != s[i]) {
                blocks_num++;
                prev = s[i];
            }
        }

        cout << "case #" << i + 1 << ": " << blocks_num << "\n";

    }
    return 0;
}
