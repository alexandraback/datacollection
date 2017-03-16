#include<bits/stdc++.h>
#define int long long
using namespace std;

bool x[10];

main() {

    int t;
    cin>>t;
    for (int test = 1; test<=t; test++) {
        for (int i=0; i<10; i++) x[i] = 0;
        int n;
        cin>>n;
        cout<<"Case #"<<test<<": ";
        if (n==0) cout<<"INSOMNIA"<<endl;
        else {
            for (int i=1; ;i++) {
                int tmp = i * n;
                while (tmp) {
                    x[tmp%10] = 1;
                    tmp /= 10;
                }
                bool print = 1;
                for (int j=0; j<10; j++) {
                    if (x[j] == 0) {
                        print = 0;
                        break;
                    }
                }
                if (print) {
                    cout<<i*n<<endl;
                    break;
                }
            }
        }
    }
}
