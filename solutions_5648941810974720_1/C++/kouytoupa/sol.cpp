#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const char *digit_to_str[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ks[10][2] = 
{
    //ZERO: Z TWO: W FOUR: U SIX: X EIGHT: G
    {'Z', 0}, {'W', 2}, {'U', 4}, {'X', 6}, {'G', 8},
    //ONE THREE FIVE SEVEN NINE
    //after ZERO TWO FOUR SIX EIGHT was removed, we know
    //ONE: O THREE: R FIVE: F SEVEN: S
    {'O', 1}, {'R', 3}, {'F', 5}, {'S', 7},
    //ONLY NINE, just check I or E
    {'I', 9}
};
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
    //1 100
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        cout << "Case #" << cas << ": ";
        string S;
        cin >> S;
        //n 3 2000
        int n = S.size();
        vector<int> cnt(256, 0);
        for(int i = 0; i < n; i++){
            cnt[S[i]] ++;
        }
        vector<int> res;
        for(int i = 0; i < 10; i++){
            char c = ks[i][0];
            int d = ks[i][1];
            const char *str = digit_to_str[d];
            for(int j = 0; j < cnt[c]; j++){
                res.push_back(d);
            }
            int str_len = strlen(str);
            for(int j = 0; j < str_len; j++){
                if(str[j] != c){
                    cnt[str[j]] -= cnt[c];
                }
            }
            cnt[c] = 0;
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}
