#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll in10(int n) {
    ll ans = 1;
    for (int i = 0; i < n; i++) ans *= 10;
    return ans;
}

ll rotateN(ll n, int digNum) {
    ll ans = 0;
    int i = 0;
    while (n) {
        ans += (n % 10) * in10(digNum - 1 - i);
        i++;
        n /= 10;
    }
    return ans;
}

ll solve(ll n) {
    if (n <= 10) return n;
    vector<int> num;
    int digCount = 0;
    ll copyN = n;
    while (copyN)
        digCount++, num.push_back(copyN % 10), copyN /= 10;
    ll answer = 0;
    for (int i = 1; i < digCount; i++) {
        if (i > 1)
            answer += in10(i / 2) - 1;
        if (i > 1)
            answer++;
        if (i % 2 == 1)
            answer += in10(i / 2 + 1);
        else
            answer += in10(i / 2);
        if (i > 1)
            answer--;
    }
    if (in10(digCount - 1) == n) return answer;
    if (rotateN(n, digCount) % in10(digCount / 2) == 1) {
        return answer + n - in10(digCount - 1);
    }
    int toAdd = 0;
    
    if (n % in10(digCount / 2) == 0) {
        toAdd = 1;
        n--;
        num.clear();
        copyN = n;
        while (copyN)
            num.push_back(copyN % 10), copyN /= 10;
    }
    if (rotateN(n, digCount) % in10(digCount / 2) == 1) {
        return answer + n - in10(digCount - 1) + toAdd;
    }
    int left = digCount - digCount / 2;
    int leftNumber = 0;
    for (int i = 0; i < left; i++)
        leftNumber *= 10, leftNumber += num[digCount - 1 - i];
    answer += rotateN(leftNumber, left);
    answer ++;
    answer += (n % in10(digCount / 2)) - 1;
    
    return answer + toAdd;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    int i = 1;
    while (t--) {
        ll tmp;
        cin >> tmp;
        cout << "Case #" << i << ": " << solve(tmp) << endl;
        i++;
    }
}
