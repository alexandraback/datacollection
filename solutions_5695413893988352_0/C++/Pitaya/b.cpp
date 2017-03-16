#include <iostream>
#include <cstring>

using namespace std;

int num_count[10];
int letter_count[26];

int main() 
{
    int case_num;
    int n;
    cin >> case_num;
    for (int case_id = 0; case_id < case_num; case_id++)
    {
        cout << "Case #" << case_id + 1 << ": ";
        string s1, s2;
        int leading = 0;
        cin >> s1 >> s2;
        // cout << s1 << 'a' << s2 << 'a' << endl;
        for (size_t i = 0; i < s1.length(); i++) {
            if (leading == 0) {
                if (s1[i] != '?' && s2[i] != '?') { 
                    if (s1[i] > s2[i]) {
                        leading = 1;
                    }
                    if (s1[i] < s2[i]) {
                        leading = 2;
                    }
                    continue;
                }
                if (s1[i] == '?' && s2[i] == '?') {
                    s1[i] = s2[i] = '0';
                    continue;
                }
                if (s1[i] == '?') {
                    s1[i] = s2[i];
                }
                if (s2[i] == '?') {
                    s2[i] = s1[i];
                }
            } else {
                if (leading == 1) {
                    if (s1[i] == '?') {
                        s1[i] = '0';
                    }
                    if (s2[i] == '?') {
                        s2[i] = '9';
                    }
                } else {
                    if (s1[i] == '?') {
                        // cout << leading << endl;
                        s1[i] = '9';
                    }
                    if (s2[i] == '?') {
                        s2[i] = '0';
                    }
                }

            }
        }
        cout << s1 << ' ' << s2 << endl;
    }
    return 0;
}
