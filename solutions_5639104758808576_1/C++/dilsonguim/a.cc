#include <iostream>
#include <string>

using namespace std;


int minFriends(const int s_max, const string s){
    int num_friends = 0;
    int num_standing = 0;
    for(int i = 0; i <= s_max; i++){
        const int si = s[i] - '0';
        if(i > num_standing){
            num_friends += i - num_standing;
            num_standing += si + i - num_standing;
        }else{
            num_standing += si;
        }

    }
    return num_friends;
}

int main(){
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        int s_max;
        string s;
        cin >> s_max >> s;
        const int sol = minFriends(s_max, s);
        cout << "Case #" << (tc + 1) << ": " << sol << "\n";
    }
}
