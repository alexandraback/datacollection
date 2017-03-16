#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {
    long long T; cin >> T;
    for(int t = 1; t<=T; t++) {
        long long n; cin >> n;
        set<long long> s;
        long long res = 0;
        for(long long i = 1; i<100000; i++) {
            long long x = n*i;
            while(x) {
                s.insert(x%10);
                x/=10;
            }
            if(s.size() == 10) {
                res = n*i;
                break;
            }
        }
        
        cout << "Case #" << t << ": ";
        if(res)
            cout << res;
        else
            cout << "INSOMNIA";
        cout << "\n";
    }
}
