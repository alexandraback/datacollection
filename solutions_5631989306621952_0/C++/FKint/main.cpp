#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int get_heighest_char(string s, int len){
    char heighest_char = 0;
    int heighest_index = 0;
    for(int i = 0; i < len; ++i){
        if(s[i] >= heighest_char){
            heighest_char = s[i];
            heighest_index = i;
        }
    }
    return heighest_index;
}

int main(){
	std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int current_case_nb = 1; current_case_nb <= T; ++current_case_nb){
        string s;
        cin >> s;
        int current_end = s.length();
        string res = "";
        vector<bool> positioning_left(s.length(), false);
        while(current_end > 0){
            int heighest_char = get_heighest_char(s, current_end);
            positioning_left[heighest_char] = true;
            current_end = heighest_char;
        }
        cout << "Case #" << current_case_nb << ": ";
        for(int i = 0; i < s.length(); ++i){
            if(positioning_left[i]){
                res = s[i] + res;
            }else{
                res = res + s[i];
            }
        }
        cout << res;
        cout << endl;
    }
    return 0;
}
