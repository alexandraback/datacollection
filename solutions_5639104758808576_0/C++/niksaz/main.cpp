#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int quests;
    cin >> quests;
    for (int q = 1; q <= quests; q++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            if (sum < i) {
                ans += i - sum;
                sum = i;
            }
            sum += s[i] - '0';
        }
        cout << "Case #" << q << ": " << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
