#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        int sh;
        string s;
        in >> sh >> s;
        int sum = 0, ans = 0;
        for(int i = 0; i <= sh; i++) {
            if(s[i] == '0')
                continue;
            if(sum < i) {
                ans += i - sum;
                sum = i;
            }
            sum += s[i] - '0';
        }
        out << "Case #" << tt + 1 << ": " << ans << '\n';
    }
    return 0;
}
