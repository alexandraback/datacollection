#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int t;
    cin>>t;
    for (int k = 0; k < t; k++) {
        unsigned long long r;
        cin>>r>>t;
        unsigned long long result = 0;
        unsigned long i;
        for (i = 0; i < t; i++)
            if (2*i*i + (2*r - 1)*i > t)
                break;
        cout << "Case #"<<k+1<<": "<<i-1<<endl;
    }
}
