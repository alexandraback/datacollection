#include<iostream>
#include<string>


using namespace std;

int main() {
    long long T; cin >> T;
    for(int t=1; t<=T; t++) {
        string s;
        cin >> s;
        s.push_back('+');
        long long r = 0;
        for(int i = 1; i<s.size(); i++) {
            if(s[i] != s[i-1]) {
                r++;
            }
        }
        cout << "Case #" << t << ": " << r << "\n";
    }
}
