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

        int ans = 0;
        int len = str.size();
        for(int i=0;i<len;++i) {
            int count = 0;
            bool a = false;
            for(int j=i; j<len; ++j) {
                if(!isvowel(str[j])) count++;
                else count = 0;
                if(a || count>=n) {
                    ans++;
                    a = true;
                }
            }
        }
        cout << "Case #" << no << ": " << ans << endl;
    }
}
