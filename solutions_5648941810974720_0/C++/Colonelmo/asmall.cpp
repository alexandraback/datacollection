#include <bits/stdc++.h>

using namespace std;

string ans(string inp){
    map<char, int> mp;
    string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    for(auto it : inp){
        mp[it] ++ ;
    }
    char ids[] = {'Z', 'X', 'G', 'W', 'T', 'U', 'F', 'S', 'I', 'O'};
    int digs[] = {0, 6, 8, 2, 3, 4, 5, 7, 9, 1};
    string ret= "";
    for(int i = 0 ;i < 10 ; i++){
        char lookFor = ids[i];
        int digitToInsert = digs[i];
        int todo = mp[lookFor];
        for(int j = 0 ;j < todo ; j++){
            ret += digitToInsert + '0';
        }
        for(int j = 0; j < todo ; j++){
            for(auto it : nums[digitToInsert]){
                mp[it] --;
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    int t;
    cin >> t;
    for(int tt = 1 ; tt <= t ; tt++){
        cout << "Case #" << tt << ": ";
        string str;
        cin >> str;
        cout << ans(str) << endl;
    }
    return 0;
}
