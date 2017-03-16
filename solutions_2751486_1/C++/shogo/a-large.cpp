#include <iostream>
#include <string>

using namespace std;

bool isvowel(char ch) {
    return ch=='a' || ch=='i' || ch=='u' || ch=='e' || ch=='o';
}

int main() {
    int T;
    cin >> T;
    for(int no = 1; no <= T; ++no) {
        string str;
        int n;
        cin >> str >> n;

        int count = 0;
        bool a = false;
        long long int ans = 0;
        int len = str.size();
        int delta = 0;
        for(int i=0;i<len;++i) {
            if(isvowel(str[i])) {
                ans+=delta;
                count = 0;
            } else {
                count++;
                if(count < n) {
                    ans+=delta;
                } else {
                    delta = i - n + 2;
                    ans += i - n + 2;
                }
            }
            //cout << i << ":" << ans << endl;
        }
        cout << "Case #" << no << ": " << ans << endl;
    }
}
