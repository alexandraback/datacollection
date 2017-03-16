#include <iostream>
#include <string>
using namespace std;

bool is_consonant(char ch) {
    return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
}

string str;

int main()
{
    int tot_case;
    cin >> tot_case;
    for (int test_case = 1; test_case <= tot_case; test_case++) {
        int n;
        cin >> str >> n;


        int len = str.length(), consonant = 0, left = -1;
        long ans = 0;
        for (int i = 0; i < len; i++) {
            if (is_consonant(str[i])) {
                consonant++;
            } else {
                consonant = 0;
            }

            if (n == 0) {
                left = i;
            } else if (consonant >= n) {
                left = i - n + 1;
            }

            if (left >= 0) {
                ans += left + 1;
            }
        }
        
        cout << "Case #" << test_case << ": "<< ans << endl;
    }
}
