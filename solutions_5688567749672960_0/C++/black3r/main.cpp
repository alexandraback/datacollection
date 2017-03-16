#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

unordered_map<ll, ll> memo;

ll flip(ll number) {
    if (number < 10) return number;
    else {
        ll result = 0;
        ll curr = number;
        while (curr != 0) {
            result *= 10;
            result += curr % 10;
            curr /= 10;
        }
        return result;
    }
}

int main()
{    
    queue<ll> process;
    process.push(1);
    memo[1] = 1;
    while(!process.empty()) {
        ll t = process.front();
        process.pop();
        if (t > 1000047) continue;

        ll f = flip(t);
        ll n = t + 1;
        if (memo.find(f) == memo.end()) {
            process.push(f);
            memo[f] = memo[t] + 1;
        }
        if (memo.find(n) == memo.end()) {
            process.push(n);
            memo[n] = memo[t] + 1;
        }
    }

    int T; cin >> T;
    for (int I = 1; I <= T; I++) {
        int result = 0;
        ll target; cin >> target;
        result = memo[target];
        cout << "Case #" << I << ": " << result << endl;
    }
    return 0;
}

