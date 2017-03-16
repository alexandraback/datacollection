#include <iostream>
#include <vector>

using namespace std;

void digs(int64_t n, vector<bool>& digits, int64_t& digcnt){
    int dig;
    while(n!= 0){
        dig = n % 10;
        if(!digits[dig]){
            digits[dig] = true;
            digcnt++;
        }
        n = n / 10;
    }
    return;
}

int main()
{
    int cases,cnt = 0;
    cin >> cases;
    while(cases--){
        cnt++;
        vector<bool> digits (10,false);
        int64_t digcnt = 0, n, realn;
        cin >> n;
        if(n == 0){
            cout << "Case #" << cnt << ": INSOMNIA" << endl;
            continue;
        } else {
            realn = n;
            digs(n,digits,digcnt);
            while(digcnt < 10){
                n += realn;
                digs(n,digits,digcnt);
            }
            cout << "Case #" << cnt << ": " << n << endl;
        }

    }
    return 0;
}
