#include <iostream>
#include <cstdio>
#include <vector>
#include <set>


using namespace std;


typedef long long LL;


void decomp(LL n, set < LL > &num) {
    if (n == 0) num.insert(10);
    for (; n > 0; ) {
        num.insert(n % 10);
        n /= 10;
    }
}


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        cout << "Case #" << q + 1 << ": ";
        set < LL > num;
        LL n;
        cin >> n;
        decomp(n, num);
        bool flag = false;
        
        LL dn = n;
        for (int i = 0; i < 1000; ++i) {            
            if (num.size() == 10) {
                cout << dn;
                flag = true;
                break;
            }
            dn += n;
            decomp(dn, num); 

        }
        if (!flag) {
            cout << "INSOMNIA";
        }
        cout << endl;
    }
    return 0;
}