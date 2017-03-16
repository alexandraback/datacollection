#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

uint64_t reverse(uint64_t i) {
    uint64_t res = 0;
    while(i > 0) {
        res *= 10;
        res += (i%10);
        i /= 10;
    }
    return res;
}

bool isPalindrome(uint64_t i) {
    return reverse(i) == i;
}

int main() {
    vector<uint64_t> palis = vector<uint64_t>();
    uint64_t sq;
    for(uint64_t i = 1; i < 10000001;i++) {
        sq = i*i;
        if(isPalindrome(i) && isPalindrome(sq)) {
            //cout << sq << endl;
            palis.push_back(sq);
        }
    }


    freopen("clarge.in", "r", stdin);
    freopen("clarge.out", "w", stdout);

    int T;
    cin >> T;
    for(int cse = 1; cse <= T; cse++) {
        cout << "Case #" << cse << ": ";
        uint64_t A, B, count = 0;
        cin >> A >> B;
        vector<uint64_t>::iterator it = lower_bound(palis.begin(), palis.end(), A);
        vector<uint64_t>::iterator iu = lower_bound(palis.begin(), palis.end(), B);
        count += int(iu-it);
        if(*iu == B)
            count++;
        cout << count << endl;
    }
    return 0;
}
