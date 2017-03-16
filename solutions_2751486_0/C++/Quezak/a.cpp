#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

long long compute();

int main()
{
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i)
        cout << "Case #" << i + 1 << ": " << compute() << "\n";
    return 0;
}

char word[1000100];
int cons_aft[1000100];

bool is_vowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

long long compute()
{
    int n;
    vector<int> good_pos;
    cin >> word >> n;
    int len = strlen(word);
    cons_aft[len] = 0;
    for (int i = len-1; i >= 0; --i) {
        if (is_vowel(word[i]))
            cons_aft[i] = 0;
        else
            cons_aft[i] = cons_aft[i+1] + 1;

        if (cons_aft[i] >= n) {
            good_pos.push_back(i);
        }
//         cout << i << " " << cons_aft[i] << "\n";
    }

//     cout << "GOOD_POS:\n";
//     for (int i = 0; i < good_pos.size(); ++i) {
//         cout << i << " " << good_pos[i] << "\n";
//     }

    if (good_pos.empty())
        return 0;
    long long res = 0;
    for (int i = 0; i < len; ++i) {
        if (good_pos.back() < i)
            good_pos.pop_back();
        if (good_pos.empty())
            break;

        res += (len - good_pos.back() - n + 1);

//         cout << "i:" << i << " res (" << res << ") good_pos:\n";
//         for (int i = 0; i < good_pos.size(); ++i) {
//             cout << i << " " << good_pos[i] << "\n";
//         }
    }

//     if (res < 0) {
//         cout << "oops: [" << len << "]: " << word << "\n";
//     }
    return res;
}
