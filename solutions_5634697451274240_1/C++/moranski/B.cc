#include<string>
#include<iostream>

using namespace std;

long solve(string s){
    int l = s.length();
    int ret = 0;
    for(int i = 1; i < l; i++){
        if (s[i] != s[i-1]) ret++;
    }
    if (s[l-1] == '-') ret++;
    return ret;
}

main(void){
    int T;
    string s;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> s;
        cout << "Case #" << i << ": " << solve(s) << endl;
    }
}
