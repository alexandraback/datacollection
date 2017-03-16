#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int test;
    cin>>test;
    for (int k = 0; k < test; k++) {
        unsigned long long r,t ;
        cin>>r>>t;
        unsigned long i = 0;
        unsigned long long up = t;
        unsigned long long low = 1;
        unsigned long long value;
        unsigned long long result = 0;
        while (low <= up) {
            i = (low + up)/2;
            value = 2*i + (2*r - 1);
            unsigned long long x = t/i;
            if (value == x) {
                result = i;
                break;
            }
            if (value > x)
                up = i - 1;
            else {
                result = i;
                low = i + 1;
            }
        }
        cout << "Case #"<<k+1<<": "<<result<<endl;
    }
}
