#include <bits/stdc++.h>
using namespace std;

set<int> seen;

void trackDigits(long long num){
    while(num > 0){
        seen.insert(num%10);
        num /= 10;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        seen.clear();
        long long num;
        
        cin >> num;
        long long orig = num;
        if(num == 0){
            cout << "Case #" << i << ": INSOMNIA\n";
            continue;
        }
        trackDigits(num);
        while(seen.size() != 10){
            num += orig;
            trackDigits(num);
        }
        cout << "Case #" << i << ": " << num << endl;
    }
}
