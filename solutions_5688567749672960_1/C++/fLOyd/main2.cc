#include <iostream>

using namespace std;

long long n;
string s ;
long long ans;

long long solve(long long n, string s) {
    if (n <= 20) return n;
    if (n < 100) return 10 + n / 10 + n % 10;
    ans = 11;
    for (int i = 2; i < s.size(); ++i) {
        long long ten = 1;
        for (int j = 0; j < i / 2; ++j) {
            ten *= 10;
        }
        ans += ten - 1; // ten - 1 - 1 + 1
        if (i % 2 == 1) {
            ten *= 10;
        }
        ans += ten; // ten - 2 + 2;
    }

    string s1 = s.substr(0, s.size() / 2);
    string s2 = s.substr(s.size() / 2, s.size() - s.size() / 2);
    reverse(s1.begin(), s1.end());

    if (stoll(s1) != 1) {
        ans += stoll(s1) + stoll(s2) - 1;
    } else {
        ans += stoll(s2) - 1;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int casesNum;
    long long delta;
    cin >> casesNum;
    for (int caseId = 1;  caseId <= casesNum; ++caseId) {
        cin >> n;
        if (n % 10 == 0) {
            delta = 1;
            n = n - 1;
        } else {
            delta = 0;
        }

        s = to_string(n);
        long long ans1 = solve(n,s);

        reverse(s.begin(), s.end());
        n = stoll(s);
        long long ans2 = solve(n,s);

        cout << "Case #" << caseId << ": " << min(ans1, ans2 + 1) + delta << endl;
    }
    return 0;
}
