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
        memset(num_count, 0, sizeof(num_count));
        memset(letter_count, 0, sizeof(letter_count));
        string s;
        cin >> s;
        for (char x : s) {
            letter_count[x - 65]++;
        }
        num_count[0] = letter_count['Z' - 65];
        letter_count['Z' - 65] -= num_count[0];
        letter_count['E' - 65] -= num_count[0];
        letter_count['R' - 65] -= num_count[0];
        letter_count['O' - 65] -= num_count[0];
        num_count[2] = letter_count['W' - 65];
        letter_count['T' - 65] -= num_count[2];
        letter_count['W' - 65] -= num_count[2];
        letter_count['O' - 65] -= num_count[2];
        num_count[4] = letter_count['U' - 65];
        letter_count['F' - 65] -= num_count[4];
        letter_count['O' - 65] -= num_count[4];
        letter_count['U' - 65] -= num_count[4];
        letter_count['R' - 65] -= num_count[4];
        num_count[3] = letter_count['R' - 65];
        letter_count['T' - 65] -= num_count[3];
        letter_count['H' - 65] -= num_count[3];
        letter_count['R' - 65] -= num_count[3];
        letter_count['E' - 65] -= num_count[3];
        letter_count['E' - 65] -= num_count[3];
        num_count[5] = letter_count['F' - 65];
        letter_count['F' - 65] -= num_count[5];
        letter_count['I' - 65] -= num_count[5];
        letter_count['V' - 65] -= num_count[5];
        letter_count['E' - 65] -= num_count[5];
        num_count[6] = letter_count['X' - 65];
        letter_count['S' - 65] -= num_count[6];
        letter_count['I' - 65] -= num_count[6];
        letter_count['X' - 65] -= num_count[6];
        num_count[7] = letter_count['V' - 65];
        letter_count['S' - 65] -= num_count[7];
        letter_count['E' - 65] -= num_count[7];
        letter_count['V' - 65] -= num_count[7];
        letter_count['E' - 65] -= num_count[7];
        letter_count['N' - 65] -= num_count[7];
        num_count[8] = letter_count['G' - 65];
        letter_count['E' - 65] -= num_count[8];
        letter_count['I' - 65] -= num_count[8];
        letter_count['G' - 65] -= num_count[8];
        letter_count['H' - 65] -= num_count[8];
        letter_count['T' - 65] -= num_count[8];
        num_count[9] = letter_count['I' - 65];
        letter_count['N' - 65] -= num_count[9];
        letter_count['I' - 65] -= num_count[9];
        letter_count['N' - 65] -= num_count[9];
        letter_count['E' - 65] -= num_count[9];
        num_count[1] = letter_count['O' - 65];
        letter_count['O' - 65] -= num_count[1];
        letter_count['N' - 65] -= num_count[1];
        letter_count['E' - 65] -= num_count[1];
        for (int digit = 0; digit < 10; digit++) {
            for (int j = 0; j < num_count[digit]; j++) {
                cout << digit;
            }
        }
        cout << endl;
    }
    return 0;
}
