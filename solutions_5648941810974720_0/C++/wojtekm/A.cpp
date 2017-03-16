#include <iostream>
#include <string>

using namespace std;

string digits[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

int recognize(int num, char by, int howMany[]) {
    int res = howMany[by];
    for (int i = 0; i < digits[num].length(); i++)
        howMany[digits[num][i]] -= res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    
    for (int T = 1; T <= t; T++) {
        int howMany['Z'+1];
        for (int i = 'A'; i <= 'Z'; i++)
            howMany[i] = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            howMany[s[i]]++;
        
        int res[10];
        int nums[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        char by[] = {'Z', 'W', 'U', 'X', 'G', 'O', 'H', 'F', 'V', 'E'};
        for (int i = 0; i <= 9; i++)
            res[nums[i]] = recognize(nums[i], by[i], howMany);
            
            
        cout << "Case #" << T << ": ";
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j < res[i]; j++)
                cout << i;
        cout << "\n";
    }
    
    return 0;
}
