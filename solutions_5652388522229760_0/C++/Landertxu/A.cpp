#include <iostream>
#include <set>

using namespace std;

void addDigits (long long number, set<int>& digits){
    if (number == 0) return;
    digits.insert(number%10);
    addDigits(number/10, digits);
}

int solve(){
    int N;
    cin >> N;
    
    if (N == 0) return -1;
    
    set<int> digits;
    long long current = 0;
    while (digits.size() < 10){
        current += N;
        addDigits(current, digits);
    }
    return current;
}

int main(){
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        int ans = solve();
        if (ans == -1) cout << "INSOMNIA" << endl;
        else cout << ans << endl;
    }
}